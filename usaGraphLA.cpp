#include <iostream>
using namespace std;

#include "LinkedListT.h"

int main(){
    LinkedListT<char> miListaV;
    miListaV.addFirst('a');
    miListaV.addLast('b');
    miListaV.addLast('c');
    miListaV.addLast('d');
    miListaV.addLast('e');
    miListaV.insertAdj('a','b');
    miListaV.insertAdj('b','a');
    miListaV.insertAdj('a','c');
    miListaV.insertAdj('c','a');
    miListaV.insertAdj('c','d');
    miListaV.insertAdj('d','c');
    miListaV.insertAdj('c','e');
    miListaV.insertAdj('e','c');
    miListaV.insertAdj('e','a');
    miListaV.insertAdj('a','e');


    miListaV.printGraph();
}