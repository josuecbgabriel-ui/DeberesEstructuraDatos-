#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H
#include "Nodo.h"

using namespace std;

class ListaDobleCircular {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaDobleCircular();
    void insertar(string n);
    void mostrar();
    void buscar(string n);
    void eliminar(string n);
    void invertir(); // Deber 1
    string obtenerEnPosicion(int pos); 
};

#endif