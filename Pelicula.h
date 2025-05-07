/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pelicula.h
 * Author: usuario
 *
 * Created on 2 de mayo de 2025, 16:32
 */
#ifndef PELICULA_H
#define PELICULA_H

#include "Fecha.h"
#include <iostream>

enum Genero {
    DRAMA,
    COMEDIA, SUSPENSE, CIENCIA_FICCION, ANIMACION, ACCION, GENERICO      
};
using namespace std;

class Pelicula {
    int id;
    string titulo;
    Fecha fechaLanzamiento;
    Genero genero;
public:

    Pelicula(int id, string titulo, Fecha lanzamiento, Genero genero);
    Pelicula();
    Pelicula(const Pelicula& orig);
    string toString();
private:

};

#endif /* PELICULA_H */

