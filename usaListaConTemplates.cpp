#include <iostream>
using namespace std;

#include "LinkedListT.h"

int main(){
    LinkedListT<int> listaEnt;
    LinkedListT<string> listaStr;

    for (int i = 0; i<5; i++){
        listaEnt.addFirst(i);
    }
    listaEnt.printList();
}