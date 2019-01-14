#include <iostream>
using namespace std;

typedef void (*pointer)(int V[], int n);

void sort_data(int V[], int n){
    int isSorted = 0;
    do{
        isSorted = 1;
        for(int i = 0; i < n - 1; i++){
            if(V[i] > V[i + 1]){
                isSorted = 0;
                swap(V[i], V[i + 1]);
            }
        }
    }while(!isSorted);
}

void print_data(int V[], int n){
    for(int i = 0; i < n; i++) cout << V[i] << " ";
    cout << endl;
}

pointer funct;

int givemetools(pointer method, int V[], int n){
    method(V, n);
    return 0;
}

int main()
{
    int X[3] = {1, 2, 3};
    int V[3] = {3, 1, 2};

    funct = &print_data;
    givemetools(funct, X, 3);

    funct = &print_data;
    givemetools(funct, V, 3);

    funct = &sort_data;
    givemetools(funct, V, 3);

    funct = &print_data;
    givemetools(funct, V, 3);

    return 0;
}
