#include <iostream>
#include "Zfraction.h"
using namespace std;

int main(){
    Zfraction a(4,5); // 4/5
    Zfraction b(2); // 2/1 = 2
    Zfraction c,d,e,f; // 0

    c = a + b;
    d = a * b;
    e = a - b;
    f = a / b;

    cout << endl << "Calcul arithmétiques" << endl;
    cout << a << " + " << b << " = " << c << endl;
    cout << a << " * " << b << " = " << d << endl;
    cout << a << " - " << b << " = " << e << endl;
    cout << a << " / " << b << " = " << f << endl;

    cout << endl << "Comparaison logique" << endl;
    if(a > b){
        cout << "a est plus grand que b." << endl;
    } else if(a == b){
        cout << "a est egal a b." << endl;
    } else{ 
        cout << "a est plus petit que b" << endl;
    }

    cout << endl << "Nombre reel" << endl;
    cout << a << " = " << a.nombreReel() << endl;
    cout << b << " = " << b.nombreReel() << endl;
    cout << e << " = " << e.nombreReel() << endl;
    cout << f << " = " << f.nombreReel() << endl;

    cin.ignore();
}
