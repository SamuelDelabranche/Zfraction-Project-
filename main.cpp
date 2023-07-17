#include <iostream>
#include "Zfraction.h"
using namespace std;

int main(){
    Zfraction a(4,5); // 4/5
    Zfraction b(2); // 2/1 = 2
    Zfraction c,d; // 0

    c = a + b;
    d = a * b;

    cout << a << " + " << b << " = " << c << endl;
    cout << a << " * " << b << " = " << d << endl;

    if(a > b){
        cout << "a est plus grand que b." << endl;
    } else if(a == b){
        cout << "a est egal a b." << endl;
    } else{ cout << "a est plus petit que b" << endl;}

    cin.ignore();
}