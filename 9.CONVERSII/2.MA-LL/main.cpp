#include <iostream>
#include <fstream>
using namespace std;

int M[100][100] = {
    {1, 1, 0, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 1, 1},
    {1, 1, 0, 1, 1}
};
int n = 5;
int L[100][100];

int main()
{
    cout << n << endl << n +  1 << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(M[i][j] == 1 & i != j){
                L[i][0] ++;
                L[i][L[i][0]] = j + 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << L[i][j] << " ";
        cout << endl;
    }
}
