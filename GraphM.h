#include <iostream>
using namespace std;

class GraphM{
    public:
    GraphM();
    void insertVertex(char arrV[], int cantVer);
    void insertEdges(char fromVertex, char toVertex);
    void deleteEdges(char fromVertex, char toVertex);
    void print();
    private:
    bool mat[10][10] {false};
    char arrVertex[10];
    int cantVertices;
    int findPos(char vertex);
};

GraphM::GraphM(){
    cantVertices = 0;
}

void GraphM::insertVertex(char arrV[], int cantVer){
    for (int i = 0; i<cantVer; i++){
        arrVertex[i] = arrV[i];
    }
    cantVertices = cantVer;
}

int GraphM::findPos(char vertex){
    int pos=-1;
    int i=0;
    while((pos==-1)&&(i<cantVertices)){
        if(arrVertex[i] == vertex){
            pos = i;
        }
        i++;
    }
    return pos;
}

void GraphM::insertEdges(char fromVertex, char toVertex){
    int posR = findPos(fromVertex);
    int posC = findPos(toVertex);
    mat[posR][posC] = true;
    mat[posC][posR] = true;
}
void GraphM::deleteEdges(char fromVertex, char toVertex){
    int posR = findPos(fromVertex);
    int posC = findPos(toVertex);
    mat[posR][posC] = false;
    mat[posC][posR] = false;
}

void GraphM::print(){
    for(int i = 0; i<cantVertices; i++){
        cout<<arrVertex[i]<<" ";
        for (int c=0; c<cantVertices; c++){
            cout<<mat[i][c]<<" ";
        }
        cout<<endl;
    }
}