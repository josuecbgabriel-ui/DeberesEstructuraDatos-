#include <iostream>
#include "ListaDobleCircular.h"

using namespace std;

int main() {
    ListaDobleCircular miLista;

    cout << "=== INSERTANDO DATOS ===" << endl;
    miLista.insertar("Carlos");
    miLista.insertar("Ana");
    miLista.insertar("Mateo");
    miLista.insertar("Sofia");

    cout << "\n=== MOSTRAR LISTA ORIGINAL ===" << endl;
    miLista.mostrar();

    cout << "\n=== PRUEBA DE BUSQUEDA ===" << endl;
    miLista.buscar("Ana");
    miLista.buscar("Luis");

    cout << "\n=== PRUEBA DE ELIMINACION ===" << endl;
    miLista.eliminar("Ana");

    cout << "\n=== LISTA FINAL ===" << endl;
    miLista.mostrar();

    cout << "\n=== PRUEBA DE INVERSION (DEBER 1) ===" << endl;
    miLista.invertir();
    miLista.mostrar();

    cout << "\n=== PRUEBA DE OBTENER EN POSICION ===" << endl;
    cout << "Dato en la posicion 1: " << miLista.obtenerEnPosicion(1) << endl;
    cout << "Dato en la posicion 10: " << miLista.obtenerEnPosicion(10) << endl;

    return 0;
}