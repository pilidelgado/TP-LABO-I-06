#pragma once

#ifndef CJINETE_H
#define CJINETE_H

#include "cDragon.h"

//defino mi enum:
enum class resultado { noAsistio = 0, aprobado = 4, desaprobado = 3, primero = 10, ultimo = 10 };//por entrenamiento con Bocon

class cJinete
{
private:
    string nombre;
    string apellido;
    string apodo;
    string fecha_nac;
    string caracteristicaFisica;//s�lo una, la que le da el apodo a la persona.
    cDragon* MiDragon; //por relaci�n
    resultado result;

public:
    cJinete();

    ~cJinete();

    tm convertirFecha();
   


    cJinete(string nombre, string apellido, string apodo, string fecha_nac,
        string caracteristicaFisica, cDragon* MiDragon, resultado result);

    void IncorporarDragon(cDragon* nuevoDragon);

    void entrenarDragon(combate habilidadAEntrenar); 
    //accedo a mi dragon (objeto dinamico) para, a su vez, acceder a sus habilidades (otro objeto din�mico de �l). Dentro de habilidades, llamo al m�todo entrenar

    void curarDragon();

    string to_string(); 
    void print();
};
#endif
