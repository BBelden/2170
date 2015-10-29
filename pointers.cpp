#include <iostream>

using namespace std;

int x;
int* p;
int* q;

void printValues(){
    cout << "---------------------------------\n"; 
    cout << "&x: " << &x << ", x: " << x << endl;
     
    cout << "&p: " << &p << ", p: " << p << ", *p: ";
    if( p != NULL){
        cout << *p;
    }else{
        cout << "NULL";
    }
    cout << endl;
     
    cout << "&q: " << &q << ", q: " << q << ", *q: ";
    if( q != NULL){
        cout << *q;
    }else{
        cout << "NULL";
    }
    cout << endl;
    cout << endl;
}

int main(){
    cout << "int x;\nint* pl\nint* q;\n";
    printValues();

     p = &x;
     cout << "p = &x;" << endl;
     printValues();

     *p = 7;
     cout << "*p = 7;" << endl;
     printValues();

     p = new int;
     cout << "*p = new int;" << endl;
     printValues();

     *p = 9;
     cout << "*p = 9;" << endl;
     printValues();

     q = p;
     cout << "q = p;" << endl;
     printValues();

     q = new int;
     cout << "q = new int;" << endl;
     *q = 11;
     cout << "*q = 11;" << endl;
     printValues();

     p = NULL;
     cout << "p = NULL;" << endl;
     printValues();
     
     delete q;
     cout << "delete q;" << endl;
     printValues();

     q = NULL;
     
    return 0;
}
