#include "NodeT.h"
#include <iostream>

using namespace std;

template <class T>
class Stack{
    private:
        int size;
        NodeT<T> *top;
    public:
        Stack(){
            size = 0;
            top = nullptr;
        }

        ~Stack(){};
        bool isEmpty(){return size == 0;};
        int getSize() {return size;};
        void push(T dato);
        void print();
        T peek();
        int findData(T data);
        bool pop(); //indice (0)
        void clear();
};
template <class T>
void Stack<T>::clear(){
    if (size>0){
        NodeT<T> *aux = top;
    while(top -> next != nullptr){
        top = aux -> next;
        aux -> next = nullptr;
        delete aux;
        aux = top;
        size--;
    }
    top = nullptr;
    delete aux;
    size--;
    cout<<"Lista Borrada"<<endl;

    }
}
template <class T>
bool Stack<T>::pop(){
    if (size>0){
    NodeT<T> *aux = top;
        top = aux->next;
        aux->next = nullptr;
        delete aux;
        size--;
        return true;
    }else{
        return false;
    }
}
template <class T>
int Stack<T>::findData(T data){
    NodeT<T> *aux = top;
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
T Stack<T>::peek(){
    if(size > 0){
        return top->dato;
    }else{
        return -1;
    }
}
template <class T>
void Stack<T>::push(T dato){
    NodeT<T> *aux = new NodeT<T>(dato);
    aux->next = top;
    top = aux;
    size++;
}
template <class T>
void Stack<T>::print(){
    if (size>0){
    NodeT<T> *aux = top;
    for(int i = 0; i<size; i++){
        cout<<aux->dato << endl;
        aux = aux->next;

    }
    }else{
        cout<<"Lista vacia"<<endl;
    }
}