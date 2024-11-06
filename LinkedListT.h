#include "NodeVT.h"
#include <iostream>

using namespace std;

template <class T>
class LinkedListT{
    private:
        int size;
        NodeVT<T> *head;
    public:
        LinkedListT<T>(){
            size = 0;
            head = nullptr;
        }
        bool isEmpty(){return size == 0;};
        int getSize() {return size;};
        void addFirst(T dato);
        void addLast(T dato);
        void printList();
        T getData(int index);
        int findData(T data);
        bool deleteData(T data);
        bool deleteAt(int index);
        void updateData(T data, T newData);
        void updateAt(int index, T newData);
        bool insertAt(int index, T data);
        void insertAdj(T fromV, T toV);
        void printGraph();
        void printBFS();
        void clear();
};
template <class T>
void LinkedListT<T>::printGraph(){
    if (size>0){
        NodeVT<T> *aux = head;
        NodeT<T> *auxA = aux->adj;
        for (int i=0; i<size; i++){
            cout<<aux->dato << " ";
            auxA= aux->adj;
            while(auxA!=nullptr){
                cout<<auxA->dato <<" ";
                auxA = auxA->next;
            }
            aux = aux->next;
            cout<<endl;
        }
    }else{
        cout<<"lista vacia\n";
    }
}
template <class T>
void LinkedListT<T>::insertAdj(T fromV, T toV){
    NodeVT<T> *aux = head;
    int pos = 0;
    while(aux -> dato!= fromV && pos< size){
        aux = aux->next;
        pos++;
    }
    if (aux->dato == fromV){ //aqui voy a ligar lista adjaciencia
        NodeT<T> *newAdj = new NodeT<T>(toV);
        NodeT<T> *aux2;
        if(aux->adj == nullptr){
            aux->adj = newAdj;
        }else{
            aux2 = aux->adj;
            while( aux2->next = nullptr){
                aux2 = aux2->next;
            }
            aux2->next = newAdj;
        }
    }
}
template <class T>
void LinkedListT<T>::clear(){
    if (size>0){
        NodeT<T> *aux = head;
    while(head -> next != nullptr){
        head = aux -> next;
        aux -> next = nullptr;
        delete aux;
        aux = head;
        size--;
    }
    head = nullptr;
    delete aux;
    size--;
    cout<<"Lista Borrada"<<endl;

    }
}
template <class T>
bool LinkedListT<T>::insertAt(int index, T data){
    if (index<size){
    NodeT<T> *aux = head;
    NodeT<T> *aux2 = aux;
    int pos = 0;
    while(pos < index){
        aux2 = aux;
        aux = aux ->next;
        pos++;
    }
        if (pos==0){
            addFirst(data);
            return true;
        }else{
            NodeT<T> *newNodo = new NodeT<T>(data);
            newNodo -> dato = data;
            newNodo -> next = aux2 ->next;
            aux2->next = newNodo;
            size++; 
            return true;
        }
    }else{
        cout<<"index > size "<< index <<" "<< size<< endl;
        return false;
    }
}
template <class T>
void LinkedListT<T>::updateData(T data, T newData){
    NodeT<T> *aux = head;
    int pos = 0;
    while(aux->dato != data && pos < size){
        aux = aux ->next;
        pos++;
    }
    if (aux->dato == data){
        aux->dato = newData;
    }
}
template <class T>
bool LinkedListT<T>::deleteAt(int index){
    if (index<size){
    NodeT<T> *aux = head;
    NodeT<T> *aux2;
    int pos = 0;
    while(pos < index){
        aux2 = aux;
        aux = aux ->next;
        pos++;
    }
        if (pos==0){
            head = aux->next;
        }else{
            aux2->next = aux->next; 
        }
        aux->next = nullptr;
        delete aux;
        size--;
        return true;
    }else{
        return false;
    }
}
template <class T>
void LinkedListT<T>::updateAt(int index, T newData){
    if(size >0 && index < size){
        NodeT<T> *aux = head;
        for (int pos = 0; pos<index; pos++){
            aux = aux -> next;
        }
        aux->dato = newData;
    }
}
template <class T>
bool LinkedListT<T>::deleteData(T data){
    NodeT<T> *aux = head;
    NodeT<T> *aux2;
    int pos = 0;
    while(aux->dato != data && pos < size){
        aux2 = aux;
        aux = aux ->next;
        pos++;

    }
    if (aux->dato == data){
        if (pos==0){
            head = aux->next;
            aux->next = nullptr;
            delete aux;
        }else{
            aux2->next = aux->next;
            aux->next = nullptr;
            delete aux;   
        }
        size--;
        return true;
    }else{
        return false;
    }
}
template <class T>
int LinkedListT<T>::findData(T data){
    NodeT<T> *aux = head;
    int pos = 0;
    while(aux->dato != data && pos < size){
        aux = aux ->next;
        pos++;
    }
    if (aux->dato == data){
        return pos;
    }else{
        return -1;
    }
}
template <class T>
T LinkedListT<T>::getData(int index){
    if(size >0 && index < size){
        NodeT<T> *aux = head;
        for (int pos = 0; pos<index; pos++){
            aux = aux -> next;
        }
        return aux->dato;
    }else{
        return -1;
    }
}
template <class T>
void LinkedListT<T>::addFirst(T dato){
    NodeVT<T> *aux = new NodeVT<T>(dato);
    aux->next = head;
    head = aux;
    size++;
}
template <class T>
void LinkedListT<T>::addLast(T dato){
    NodeVT<T> *aux = head;
    for(int i= 0; i<size-1; i++){
        aux = aux -> next;
    }
    aux->next = new NodeVT<T>(dato);
    size++;
}
template <class T>
void LinkedListT<T>::printList(){
    if (size>0){
    NodeT<T> *aux = head;
    /*if (size == 1) cout<<aux->dato << endl;
        while (aux->next != nullptr){
        cout<<aux->dato << endl;
        aux = aux->next;
    }*/
    for(int i = 0; i<size; i++){
        cout<<aux->dato << endl;
        aux = aux->next;

    }
    }else{
        cout<<"Lista vacia"<<endl;
    }
}