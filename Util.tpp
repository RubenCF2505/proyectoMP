

#include "Util.h"

template<typename T>
void aniadirLista(T**& Lista, T* objeto, int & limite, int &incremento) {
    if (incremento == limite) {
        ampliarEspacio(Lista, limite);
    }
    Lista[incremento] = objeto;
    incremento++;
}

template<typename T>
bool buscarLista(T** Lista, T* objeto, int &limite) {
    bool encontrado = false;
    for (int i = 0; i < limite; i++) {
        if (Lista[i] == objeto && encontrado == false) {
            encontrado = true;
        }
    }
    return encontrado;
}

template<typename T>
bool buscarLista(T** Lista, T* objeto, int &limite, int &indice) {
    indice = -1;
    bool encontrado = false;
    for (int i = 0; i < limite; i++) {
        if (Lista[i] == objeto && encontrado == false) {
            encontrado = true;
            indice = i;
        }
    }
    return encontrado;
}

template<typename T>
void eliminarLista(T**& Lista, int& decremento, int& limite, int indice) {
    Lista[indice] = nullptr;

    for (int i = indice; i < decremento - 1; i++) {
        Lista[i] = Lista[i + 1];
    }

    Lista[decremento - 1] = nullptr;

    decremento--;

    if (decremento < limite / 2) {
        reducirEspacio(Lista, limite);
    }
}

template<typename T>
void borrarMemoria(T**& Lista, int& limite) {
    for (int i = 0; i < limite; i++) {
        if (Lista[i] != nullptr) {
            Lista[i] = nullptr;
        }
    }
    Lista = nullptr;
    limite = 0;
}

template <typename T>
void ampliarEspacio(T**& lista, int& limite) {
    int nuevoLimite = limite * 2;
    T** aux = new T*[nuevoLimite];
    for (int i = 0; i < nuevoLimite; i++) {
        aux[i] = lista[i];
    }
    delete [] lista;
    lista = aux;
    limite = nuevoLimite;
}

template <typename T>
void reducirEspacio(T**& lista, int& limite) {
    int nuevoLimite = limite / 2;
    T** aux = new T*[nuevoLimite];
    for (int i = 0; i < nuevoLimite; i++) {
        aux[i] = lista[i];
    }
    delete[] lista;
    lista = aux;
    limite = nuevoLimite;
}
template <typename T>
void ampliarEspacio(T*& lista, int& limite) {
    T* aux = new T[limite + 1];
    for (int i = 0; i < limite; i++) {

        aux[i] = lista[i];
    }
    delete [] lista;
    lista = aux;
    limite++;
}

template <typename T>
void reducirEspacio(T*& lista, int& limite) {
    int nuevoLimite = limite / 2;
    T** aux = new T*[nuevoLimite];
    for (int i = 0; i < nuevoLimite; i++) {
        aux[i] = lista[i];
    }
    delete[] lista;
    lista = aux;
    limite = nuevoLimite;
}
