#include <iostream>
using namespace std;

class element
{
    private:
        int value;
        element *prev;
        element *next;

    public:

        element(){
            value = 0;
            next = NULL;
            prev = NULL;
        }

        int getvalue(){
            return value;
        }

        int setvalue(int thisvalue){
            value = thisvalue;
            return 0;
        }

        element* getprev(){
            return prev;
        }

        int setprev(element *thisvalue){
            prev = thisvalue;
            return 0;
        }

        element* getnext(){
            return next;
        }

        int setnext(element *thisvalue){
            next = thisvalue;
            return 0;
        }
};

class Lista
{
    private:
        element *start;
        element *curent;
        element *sfarsit;
        int counter;

    public:

        Lista(){
            start = NULL;
            curent = NULL;
            sfarsit = NULL;
            counter = 0;
        }

        int isEmpty(){
            return counter == 0;
        }

        void printLR(){
            element *saved = curent;

            curent = start;
            while(curent != NULL){
                cout << curent->getvalue() << " ";
                curent = curent->getnext();
            }
            cout << endl;
            curent = saved;
        }

        void printRL(){
            element *saved = curent;

            curent = sfarsit;
            while(curent != NULL){
                cout << curent->getvalue() << " ";
                curent = curent->getprev();
            }
            cout << endl;
            curent = saved;
        }

        void addq(int value, int *err){
            *err = 0;
            if (isEmpty()){
                element *newone = new element();
                newone->setvalue(value);
                start = newone;
                curent = newone;
                sfarsit = newone;
                counter ++;
            }
            else {
                element *newone = new element;
                newone->setvalue(value);
                newone->setprev(sfarsit);
                sfarsit->setnext(newone);
                sfarsit = newone;
                curent = newone;
                counter++;
            }
        }

        void serveq(int *old, int *err){
            *err = 0;
            if(isEmpty()) *err = 1;
            else if(counter == 1){
                *old = sfarsit->getvalue();
                start = NULL;
                sfarsit = NULL;
                curent = NULL;
                counter = 0;
            }
            else {
                *old = start->getvalue();
                element * fork = start;
                start = start->getnext();
                start->setprev(NULL);
                counter --;
                delete fork;
            }
        }

};

int main(){
    Lista *L = new Lista();

    int error, old;

    for(int i = 1; i <= 10; i++) L->addq(i, &error);

    L->printLR();
    L->printRL();

    for(int i = 1; i <= 11; i++){
        L->serveq(&old, &error);
        cout << endl << old << " " << error <<  endl;
        L->printLR();
        L->printRL();
    }

    for(int i = 1; i <= 10; i++) L->addq(i, &error);

    L->printLR();
    L->printRL();
    return 0;
}
