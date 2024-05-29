#pragma once
#ifndef CVIKINGO_H
#define CVIKINGO_H

#include "cDragon.h"//cDragon tiene a cHabilidades, para q no nos pase como en IRI JAJAJ
enum class VformaDeAtaque { nulo = 0, Vpunyo = 1, Varco = 2, Vhacha = 3 };

class cVikingo
{
private:
    string nombre;
    const string apellido;
    string posicion;
    VformaDeAtaque nivel;
    int contadorDragonesTerminados;//Cuenta la cantidad de veces que se ejecut� la funcion "combate" de la clase cHabilidades y gan�
    cHabilidades* habilidades;

public:
    static int contVikingos;

    cVikingo() : apellido("") { //constructor nulo
        this->nombre = "";
        this->posicion = "";
        this->contadorDragonesTerminados = 0;
        this->nivel = VformaDeAtaque::nulo;
        this->habilidades = new cHabilidades(); //me creo un objeto din�mico de habilidades
        contVikingos++;
    }

    ~cVikingo(); //en cpp


    cHabilidades* get_habilidades() {
        return this->habilidades;
    }


    cVikingo(string nombre, string apellido, string posicion, int contadorDragonesTerminados, cHabilidades* habilidades, VformaDeAtaque nivel);

    string to_string();
    void print();
    void set_trabajar(string posicion) {
        this->posicion = posicion;
    }

    string get_trabajar() {
        return this->posicion;
    }

    bool dragonesTerminados(); //true si mat� a m�s de 1 drag�n. false si no mato ninguno
    

    // ACLARACI�N: nuestra idea es que actualizarFormaAtaque sea una sola funci�n, �til tanto para drag�n como para vikingo(deber�a ser virtual y, por lo tanto,
    // cHabilidades ser�a una clase abstracta).Lo vamos a modificar cuando entendamos mejor el tema!!!

    void V_actualizarFormaDeAtaque();

    void AnularVikingo();

    void V_baja();
};

#endif
