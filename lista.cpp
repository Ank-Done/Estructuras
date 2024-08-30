#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(){
    LinkedList miLista;
    int dato, pos;
    miLista.addFirst(20);
    miLista.addFirst(30);
    miLista.addFirst(40);
    miLista.addLast(10);
    miLista.printList();
    dato = miLista.getData(2);
    pos = miLista.findData(20);

    cout << dato<<endl;
    cout<<pos<<endl;
    if (miLista.deleteData(40)){
        cout<<"borrado"<<endl;
    }else{
        cout<<"no encontrado"<<endl;
    }
    miLista.deleteAt(2);
    miLista.printList();

    if (miLista.insertAt(1, 18))
        cout<<"Si se pudo gente"<<endl;
    miLista.printList();
    miLista.clear();
    miLista.printList();
    return 0;
}