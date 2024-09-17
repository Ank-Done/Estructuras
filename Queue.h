#include "NodeT.h"
#include <iostream>

using namespace std;

template <class T>
class Queue{
    private:
        int size;
        NodeT<T> *head;
        NodeT<T> *tail;
    public:
        Queue(){
            size = 0;
            head = nullptr;
            tail = nullptr;
        }
        bool isEmpty(){return size == 0;};
        int getSize() {return size;};
        void enqueue(T dato);
        void print();
        T getData(int index);
        bool dequeue();
        void clear();
};
template <class T>
void Queue<T>::clear(){
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
    cout<<"Fila Borrada"<<endl;

    }else{
        cout<<"Fila vacia";
    }
}
template <class T>
bool Queue<T>::dequeue(){
     if(size>0){
    NodeT<T> *aux = head;
    head = aux->next;
    NodeT<T> *aux2;
    int pos = 0;
    aux->next = nullptr;
    delete aux;
    size--;
        return true;
    }else{
        return false;
       }
}
template <class T>
T Queue<T>::getData(int index){
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
void Queue<T>::enqueue(T dato){
NodeT<T> *aux = new NodeT<T>(dato);
    if(size > 0){
        tail->next = aux;
        tail = aux;
    }else{
        head = aux;
        tail = aux;
    }
        size++;
}
template <class T>
void Queue<T>::print(){
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