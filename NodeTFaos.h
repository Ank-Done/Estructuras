template <class T> class LinkedListT;
template <class T> class Queue;
template <class T> class Stack;
template <class T>

class NodeT{
    friend class LinkedListT<T>;
    friend class Queue<T>;
    friend class Stack<T>;
    private:
        T dato;
        NodeT<T> *next;

    public:
        NodeT<T>(T datoP){
            dato = datoP;
            next = nullptr;
        }

};