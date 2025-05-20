/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Fecha.h
 * Author: usuario
 *
 * Created on 2 de mayo de 2025, 16:34
 */

#ifndef FECHA_H
#define FECHA_H

#include <string>

enum class mesEspecial {
    FEBRERO, ABRIL, JUNIO, SEPTIEMBRE, NOVIEMBRE
};

using namespace std;

class Fecha {
    int dia;
    int mes;
    int anio;
public:
    Fecha(int dia, int mes, int anio);
    Fecha();
    string toString();
    int getAnio();
private:
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void setDia(int dia, int mes,int anio);
    bool esBisiesto(int anio);
};

#endif /* FECHA_H */

