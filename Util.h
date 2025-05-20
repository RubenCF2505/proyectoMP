/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Util.h
 * Author: usuario
 *
 * Created on 20 de mayo de 2025, 11:38
 */

#ifndef UTIL_H
#define UTIL_H

class Util {
public:
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
    template <typename T>
    void ampliarEspacio(T*& lista, int& limite);
    template <typename T>
    void reducirEspacio(T*& lista, int& limite);

};
#include "Util.tpp"

#endif /* UTIL_H */

