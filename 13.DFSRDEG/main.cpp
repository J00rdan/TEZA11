#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");
ofstream fout("output.dat");

int M[100][100];
int n;
int k;
int VIZ[100];
int top;
int ST[100];

void read_data(){
    fin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) fin >> M[i][j];
    fin >> k;
}

int isEmpty(int ST[], int top){
    return top == 0;
}

int push(int ST[], int *top, int value){
    *top = *top + 1;
    ST[*top] = value;
    return 0;
}

int pop(int ST[], int *top){
    int old = ST[*top];
    (*top) = (*top) - 1;
    return old;
}

int DFS_REC(int ST[], int *top, int node){
    if(!isEmpty(ST, *top)){
        int old = pop(ST, top);
        cout << old << " ";
        VIZ[old] = 1;
        for(int i = 1; i <= n; i++){
            if(M[old][i] == 1 && VIZ[i] == 0){
                push(ST, top, i);
                DFS_REC(ST, top, i);
            }
        }
        return 0;
    }
}

int main()
{
    read_data();
    push(ST, &top, k);
    DFS_REC(ST, &top, k);
    return 0;
}
