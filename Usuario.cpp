/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Usuario.cpp
 * Author: usuario
 * 
 * Created on 30 de abril de 2025, 16:02
 */

#include "Usuario.h"

Usuario::Usuario(int id, string nombre, string apellidos, string email, int edad, Sexo sexo) {
    this->id = id;
    this->nombre = nombre;
    this->apellidos = apellidos;
    this->email = email;
    this->edad = edad;
    this->sexo = sexo;
    this->numMeGusta = 0;
    this->numNoMeGusta = 0;
    this->numCriticas = 0;

    this->maxCriticas = 5;
    this->maxMeGusta = 5;
    this->maxNoMeGusta = 5;

    meGusta = new Pelicula*[maxMeGusta];
    noMeGusta = new Pelicula*[maxNoMeGusta];
    criticas = new Critica*[maxCriticas];
}

Usuario::Usuario(int id, string nombre, string apellidos, string email, Sexo sexo) {
    this->id = id;
    this->nombre = nombre;
    this->apellidos = apellidos;
    this->email = email;
    this->edad = -1;
    this->sexo = sexo;
    this->numMeGusta = 0;
    this->numNoMeGusta = 0;
    this->numCriticas = 0;

    this->maxCriticas = 5;
    this->maxMeGusta = 5;
    this->maxNoMeGusta = 5;

    meGusta = new Pelicula*[maxMeGusta];
    noMeGusta = new Pelicula*[maxNoMeGusta];
    criticas = new Critica*[maxCriticas];
}

Usuario::Usuario(const Usuario& orig) {

}

Usuario::Usuario(string linea) {

}

Usuario::Usuario() {
    this->id = -1;
    this->nombre = "";
    this->apellidos = "";
    this->email = "";
    this->edad = -1;
    this->sexo = NO_ESPECIFICA;
    numMeGusta, numNoMeGusta, numCriticas = 0;
    maxCriticas, maxMeGusta, maxNoMeGusta = 5;
    meGusta = new Pelicula*[maxMeGusta];
    noMeGusta = new Pelicula*[maxNoMeGusta];
    criticas = new Critica*[maxCriticas];

}

Pelicula** Usuario::getMeGusta() {
    return meGusta;
}

Usuario::~Usuario() {
    borrarMemoria(meGusta, numMeGusta);
    borrarMemoria(noMeGusta, numNoMeGusta);
    borrarMemoria(criticas, numCriticas);
}

int Usuario::getNumMeGusta() {
    return numMeGusta;
}

string Usuario::getApellidos() {
    return apellidos;
}

string Usuario::getNombre() {
    return nombre;
}

int Usuario::getNumNoMeGusta() {
    return numNoMeGusta;
}

int Usuario::getMaxMeGusta() {
    return maxMeGusta;
}

int Usuario::getNumCriticas() {
    return numCriticas;
}

int Usuario::getMaxCriticas() {
    return maxCriticas;
}

bool Usuario::aniadirMeGusta(Pelicula* pelicula) {
    bool encontrado = buscarLista(meGusta, pelicula, numMeGusta);

    if (!encontrado) {
        aniadirLista(meGusta, pelicula, maxMeGusta, numMeGusta);
    }
    return !encontrado;
}

bool Usuario::eliminarMeGusta(Pelicula* pelicula) {
    int aux = -1;
    bool encontrado = buscarLista(meGusta, pelicula, numMeGusta, aux);


    if (encontrado) {
        eliminarLista(meGusta, numMeGusta, maxMeGusta, aux);
    }

    return encontrado;
}

bool Usuario::aniadirCritica(Critica* critica) {
    bool encontrado = buscarLista(criticas, critica, numCriticas);

    if (!encontrado) {
        aniadirLista(criticas, critica, maxCriticas, numCriticas);
    }
    return !encontrado;

}

bool Usuario::eliminarCritica(Critica* critica) {
    int aux = -1;
    bool encontrado = buscarLista(criticas, critica, numCriticas, aux);

    if (encontrado) {
        eliminarLista(criticas, numCriticas, maxCriticas, aux);
    }
    return encontrado;
}

bool Usuario::aniadirNoMeGusta(Pelicula* pelicula) {
    bool encontrado = buscarLista(noMeGusta, pelicula, numNoMeGusta);

    if (!encontrado) {
        aniadirLista(noMeGusta, pelicula, maxNoMeGusta, numNoMeGusta);
    }
    return !encontrado;
}

bool Usuario::eliminarNoMeGusta(Pelicula* pelicula) {
    int aux = -1;
    bool encontrado = buscarLista(noMeGusta, pelicula, numNoMeGusta, aux);

    if (encontrado) {
        eliminarLista(noMeGusta, numNoMeGusta, maxNoMeGusta, aux);
    }
    return encontrado;
}

/*FUNCIONES GENERICAS*/
