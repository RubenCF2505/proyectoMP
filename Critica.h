/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Critica.h
 * Author: usuario
 *
 * Created on 2 de mayo de 2025, 16:35
 */

#ifndef CRITICA_H
#define CRITICA_H
#include "Pelicula.h"
#include <string>
using namespace std;

class Critica {
    float valoracion;
    string descripcion;
    Pelicula * pelicula;
public:
    Critica(float valoracion, string descripcion, Pelicula * pelicula);
    Critica();
    Critica(const Critica& orig);
private:

};

#endif /* CRITICA_H */

