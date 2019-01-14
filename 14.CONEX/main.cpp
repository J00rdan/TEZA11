#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

int M[100][100];
int VIZ[100];
int ST[100];
int n;
int start;
int top;

void read_data(){
    fin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) fin >> M[i][j];
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

int conex(int VIZ[]){
    for(int i = 1; i <= n; i ++)
        if(VIZ[i] == 0) return 0;
    return 1;
}

int main()
{
    read_data();
    push(ST, &top, 2);
    DFS_REC(ST, &top, 2);

    if(conex(VIZ) == 1){
        cout << endl << "Graful este conex";
    }
    else cout << endl << "Graful nu este conex";

    return 0;
}
