#ifndef NODO_H
#define NODO_H
#include <string>

using namespace std;

class Nodo {
    // Declaramos a la lista como clase amiga para poder acceder a los punteros
    friend class ListaDobleCircular;
private:
    string dato;
    Nodo* siguiente;
    Nodo* anterior;
public:
    Nodo(string d) {
        dato = d;
        siguiente = nullptr;
        anterior = nullptr;
    }
};

#endif