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
int M[100][100];

int main()
{
    for(int i = 0; i <= n; i++){
        M[C[i][0]][C[i][1]] = 1;
        M[C[i][1]][C[i][0]] = 1;
        M[i + 1][i + 1] = 1;
    }
    cout << n << endl << m << endl;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << M[i][j] << " ";
        cout << endl;
    }

    return 0;
}
