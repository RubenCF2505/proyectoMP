/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Usuariop.h
 * Author: usuario
 *
 * Created on 30 de abril de 2025, 16:02
 */
#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "Pelicula.h"
#include "Critica.h"


using namespace std;

enum Sexo {
    HOMBRE,
    MUJER,
    NO_ESPECIFICA
};

class Usuario {
    int id;
    string nombre;
    string apellidos;
    string email;
    int edad;
    Sexo sexo;
    int maxMeGusta;
    int maxNoMeGusta;
    int maxCriticas;
    int numMeGusta;
    int numNoMeGusta;
    int numCriticas;
    Pelicula ** meGusta;
    Pelicula ** noMeGusta;
    Critica ** criticas;


public:
    Usuario(int id, string nombre, string apellidos, string email, int edad, Sexo sexo);
    Usuario(int id, string nombre, string apellidos, string email, Sexo sexo);

    Usuario(const Usuario& orig);
    virtual ~Usuario();
    int getId();
    string getNombre();
    string getApellidos();
    int getEdad();
    string getEmail();
    Sexo getSexo();
    Usuario();
    int getNumMeGusta();
    int getNumNoMeGusta();

    int getMaxMeGusta();
    int getNumCriticas();
    int getMaxCriticas();



    bool aniadirMeGusta(Pelicula * pelicula);
    bool eliminarMeGusta(Pelicula * pelicula);
    bool aniadirNoMeGusta(Pelicula * pelicula);
    bool eliminarNoMeGusta(Pelicula * pelicula);
    bool aniadirCritica(Critica * critica);
    bool eliminarCritica(Critica * critica);

    void setApellidos(string apellidos);

    void setEdad(int edad);

    void setEmail(string email);

    void setId(int id);

    void setNombre(string nombre);


    Pelicula* getMeGusta();
    void setSexo(Sexo sexo);
private:

    template <typename T>
    void ampliarEspacio(T**& lista, int& limite);
    template <typename T>
    void reducirEspacio(T**& lista, int& limite);
    template <typename T>
    void aniadirLista(T**& Lista, T* objeto, int& limite, int &incremento);
    template <typename T>
    void eliminarLista(T**& Lista, int& limite, int &decremento, int indice);
    template <typename T>
    bool buscarLista(T** Lista, T* objeto, int &limite, int &indice);
    template <typename T>
    bool buscarLista(T** Lista, T* objeto, int &limite);
    template <typename T>
    void borrarMemoria(T**& Lista, int& limite);
};


#endif /* USUARIO_H */

