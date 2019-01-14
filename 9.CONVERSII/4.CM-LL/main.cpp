#include <iostream>
#include <fstream>
using namespace std;

int n = 5;
int m = 6;
int C[7][2] = {
    {1, 2},
    {1, 5},
    {2, 3},
    {2, 5},
    {3, 4},
    {4, 5},
};
int L[100][100];

int main()
{
    for(int i = 0; i < m; i++){
        int x = C[i][0];
        int y = C[i][1];
        L[x][1] ++;
        L[y][1] ++;

        L[x][L[x][1] + 1] = y;
        L[y][L[y][1] + 1] = x;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << L[i][j] << " ";
        cout << endl;
    }
    return 0;
}
