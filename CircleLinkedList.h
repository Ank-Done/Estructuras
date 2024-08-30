#include "Node.h"
#include <iostream>

using namespace std;

class CircleLinkedList{
    private:
        int size;
        Node *head;
    public:
        CircleLinkedList(){
            size = 0;
            head = nullptr;
        }
        bool isEmpty(){return size == 0;};
        int getSize() {return size;};
        void addFirst(int dato);
        void addLast(int dato);
        void printList();
        int getData(int index);
        int findData(int data);
        bool deleteData(int data);
        bool deleteAt(int index);
        void updateData(int data, int newData);
        void updateAt(int index, int newData);
        bool insertAt(int index, int data);
        void clear();
};
void CircleLinkedList::clear(){
    if (size>0){
        Node *aux = head;
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

bool CircleLinkedList::insertAt(int index, int data){
    if (index<size){
    Node *aux = head;
    Node *aux2 = aux;
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
            Node *newNodo = new Node(data);
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

void CircleLinkedList::updateData(int data, int newData){
    Node *aux = head;
    int pos = 0;
    while(aux->dato != data && pos < size){
        aux = aux ->next;
        pos++;
    }
    if (aux->dato == data){
        aux->dato = newData;
    }
}

bool CircleLinkedList::deleteAt(int index){
    if (index<size){
    Node *aux = head;
    Node *aux2;
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

void CircleLinkedList::updateAt(int index, int newData){
    if(size >0 && index < size){
        Node *aux = head;
        for (int pos = 0; pos<index; pos++){
            aux = aux -> next;
        }
        aux->dato = newData;
    }
}

bool CircleLinkedList::deleteData(int data){
    Node *aux = head;
    Node *aux2;
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

int CircleLinkedList::findData(int data){
    Node *aux = head;
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

int CircleLinkedList::getData(int index){
    if(size >0 && index < size){
        Node *aux = head;
        for (int pos = 0; pos<index; pos++){
            aux = aux -> next;
        }
        return aux->dato;
    }else{
        return -1;
    }
}
void CircleLinkedList::addFirst(int dato){
    Node *aux = new Node(dato);
    aux->next = head;
    head = aux;
    size++;
}

void CircleLinkedList::addLast(int dato){
    Node *aux = head;
    for(int i= 0; i<size-1; i++){
        aux = aux -> next;
    }
    aux->next = new Node(dato);
    size++;
}
void CircleLinkedList::printList(){
    if (size>0){
    Node *aux = head;
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