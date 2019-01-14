#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("data.in");
ofstream fout("data.out");

int M[100][100] = {
    {1, 1, 0, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 1, 1},
    {1, 1, 0, 1, 1}
};
int n = 5;
int m;
int C[100][100];
int k;

int main()
{
    m = n + 1;
    cout << n << endl << m << endl;

    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++){
            if(M[i][j] == 1 && i != j) C[++k][1] = i + 1, C[k][2] = j + 1;
        }
    for(int i = 1; i <= m; i++) cout << C[i][1] << " " << C[i][2] << endl;

    return 0;
}
