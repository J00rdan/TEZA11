#include <iostream>
#include <stdlib.h>
using namespace std;

int n;
int V[100];
int s;

int main(int argc, char *argv[])
{
    cout << argc << endl;
    n = atoi(argv[1]);
    for(int i = 1; i <= n; i++){
        V[i] = atoi(argv[i + 1]);
    }

    for(int i = 1; i <= n; i++) s += V[i];
    cout << s;
    return 0;
}
