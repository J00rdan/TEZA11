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

        int add_left(int thisone){
            if(isEmpty()){
                element *newone = new element;
                newone->setvalue(thisone);
                curent = newone;
                start = newone;
                sfarsit = newone;
                counter++;
            }
            else if(start == curent){
                element *newone = new element;
                newone->setvalue(thisone);
                start->setprev(newone);
                newone->setnext(start);
                start = newone;
                curent = newone;
                counter++;

            }
            else {
                element *newone = new element;
                newone->setvalue(thisone);
                newone->setnext(curent);
                newone->setprev(curent->getprev());

                curent->getprev()->setnext(newone);
                curent->setprev(newone);

                curent = newone;
                counter ++;
            }
            return 0;
        }

        int add_right(int thisone){
            if(isEmpty()){
                element *newone = new element;
                newone->setvalue(thisone);
                curent = newone;
                start = newone;
                sfarsit = newone;
                counter++;
            }
            else if(sfarsit == curent){
                element *newone = new element;
                newone->setvalue(thisone);
                newone->setprev(sfarsit);
                newone->setnext(NULL);
                sfarsit->setnext(newone);
                sfarsit = newone;
                curent = newone;
                counter++;

            }
            else {
                element *newone = new element;
                newone->setvalue(thisone);
                newone->setnext(curent->getnext());

                curent->getnext()->setprev(newone);

                curent->setnext(newone);
                newone->setprev(curent);
                curent = newone;
                counter ++;
            }
            return 0;
        }

        element* getcurent(){
            return curent;
        }

        void deletee(int *old, int *err, int direction){
            *err = 0;
            if(direction == 1){
                if(counter == 0){
                    *err = 1;
                }
                else if(counter == 1){
                    *old = start->getvalue();
                    start = NULL;
                    curent = NULL;
                    sfarsit = NULL;
                    counter = 0;
                }
                else if(curent == sfarsit){
                    element *oldone = curent;
                    *old = oldone->getvalue();

                    curent = sfarsit->getprev();
                    curent->setnext(NULL);
                    sfarsit = curent;

                    counter --;
                    delete oldone;
                }
                else if(curent == start){
                    element *oldone = curent;
                    *old = oldone->getvalue();

                    curent = start->getnext();
                    curent->setprev(NULL);
                    start = curent;

                    counter --;
                    delete oldone;
                }
                else {
                    element *oldone = curent;
                    *old = oldone->getvalue();

                    curent->getprev()->setnext(curent->getnext());
                    curent->getnext()->setprev(curent->getprev());

                    curent = curent->getnext();
                    delete oldone;
                    counter --;

                }
            }
            else {
                if(counter == 0){
                    *err = 1;
                }
                else if(counter == 1){
                    *old = start->getvalue();
                    start = NULL;
                    curent = NULL;
                    sfarsit = NULL;
                    counter = 0;
                }
                else if(curent == sfarsit){
                    element *oldone = curent;
                    *old = oldone->getvalue();

                    curent = sfarsit->getprev();
                    curent->setnext(NULL);
                    sfarsit = curent;

                    counter --;
                    delete oldone;
                }
                else if(curent == start){
                    element *oldone = curent;
                    *old = oldone->getvalue();

                    curent = start->getnext();
                    curent->setprev(NULL);
                    start = curent;

                    counter --;
                    delete oldone;
                }
                else {
                    element *oldone = curent;
                    *old = oldone->getvalue();

                    curent->getprev()->setnext(curent->getnext());
                    curent->getnext()->setprev(curent->getprev());

                    curent = curent->getprev();
                    delete oldone;
                    counter --;

                }
            }
        }

        void findvalue(int value, int *err){
            *err = 0;
            if(counter == 0) *err = 1;
            else {

                element *save = curent;

                curent = start;

                while(curent->getvalue() != value){

                    if(curent->getnext() == NULL) {*err = 1; curent = save; break;}
                    curent = curent->getnext();
                }

                if(sfarsit->getvalue() == value) curent = sfarsit;
            }
        }

        void printLR(){
            element *save = curent;
            curent = start;
            while(curent != NULL){
                cout << curent->getvalue() << " ";
                curent = curent->getnext();
            }
            cout << endl;
            curent = save;
        }

        void printRL(){
            element *save = curent;
            curent = sfarsit;
            while(curent != NULL){
                cout << curent->getvalue() << " ";
                curent = curent->getprev();
            }
            cout << endl;
            curent = save;
        }
};

int main()
{
    int err;
    int old;

    Lista *L = new Lista();

    for(int i = 1; i <= 10; i++) L->add_right(i);

    L->printLR();
    L->printRL();

    L->findvalue(5, &err);

    L->deletee(&old, &err, 0);

    L->printLR();
    L->printRL();

    L->add_right(0);

    L->printLR();
    L->printRL();

    return 0;
}
