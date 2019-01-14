#include <iostream>
using namespace std;

class element
{
    private:
        int value;
        element *next;

    public:
        element(){
            value = 0;
            next = NULL;
        }

        int getvalue(){
            return value;
        }

        int setvalue(int thisvalue){
            value = thisvalue;
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
        }

        int isEmpty(){
            return counter == 0;
        }

        void print(){
            curent = start;
            while(curent != NULL){
                cout << curent->getvalue() << " ";
                curent = curent->getnext();
            }
        }

        void addq(int value, int *err){
            *err = 0;
            if (isEmpty()){
                element *newone = new element;
                newone->setvalue(value);
                start = newone;
                curent = newone;
                sfarsit = newone;
                counter ++;
            }
            else{
                element *newone = new element;
                newone->setvalue(value);
                sfarsit->setnext(newone);
                sfarsit = newone;
                curent = newone;
                counter ++;
            }
        }

        void serveq(int *old, int *err){
            *err = 0;
            if(isEmpty()) *err = 1;
            else if (counter == 1){
                *old = start->getvalue();
                counter = 0;
                start = NULL;
                sfarsit = NULL;
                curent = NULL;
            }
            else {
                *old = start->getvalue();
                element *fork = start;
                start = start->getnext();
                counter --;
                delete fork;
            }
        }

};

int main(){
    Lista *L = new Lista();

    int error, old;

    for(int i = 1; i <= 10; i++) L->addq(i, &error);

    L->print();

    for(int i = 1; i <= 11; i++){
        L->serveq(&old, &error);
        cout << endl << old << " " << error <<  endl;
        L->print();
    }
    return 0;
}
