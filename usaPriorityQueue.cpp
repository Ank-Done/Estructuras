// Fabian Orta
// Francisco Gonzalez

#include <iostream>
using namespace std;
#include "PriorityQueue.h"

int main() {
    PriorityQueue<int> filaNum;
    
    filaNum.insert(10);
    filaNum.insert(20);
    filaNum.insert(30);
    filaNum.insert(40);
    filaNum.insert(15);
    filaNum.insert(50);
    filaNum.insert(25);
    filaNum.insert(5);
    filaNum.insert(35);
    filaNum.insert(45);
    
    filaNum.print();
    
    cout << "Removed element with highest priority: " << filaNum.remove() << endl;
    
    filaNum.print();
    
    list<int> sortedList = filaNum.heapSort();
    cout << "Sorted elements: ";
    for (int elem : sortedList) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
