#include "NodeTree.h"
#include <iostream>

using namespace std;

class BST{
    private:
        NodeTree *root; //variables que vas a usar como parametro
        int numChildren(NodeTree *nodo);
        NodeTree* predecesor(NodeTree* p, NodeTree* &parent);
        NodeTree* sucesor(NodeTree* p);
        void preorden(NodeTree* p);
        void inorden(NodeTree* p);
        void postorden(NodeTree* p);

    public:
        BST(){root = nullptr;}; //consultas con los parametros
        void add(int dato);
        bool remove(int dato);
        bool find(int dato);
        void visita(int orden);
        void recorrido();
        void altura();
        void deleteBST();
};
void BST::deleteBST(){
        NodeTree *parent = nullptr;
        NodeTree* aux = root; //aux apunta a la raiz

        
}

void BST::altura(){
    cout<<"hola";
}

void BST::recorrido(){
    if(root!=nullptr){
        NodeTree* aux = root;
        while(aux != nullptr){
            while(aux ->right != nullptr){
                
            }
        }
    }else{
        cout<<"No hay nadota\n";
    }
}

void BST::visita(int orden){
    switch(orden)
    {
        case 1:
        preorden(root);
        break;
        case 2:
        inorden(root);
        break;
        case 3:
        postorden(root);
        break;
        

    default:
    break;
    }
}

void BST::preorden(NodeTree* p){
    if(p!=nullptr){
        cout<<p->dato << " ";
        preorden(p->left);
        preorden(p->right);
    }
}
void BST::inorden(NodeTree* p){
    if(p!=nullptr){
        inorden(p->left);
        cout<<p->dato << " ";
        inorden(p->right);
    }
}
void BST::postorden(NodeTree* p){
    if(p!=nullptr){
        postorden(p->left);
        postorden(p->right);
        cout<<p->dato << " ";
    }
}

NodeTree* BST::predecesor(NodeTree* p, NodeTree* &parent){
    parent = p;
    NodeTree *aux = p->left;
    while(aux->right!=nullptr){
        parent = aux;
        aux = aux -> right;
    }
    return aux;

}

NodeTree* BST::sucesor(NodeTree* p){
    NodeTree *aux = p->right;
    while(aux->left!=nullptr){
        aux = aux -> left;
    }
    return aux;

}

int BST::numChildren(NodeTree *nodo){
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
bool BST::find(int dato){
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
bool BST::remove(int dato){
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

void BST::add(int dato){
if(root == nullptr){ //arbol vacio
        root = new NodeTree(dato);
    }else{
        NodeTree* aux = root; //aux apunta a la raiz
        while(aux != nullptr){
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