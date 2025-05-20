/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ListaPeliculas.h
 * Author: usuario
 *
 * Created on 13 de mayo de 2025, 11:38
 */

#ifndef LISTAPELICULAS_H
#define LISTAPELICULAS_H


#include <ostream>
#include "Pelicula.h"
#include "Util.h"
using namespace std;

const int TAM_BLOQUE = 10;

struct Bloque {
    Pelicula * lista[TAM_BLOQUE];
    int usados;
    Bloque * siguiente;
};

class ListaPeliculas {
    Bloque * bloquePrimer;
    Bloque * bloqueUltimo;
public:
    ListaPeliculas(string nombreFichero);
    void listado();
    bool buscarPeliculas(string bTitulo, int anioIni, int anioFin, Pelicula ** resultado, int maxResultados, int &numResultados);
    bool aniadirPelicula(Pelicula * pelicula);
private:
    bool buscarPorCondicion(Pelicula ** resultado, int maxResultados, int &numResultados, string bTitulo = "", int anioIni = -1, int anioFin = -1);
    Pelicula* operator[](int i) const;
    void leerFichero(ifstream& fichero);
    Pelicula * guardarDatos(string & linea);
    void filtrar(string& linea, string*& lista, int& cantidad, char filtro);
    Genero stringToGenero(const string& palabra);
    Bloque * buscarUltimo(Bloque *bloquePrimer);
};
#endif /* LISTAPELICULAS_H */

