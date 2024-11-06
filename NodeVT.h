template <class T> class LinkedListT;
#include "NodeT.h"
template <class T>

class NodeVT{
    friend class LinkedListT<T>;
    private:
        T dato;
        bool processed = false;
        NodeVT<T> *next;
        NodeT<T> *adj;


    public:
        NodeVT<T>(T datoP){
            dato = datoP;
            next = nullptr;
            adj = nullptr;
        }

};