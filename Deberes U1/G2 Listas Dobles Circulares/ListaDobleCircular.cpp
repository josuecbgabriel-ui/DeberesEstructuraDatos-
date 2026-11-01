#include "ListaDobleCircular.h"
#include <iostream>

using namespace std;

ListaDobleCircular::ListaDobleCircular() {
    cabeza = nullptr;
    cola = nullptr;
}

void ListaDobleCircular::insertar(string n) {
    Nodo* nuevo = new Nodo(n);
    
    if (cabeza == nullptr) {
        cabeza = nuevo;
        cola = nuevo;
        // Al ser circular, se apunta a sí mismo
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    } else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
        cola = nuevo;
    }
    cout << "Insertado: " << n << endl;
}

void ListaDobleCircular::mostrar() {
    if (cabeza == nullptr) {
        cout << "La lista esta vacia." << endl;
        return;
    }
    
    cout << "Lista (Inicio a Fin): ";
    Nodo* actual = cabeza;
    do {
        cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    } while (actual != cabeza);
    cout << "(Vuelta a " << cabeza->dato << ")" << endl;

    cout << "Lista (Fin a Inicio): ";
    actual = cola;
    do {
        cout << actual->dato << " <-> ";
        actual = actual->anterior;
    } while (actual != cola);
    cout << "(Vuelta a " << cola->dato << ")" << endl;
}

void ListaDobleCircular::buscar(string n) {
    if (cabeza == nullptr) return;
    
    Nodo* actual = cabeza;
    do {
        if (actual->dato == n) {
            cout << "-> Nombre encontrado: " << n << endl;
            return;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);
    
    cout << "-> Nombre '" << n << "' no encontrado." << endl;
}

void ListaDobleCircular::eliminar(string n) {
    if (cabeza == nullptr) return;
    
    Nodo* actual = cabeza;
    bool encontrado = false;
    
    do {
        if (actual->dato == n) {
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    if (!encontrado) {
        cout << "-> No se pudo eliminar: " << n << " (No encontrado)" << endl;
        return;
    }

    // Si es el único elemento de la lista
    if (cabeza == cola && actual == cabeza) {
        cabeza = nullptr;
        cola = nullptr;
    } else {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
        
        if (actual == cabeza) {
            cabeza = actual->siguiente;
        } else if (actual == cola) {
            cola = actual->anterior;
        }
    }
    delete actual;
    cout << "-> Se elimino correctamente: " << n << endl;
}

void ListaDobleCircular::invertir() {
    if (cabeza == nullptr || cabeza == cola) {
        return;
    }

    Nodo* actual = cabeza;
    Nodo* temp = nullptr;

    // Recorremos todos los nodos intercambiando punteros
    do {
        temp = actual->anterior;
        actual->anterior = actual->siguiente;
        actual->siguiente = temp;

        actual = actual->anterior; 
    } while (actual != cabeza);


    temp = cabeza;
    cabeza = cola;
    cola = temp;
}

string ListaDobleCircular::obtenerEnPosicion(int pos) {
    if (cabeza == nullptr || pos < 0) {
        return "Error: Lista vacia o posicion invalida";
    }

    Nodo* actual = cabeza;
    int contador = 0;

    do {
        if (contador == pos) {
            return actual->dato;
        }
        actual = actual->siguiente;
        contador++;
    } while (actual != cabeza);

    return "Error: Posicion fuera de rango";
}