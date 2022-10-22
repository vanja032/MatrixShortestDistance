#include <iostream>
using namespace std;
int horizontalDistance(int m, int n, int x, int y, int distance, int** hpos, int** vpos);
int verticalDistance(int m, int n, int x, int y, int distance, int** hpos, int** vpos) {
    int d1 = -1, d2 = -1;
    if (x == n-1 && y == m-1)
        return distance;
    if (vpos[y][x] == 1)
        return -1;
    vpos[y][x] = 1;
    if (y > 0)
        d1 = horizontalDistance(m, n, x, y - 1, distance + 1, hpos, vpos);
    if (y < m - 1)
        d2 = horizontalDistance(m, n, x, y + 1, distance + 1, hpos, vpos);
    if (d1 != -1 && d2 != -1)
        return (d1 < d2) ? d1 : d2;
    else
        return (d1 > d2) ? d1 : d2;
}
int horizontalDistance(int m, int n, int x, int y, int distance, int** hpos, int** vpos) {
    int d1 = -1, d2 = -1;
    if (x == n-1 && y == m-1)
        return distance;
    if (hpos[y][x] == 1)
        return -1;
    hpos[y][x] = 1;
    if (x > 0)
        d1 = verticalDistance(m, n, x - 1, y, distance + 1, hpos, vpos);
    if (x < n - 1)
        d2 = verticalDistance(m, n, x + 1, y, distance + 1, hpos, vpos);
    if (d1 != -1 && d2 != -1)
        return (d1 < d2) ? d1 : d2;
    else
        return (d1 > d2) ? d1 : d2;
}
int distance(int m, int n, int** hpos, int** vpos) {
    int d1 = verticalDistance(m, n, 0, 0, 0, hpos, vpos);
    int d2 = horizontalDistance(m, n, 0, 0, 0, hpos, vpos);
    if(d1 != -1 && d2 != -1)
        return (d1 < d2) ? d1 : d2;
    else
        return (d1 > d2) ? d1 : d2;
}
int main()
{
    int m, n;
    cout << "Unesi M: ";
    cin >> m;
    cout << "Unesi N: ";
    cin >> n;
    int** hpos = new int* [m];
    int** vpos = new int* [m];
    for (int i = 0; i < m; i++) {
        hpos[i] = new int[n];
        vpos[i] = new int[n];
    }
    cout << "Distance: " << distance(m, n, hpos, vpos);
    for (int i = 0; i < m; i++) {
        delete(hpos[i]);
        delete(vpos[i]);
    } 
    delete(*hpos);
    delete(*vpos);
}