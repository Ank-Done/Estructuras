#include "NodeTree.h"
#include "Queue.h"
#include <iostream>

using namespace std;

class BSTRemake{
    private:
        NodeTree *root; //variables que vas a usar como parametro
        int numChildren(NodeTree *nodo);
        NodeTree* predecesor(NodeTree* p, NodeTree* &parent);
        NodeTree* sucesor(NodeTree* p);
        void preorden(NodeTree* p);
        void inorden(NodeTree* p);
        void postorden(NodeTree* p);
        void deleteTreePostOrder(NodeTree* node);
        bool encontrarAncestros(NodeTree* node, int dato, Queue<int>& ancestros);
        int height(NodeTree* node);
        NodeTree* encontrarNodo(NodeTree* node, int dato);
        int calcularNivel(NodeTree* node, int dato, int nivel);
        

    public:
        BSTRemake(){root = nullptr;}; //consultas con los parametros
        void add(int dato);
        bool remove(int dato);
        bool find(int dato);
        void visita(int orden);
        void nivelPorNivel();
        void nivelPorNivel(NodeTree* aux);
        void height();
        void deleteTree();
        void ancestros(int dato);
        int whatLevelAmI(int dato);
        
};

int BSTRemake::calcularNivel(NodeTree* node, int dato, int nivel) {
        if (!node) return -1; // Si el nodo es nulo, regresamos -1
        if (node->dato == dato) return nivel; // Si encontramos el dato, regresamos el nivel actual

        // Buscamos en el subárbol izquierdo
        int nivelIzquierda = calcularNivel(node->left, dato, nivel + 1);
        if (nivelIzquierda != -1) return nivelIzquierda;

        // Buscamos en el subárbol derecho
        return calcularNivel(node->right, dato, nivel + 1);
    }

NodeTree* BSTRemake::encontrarNodo(NodeTree* node, int dato) {
        if (!node || node->dato == dato) return node;
        if (dato < node->dato) return encontrarNodo(node->left, dato);
        return encontrarNodo(node->right, dato);
    }

int BSTRemake::whatLevelAmI(int dato) {
        int nivel = calcularNivel(root, dato, 1); // Comenzamos con el nivel 1 para la raíz
        if (nivel == -1) {
            cout << "no se encuentra en el arbol" << endl;
            return -1;
        }
        return nivel;
    }

void BSTRemake::ancestros(int dato) {
        Queue<int> ancestros;
        if (encontrarAncestros(root, dato, ancestros)) {
            cout << "Los ancestros de " << dato << " son: ";
            while (!ancestros.isEmpty()) {
                cout << ancestros.peek() << " ";
                ancestros.dequeue();
            }
            cout << endl;
        } else {
            cout << "no tiene ancestros" << endl;
        }
    }

bool BSTRemake::encontrarAncestros(NodeTree* node, int dato, Queue<int>& ancestros) {
        if (!node) return false;
        if (node->dato == dato) return true;

        if (encontrarAncestros(node->left, dato, ancestros) || encontrarAncestros(node->right, dato, ancestros)) {
            ancestros.enqueue(node->dato);
            return true;
        }
        return false;
    }

void BSTRemake::deleteTreePostOrder(NodeTree* node) {
            if(node == nullptr){
                return;
            }
        deleteTreePostOrder(node->left);
        deleteTreePostOrder(node->right);
            delete node;
        }

void BSTRemake::nivelPorNivel() {
            if(root != nullptr){
                nivelPorNivel(root);
            }else{
                cout << "Arbol vacio!\n";
            }
        }

void BSTRemake::nivelPorNivel(NodeTree* aux){
            Queue<NodeTree*> printQueue;
            cout << "Recorrido por niveles: ";
            printQueue.enqueue(aux);
            while(!printQueue.isEmpty()){
                aux = printQueue.peek();
                cout << ' ' << aux->dato;
                printQueue.dequeue();
                if(aux->left != nullptr){
                    printQueue.enqueue(aux->left);
                }
                if(aux->right != nullptr){
                    printQueue.enqueue(aux->right);
                }
            }
            cout << '\n'; 
        }

void BSTRemake::height(){
            cout << "La altura del arbol es de: " << height(root) << " niveles. \n";
        }

int BSTRemake::height(NodeTree* node){

           if(node == nullptr){
             return 0;
         }
         Queue<NodeTree*> q;
        q.enqueue(node);
        int height = 0;
         while(!q.isEmpty()){
             int cuenta = q.getSize();
             if (cuenta == 0){
                return height;
                             }
             height++;
             while(cuenta > 0){
                 NodeTree* tempNode = q.peek();
                 q.dequeue();
                 if(tempNode->left != nullptr){
                     q.enqueue(tempNode->left);
                 }
                 if(tempNode->right != nullptr){
                     q.enqueue(tempNode->right);
                 }
                 cuenta--;
             }
         }
         return height;
     }

void BSTRemake::deleteTree() {
            deleteTreePostOrder(root);
            root = nullptr;
            cout << "Arbol borrado! \n";
}
void BSTRemake::visita(int orden){
    switch(orden)
    {
        case 1:
        cout<<"Impresion preorden: ";
        preorden(root);
        break;
        case 2:
        cout<<"Impresion inorden: ";
        inorden(root);
        break;
        case 3:
        cout<<"Impresion postorden: ";
        postorden(root);
        break;
        case 4:
        nivelPorNivel(root);
        break;

        

    default:
    break;
    }
}

void BSTRemake::preorden(NodeTree* p){
    if(p!=nullptr){
        cout<<p->dato << " ";
        preorden(p->left);
        preorden(p->right);
    }
}
void BSTRemake::inorden(NodeTree* p){
    if(p!=nullptr){
        inorden(p->left);
        cout<<p->dato << " ";
        inorden(p->right);
    }
}
void BSTRemake::postorden(NodeTree* p){
    if(p!=nullptr){
        postorden(p->left);
        postorden(p->right);
        cout<<p->dato << " ";
    }
}

NodeTree* BSTRemake::predecesor(NodeTree* p, NodeTree* &parent){
    parent = p;
    NodeTree *aux = p->left;
    while(aux->right!=nullptr){
        parent = aux;
        aux = aux -> right;
    }
    return aux;

}

NodeTree* BSTRemake::sucesor(NodeTree* p){
    NodeTree *aux = p->right;
    while(aux->left!=nullptr){
        aux = aux -> left;
    }
    return aux;

}

int BSTRemake::numChildren(NodeTree *nodo){
    if(nodo->left == nullptr && nodo->right == nullptr){
        return 0;
    }else{
        if(nodo->left != nullptr && nodo->right != nullptr){
            return 2;
        }else{
            return 1;
        }
    }
}
bool BSTRemake::find(int dato){
    if(root == nullptr){ //arbol vacio
        return false;
    }else{
        NodeTree* aux = root; //aux apunta a la raiz
        while(aux != nullptr){
            if(aux->dato == dato){
                return true; //lo ha encontrado maravillosamente UwU
            }
            else{
                if(aux -> dato > dato){
                    aux = aux->left;
                }else{
                    aux = aux->right;
                }
            }
        }//while
    return false;
    }
}
bool BSTRemake::remove(int dato){
    if(root == nullptr){ //arbol vacio
    cout<<"arbol vacio\n";
        return false;
    }else{
        NodeTree *parent = nullptr;
        NodeTree* aux = root; //aux apunta a la raiz
        while(aux != nullptr){
            if(aux->dato == dato){
                //return true; //lo ha encontrado maravillosamente UwU
                switch (numChildren(aux))
                {
                case 0: //no tiene hijos
                    if (root == aux){
                        root = nullptr;
                    }else{
                        if (parent -> left == aux){
                            parent -> left = nullptr;
                        }else{
                            parent -> right = nullptr;
                        }
                    }
                    delete aux;
                    break;
                case 1: //
                if (parent == nullptr){//root == aux es la raiz
                if (aux->left == nullptr){
                    root = aux ->right;
                    }else{
                        root = aux ->left;
                    }
                }
                    if (parent -> left == aux){
                        if(aux -> left == nullptr){
                            parent -> left = aux -> right;
                        }else{
                            parent -> left = aux -> left;
                        }
                    }else{
                        if (aux ->left == nullptr){
                            parent -> right = aux -> right;
                        }else{
                            parent -> right = aux -> left;
                        }
                    }
                    delete aux;
                    break;
                 case 2: // predecesor o sucesor
                        NodeTree* parent = nullptr;
                        NodeTree *aux2 = predecesor(aux, parent);
                        aux -> dato = aux2->dato;
                        cout << "valor predecesor " << aux2->dato << endl;
                        cout << "padre del predecesor " << parent -> dato << endl;
                        // revisar el caso que aux2 tenga un hijo al a izq
                        if(aux2->left == nullptr){
                            parent->right = nullptr;
                        }else{
                            parent->right = aux2->left;
                        }
                        delete aux2;
                    break;
                }
                aux = nullptr;
                    return true;
            }else{
                parent = aux;
                if(aux -> dato > dato){
                    
                    aux = aux->left;
                }else{
                    aux = aux->right;
                }
            }
        }//while
    return false;
    }
}

void BSTRemake::add(int dato){
if(root == nullptr){ //arbol vacio
        root = new NodeTree(dato);
    }else{
        NodeTree* aux = root; //aux apunta a la raiz
        while(aux != nullptr){   //iniciaa el while
            if(aux->dato == dato){
                cout<<"dato duplicado"<<endl; //lo ha encontrado maravillosamente UwU
                aux = nullptr;
            }else{
                if(aux -> dato > dato){
                    if(aux->left == nullptr){
                        aux->left = new NodeTree(dato);
                        aux = nullptr;
                    }else{
                        aux = aux->left;
                    }
                }else{
                    if(aux->right == nullptr){
                        aux->right = new NodeTree(dato);
                        aux = nullptr;
                    }else{
                        aux = aux->right;
                    }
                }
            }
        }//while
    }    
}