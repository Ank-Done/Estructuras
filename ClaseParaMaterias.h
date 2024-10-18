#include <iostream>
#include <string>
using namespace std;

class Materia{
    private:
    string nombre;
    Profesor maestro;
    int CRN;
    int Creditos;

    private:
    Materia();{nombre}
    void guardaNombre();
    void guardaCRN();
    void guardaCreditos();


};