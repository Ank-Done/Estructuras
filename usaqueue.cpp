#include <iostream>
using namespace std;

#include "Queue.h"

int main(){
    Queue<int> filaNum;
    filaNum.enqueue(10);
    filaNum.enqueue(20);
    filaNum.enqueue(30);
    filaNum.enqueue(40);

    filaNum.print();

    cout<<endl;

    filaNum.dequeue();
    filaNum.print();
    return 0;
}