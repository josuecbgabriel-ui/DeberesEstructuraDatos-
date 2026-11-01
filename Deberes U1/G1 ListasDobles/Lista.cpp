#include "Lista.h"

ListaDoble::ListaDoble() {
    cabeza = nullptr;
    cola = nullptr;
}

void ListaDoble::invertir() { 
    // Usamos getSiguiente() en lugar de ->siguiente
    if (cabeza == nullptr || cabeza->getSiguiente() == nullptr) { 
        return; 
    }

    Nodo* actual = cabeza;
    Nodo* temp = nullptr;

    while (actual != nullptr) {
        // temp = actual->anterior;
        temp = actual->getAnterior();
        
        // actual->anterior = actual->siguiente;
        actual->setAnterior(actual->getSiguiente());
        
        // actual->siguiente = temp;
        actual->setSiguiente(temp);
        
        // actual = actual->anterior;
        actual = actual->getAnterior(); 
    }

    if (temp != nullptr) {
        // Actualizamos la cola para mantener tu estructura intacta
        cola = cabeza; 
        
        // cabeza = temp->anterior;
        cabeza = temp->getAnterior();
    }
}
void ListaDoble::insertar(string n) {
    Nodo* nuevo = new Nodo(n);

    if (cabeza == nullptr) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cola->setSiguiente(nuevo);
        nuevo->setAnterior(cola);
        cola = nuevo;
    }

    cout << "Insertado: " << n << endl;
}

void ListaDoble::buscar(string n) {
    Nodo* actual = cabeza;

    while (actual != nullptr) {
        if (actual->getNombre() == n) {
            cout << "-> Nombre encontrado: " << actual->getNombre() << endl;
            return;
        }
        actual = actual->getSiguiente();
    }

    cout << "-> Nombre '" << n << "' no encontrado.\n";
}

void ListaDoble::eliminar(string n) {
    Nodo* actual = cabeza;

    while (actual != nullptr && actual->getNombre() != n) {
        actual = actual->getSiguiente();
    }

    if (actual == nullptr) {
        cout << "-> No se puede eliminar. Nombre '" << n << "' no encontrado.\n";
        return;
    }

    if (actual == cabeza && actual == cola) {
        cabeza = nullptr;
        cola = nullptr;
    }
    else if (actual == cabeza) {
        cabeza = cabeza->getSiguiente();
        cabeza->setAnterior(nullptr);
    }
    else if (actual == cola) {
        cola = cola->getAnterior();
        cola->setSiguiente(nullptr);
    }
    else {
        actual->getAnterior()->setSiguiente(actual->getSiguiente());
        actual->getSiguiente()->setAnterior(actual->getAnterior());
    }

    delete actual;
    cout << "-> Se elimino correctamente: " << n << endl;
}

void ListaDoble::imprimirAdelante() {
    if (cabeza == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }

    Nodo* actual = cabeza;
    cout << "Lista (Inicio a Fin): NULL <-> ";
    while (actual != nullptr) {
        cout << actual->getNombre() << " <-> ";
        actual = actual->getSiguiente();
    }
    cout << "NULL\n";
}

void ListaDoble::imprimirAtras() {
    if (cola == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }

    Nodo* actual = cola;
    cout << "Lista (Fin a Inicio): NULL <-> ";
    while (actual != nullptr) {
        cout << actual->getNombre() << " <-> ";
        actual = actual->getAnterior();
    }
    cout << "NULL\n";
}

ListaDoble::~ListaDoble() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* temporal = actual;
        actual = actual->getSiguiente();
        delete temporal;
    }
}