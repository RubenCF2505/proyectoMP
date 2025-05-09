/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pelicula.cpp
 * Author: usuario
 * 
 * Created on 2 de mayo de 2025, 16:32
 */

#include <sstream>
#include "Pelicula.h"
using namespace std;

Pelicula::Pelicula(int id, string titulo, Fecha lanzamiento, Genero genero) {
    this->id = id;
    this->titulo = titulo;
    this->fechaLanzamiento = lanzamiento;
    this->genero = genero;
}

Pelicula::Pelicula(const Pelicula& orig) {
    this->id = orig.id;
    this->titulo = orig.titulo;
    this->fechaLanzamiento = orig.fechaLanzamiento;
    this->genero = orig.genero;
}

Pelicula::Pelicula() {
    this->id = -1;
    this->titulo = " ";
    this->fechaLanzamiento = Fecha();
    this->genero = GENERICO;
}



string Pelicula::toString() {
    return "Titulo: " + titulo + " Fecha de lanzamiento: " + fechaLanzamiento.toString() + " Género: " +to_string(genero);
}

