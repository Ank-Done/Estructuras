#include <iostream>
#include <fstream>
#include "Calificacion.h"

using namespace std;

double promedio (double c1, double c2, double c3){
    return (c1*.3+c2*0.3+c3*.4);
}

int main(){
    std::string nombre;
    double calA,calE,calP,prom;
    int cont = 0, opcion;
    Calificacion grupo[20];
    ifstream entrada;
    entrada.open("calificaciones.txt");
    while(entrada>>nombre>>calA>>calE>>calP){
        grupo[cont].setNombre(nombre);
        grupo[cont].setAct(calA);
        grupo[cont].setEx(calE);
        grupo[cont].setProy(calP);
        cont++;
    }
    entrada.close();
    do{
        cout << "1) listado de alumnos \n";
        cout << "2) alumnos con promedio mayor a 80 \n";
        cout << "3) salir \n";
        cin>>opcion;

        if(opcion==1){
            for (int i=0; i<cont; i++){
                cout << grupo[i].getNombre() << "\n";
                cout << "Cal Actividades " << grupo[i].getAct() << "\n";
                cout << "Cal Examen " << grupo[i].getEx() << "\n";
                cout << "Cal Proyecto " << grupo[i].getProy() << "\n";
                cout << "Promedio " << promedio(grupo[i].getAct(), grupo[i].getEx(), grupo[i].getProy()) << "\n";
            }
        }
        if (opcion==2){
            for (int i=0; i<cont; i++){
                prom = promedio(grupo[i].getAct(), grupo[i].getEx(), grupo[i].getProy());
                if (prom > 85){
                    cout << "Cal Actividades " << grupo[i].getAct() << "\n";
                    cout << "Cal Examen " << grupo[i].getEx() << "\n";
                    cout << "Cal Proyecto " << grupo[i].getProy() << "\n";
                    cout << "Promedio " << promedio(grupo[i].getAct(), grupo[i].getEx(), grupo[i].getProy()) << "\n";
                
                }
            }
        }
    }while (opcion != 3);
    return 0;
}