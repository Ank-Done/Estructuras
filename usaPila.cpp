#include <iostream>
using namespace std;

#include "Stack.h"

int main(){
    Stack<int> pilaEnteros;

    pilaEnteros.push(10);
    pilaEnteros.push(9);
    pilaEnteros.push(8);
    pilaEnteros.push(7);
    pilaEnteros.print();
    cout<<endl;
    cout<<pilaEnteros.peek();
    cout<<endl;
    cout<<endl;
    pilaEnteros.pop();
    pilaEnteros.print();
    return 0;
}