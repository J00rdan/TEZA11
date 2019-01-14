#include <iostream>
using namespace std;

int L[100][100] = {
    {2, 2, 5, 0, 0},
    {3, 1, 3, 5, 0},
    {2, 2, 4, 0, 0},
    {2, 3, 5, 0, 0},
    {3, 1, 2, 4, 0}
};

int m = 6;
int n = 5;
int M[100][100];

int main()
{
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= L[i][0]; j++){
            M[i + 1][L[i][j]] = 1;
        }
        M[i + 1][i + 1] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    return 0;
}
