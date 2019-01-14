#include <iostream>
#include  <fstream>
using namespace std;

ifstream fin("input.dat");

int G[100][100];
int n;
int k;
int top;
int VIZ[100];
int S[100];

void read_data(){
    fin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) fin >> G[i][j];
    fin >> k;
}

void init_data(){
    for(int i = 1; i <= n; i++) VIZ[i] = 0;
}

int init(int S[], int top){
    S[top] = 0;
    return 1;
}

int succesor(int S[], int top){
    if(top <= n){
        for(int i = 1; i <= n; i++){
            if(G[S[top - 1]][i] == 1 && VIZ[i] == 0){
                S[top] = i;
                return 1;
            }
        }
    }
    return 0;
}

int valid(int S[], int top){
    return 1;
}

int solutie(int S[], int top){
    return 1;
}

int tipar(int S[], int *top){
    cout << S[*top] << " ";
    VIZ[S[*top]] = 1;
    *top = (*top) + 1;
    init(S, *top);

    return 1;
}

void DFS_BKTR(int nod){
    top = 1;
    S[top] = nod;

    VIZ[nod] = 1;

    top ++;

    cout << nod << " ";
    while(top >= 1){
        int am, este;
        do{
            am = succesor(S, top);
            este = valid(S, top);
        } while(!((am && este)||(!am)));
        if(am){
            if(solutie(S, top)){
                tipar(S, &top);
            }
            else {
                init(S, top + 1);
                top ++;
            }
        }
        else top --;
    }
}

int main()
{
    read_data();
    init_data();
    DFS_BKTR(k);
    return 0;
}
