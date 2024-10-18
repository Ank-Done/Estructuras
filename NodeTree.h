class NodeTree{
    friend class BST;
    friend class BSTRemake;
    private:
    int dato;
    NodeTree *left, *right;
    public:
    NodeTree(int datoP){
        dato = datoP;
        left = nullptr;
        right = nullptr;
    }
};