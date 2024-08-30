#include <string>
class Calificacion{
    private:
std::string nombreAlumno;
    double calActividades;
    double calExamen;
    double calProyecto;
    public:
    void setNombre(std::string nombre){nombreAlumno = nombre;};
    void setAct(double cal){calActividades = cal;};
    void setEx(double cal){calExamen = cal;};
    void setProy(double cal){calProyecto = cal;};
std::string getNombre(){return nombreAlumno;};
    double getAct(){return calActividades;};
    double getEx(){return calExamen;};
    double getProy(){return calProyecto;};
    
};