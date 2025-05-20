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
#include "Util.h"


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
    Usuario(string linea);
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


    Pelicula** getMeGusta();
    void setSexo(Sexo sexo);
private:

    
};


#endif /* USUARIO_H */

