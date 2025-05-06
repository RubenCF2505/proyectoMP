/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Critica.cpp
 * Author: usuario
 * 
 * Created on 2 de mayo de 2025, 16:35
 */

#include "Critica.h"

Critica::Critica(float valoracion, string descripcion, Pelicula * pelicula) {
    this->valoracion = valoracion;
    this->descripcion = descripcion;
    this->pelicula = pelicula;
}

Critica::Critica() {
    this->valoracion = -1;
    this->descripcion = "";
    pelicula = nullptr;
}

Critica::Critica(const Critica& orig) {
}

Critica::~Critica() {
    pelicula=nullptr;
}

