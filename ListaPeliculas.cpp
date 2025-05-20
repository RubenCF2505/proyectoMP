/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ListaPeliculas.cpp
 * Author: usuario
 * 
 * Created on 13 de mayo de 2025, 11:38
 */

#include <ios>
#include <fstream>

using namespace std;
#include <fstream>
#include <sstream>
#include <string>
#include "ListaPeliculas.h"
#include <cstring>
#include "Util.h"
using namespace std;

string toLower(const string& palabra) {
    string minusculas = "";
    for (char c : palabra) {
        minusculas += tolower(c);
    }
    return minusculas;
}

string toUpper(const string& palabra) {
    string minusculas = "";
    for (char c : palabra) {
        minusculas += toupper(c);
    }
    return minusculas;
}

ListaPeliculas::ListaPeliculas(string nombreFichero) {
    bloquePrimer = nullptr;
    ifstream fichero(nombreFichero);
    if (fichero.is_open()) {
        leerFichero(fichero);
        fichero.close();
    }
}

void ListaPeliculas::leerFichero(ifstream& fichero) {
    string fila;
    while (getline(fichero, fila)) {
        aniadirPelicula(guardarDatos(fila));
    }
}

Pelicula * ListaPeliculas::guardarDatos(string& linea) {
    string* lista = nullptr;
    int cantidad = -1;
    if (linea != "")filtrar(linea, lista, cantidad, ';');

    string* listaFecha = nullptr;
    int cantidad2 = -1;
    filtrar(lista[2], listaFecha, cantidad2, '/');

    Fecha fecha(stoi(listaFecha[0]), stoi(listaFecha[1]), stoi(listaFecha[2]));
    Pelicula * pelicula = new Pelicula(stoi(lista[0]), lista[1], fecha, stringToGenero(lista[3]));

    delete[] listaFecha;
    delete[] lista;

    return pelicula;
}

Genero ListaPeliculas::stringToGenero(const string& texto) {
    Genero resultado = GENERICO;
    if (toUpper(texto) == "DRAMA") resultado = DRAMA;
    else if (toUpper(texto) == "COMEDIA")resultado = COMEDIA;
    else if (toUpper(texto) == "SUSPENSE")resultado = SUSPENSE;
    else if (toUpper(texto) == "CIENCIA FICCION")resultado = CIENCIA_FICCION;
    else if (toUpper(texto) == "ANIMACION")resultado = ANIMACION;
    else if (toUpper(texto) == "ACCION")resultado = ACCION;
    return resultado;
}

bool ListaPeliculas::buscarPeliculas(string bTitulo, int anioIni, int anioFin, Pelicula** resultado, int maxResultados, int& numResultados) {
    Bloque* actual = bloquePrimer;
    numResultados = 0;
    bool encontrado = false;

    while (actual != nullptr) {
        for (int i = 0; i < actual->usados; i++) {
            Pelicula* peli = actual->lista[i];
            if (peli == nullptr);

            bool coincide = true;


            int anio = peli->getFechaLanzamiento().getAnio();
            if (anioIni != -1 && anioFin != -1) {
                coincide = coincide && (anio >= anioIni && anio <= anioFin);
            } else if (anioIni != -1) {
                coincide = coincide && (anio == anioIni);
            }

            if (!bTitulo.empty()) {
                string tituloMinus = toLower(peli->getTitulo());
                string busquedaMinus = toLower(bTitulo);
                coincide = coincide && (tituloMinus.find(busquedaMinus) != string::npos);
            }

            if (coincide && numResultados < maxResultados && !buscarLista(resultado, peli, numResultados)) {
                resultado[numResultados++] = peli;
                encontrado = true;
            }
        }

        actual = actual->siguiente;
    }

    return encontrado;
}

bool ListaPeliculas::aniadirPelicula(Pelicula* pelicula) {
    if (bloquePrimer == nullptr) {
        bloquePrimer = new Bloque;
        bloquePrimer->usados = 0;
        bloquePrimer->siguiente = nullptr;
        bloqueUltimo = bloquePrimer;
    }

    if (bloqueUltimo->usados == TAM_BLOQUE) {
        Bloque* nuevo = new Bloque;
        nuevo->usados = 0;
        nuevo->siguiente = nullptr;
        bloqueUltimo->siguiente = nuevo;
        bloqueUltimo = nuevo;
    }

    bloqueUltimo->lista[bloqueUltimo->usados++] = pelicula;
    return true;
}

void ListaPeliculas::listado() {
    Bloque* actual = bloquePrimer;
    while (actual != nullptr) {
        for (int i = 0; i < actual->usados; i++) {
            cout << actual->lista[i]->toString() << "\n";
        }
        actual = actual->siguiente;
    }
}

Pelicula* ListaPeliculas::operator[](int i) const {
    Bloque* actual = bloquePrimer;
    Pelicula* resultado = nullptr;

    while (actual != nullptr && resultado == nullptr) {
        if (i < actual->usados) {
            resultado = actual->lista[i];
        } else {

            i -= actual->usados;
            actual = actual->siguiente;
        }
    }

    return resultado;
}

void ListaPeliculas::filtrar(string& linea, string*& lista, int& cantidad, char filtro) {
    cantidad = 0;
    lista = nullptr;

    int inicio = 0;
    int posicion = linea.find(filtro);

    while (posicion != string::npos) {
        string fragmento = linea.substr(inicio, posicion - inicio);
        ampliarEspacio(lista, cantidad);
        lista[cantidad - 1] = fragmento;

        inicio = posicion + 1;
        posicion = linea.find(filtro, inicio);
    }

    string fragmentoFinal = linea.substr(inicio);
    if (!fragmentoFinal.empty()) {
        ampliarEspacio(lista, cantidad);
        lista[cantidad - 1] = fragmentoFinal;
    }
}

Bloque* ListaPeliculas::buscarUltimo(Bloque* bloquePrimer) {

    Bloque* bloqueActual = bloquePrimer;
    while (bloqueActual->siguiente != nullptr) {

        bloqueActual = bloqueActual->siguiente;
    }
    return bloqueActual;
}







