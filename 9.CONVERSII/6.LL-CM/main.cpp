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
int C[100][2];
int k;

int main()
{
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= L[i][0]; j++){
            if(i + 1 < L[i][j]){
                C[++k][1] = i + 1;
                C[k][2] = L[i][j];
            }
        }
    }

    for(int i = 1; i <= k; i++) cout << C[i][1] << " " << C[i][2] << endl;
    return 0;
}
