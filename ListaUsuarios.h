/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ListaUsuarios.h
 * Author: usuario
 *
 * Created on 18 de mayo de 2025, 19:10
 */

#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H

#include "Usuario.h"
const int MAX_USUARIOS = 1000;

class ListaUsuarios {
    int numUsuarios;
    Usuario * lista[MAX_USUARIOS];

public:
    ListaUsuarios();
    ListaUsuarios(const ListaUsuarios& orig);
    virtual ~ListaUsuarios();

private:

};

#endif /* LISTAUSUARIOS_H */

