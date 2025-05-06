/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Fecha.cpp
 * Author: usuario
 * 
 * Created on 2 de mayo de" 2025", 16:34
 */
#include <ctime>
#include "Fecha.h"
#include <bits/stdc++.h>
struct tm datetime;

Fecha::Fecha(int dia, int mes, int anio) {
    setAnio(anio);
    setMes(mes);
    setDia(dia, mes, anio);
}

Fecha::Fecha() {
    this->dia = 25;
    this->mes = 5;
    this->anio = 2001;
}

Fecha::~Fecha() {
}

void Fecha::setAnio(int anio) {
    anio > 0 ? this->anio = anio : this->anio = -1;
}

bool Fecha::esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

void Fecha::setDia(int dia, int mes, int anio) {
    //los meses distintos de 31 son:
    int meses[]{2, 4, 6, 9, 11};
    int maxDia = 31;
    for (int i = 0; i< sizeof (meses); i++) {
        if (mes == meses[i]) {
            if (mes == 2) {
                maxDia = esBisiesto(anio) ? 29 : 28;
            } else
                maxDia = 30;
        }

    }
    dia > 0 && dia <= maxDia ? this->dia = dia : this->dia = -1;

}

void Fecha::setMes(int mes) {
    mes > 0 && mes <= 12 ? this->mes = mes : this->mes = -1;
}

string Fecha::toString() {
    return to_string(dia) + " / " + to_string(mes) + " / " + to_string(anio);
}



