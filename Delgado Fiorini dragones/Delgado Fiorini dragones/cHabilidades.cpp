#include "cHabilidades.h"

cHabilidades::cHabilidades(const cHabilidades& otrasHabilidades) {
    this->ataque = otrasHabilidades.ataque;
    this->defensa = otrasHabilidades.defensa;
    this->salud = otrasHabilidades.salud;
}

cHabilidades::cHabilidades()
{//constructor x defecto
    this->ataque = 0;//no tiene habilidades 
    this->defensa = 0;
    this->salud = 100;//la salud al maximo!
}

cHabilidades::cHabilidades(unsigned int ataque, unsigned int defensa, unsigned int salud) {
    this->ataque = ataque;
    this->defensa = defensa;
    this->salud = salud;
}

cHabilidades::~cHabilidades()
{
}

void cHabilidades::entrenar(combate habilidadaAentrenar) {
    if (habilidadaAentrenar == combate::defensa) {//quiero entrenar defensa
        if (defensa == 100) {//si la defensa esta al maximo
            throw new exception("Error: la defensa esta al maximo");// el try catch se hace en el main
        }
        else if (defensa + 3 > 100) {
            defensa = 100; //llego al maximo
        }
        else {
            defensa = defensa + 3;//aumento la defensa
        }
    }
    else {
        if (ataque == 100) {
            throw new exception("Error: el ataque esta al maximo"); //el try catch se hace en el main
        }
        else if (ataque + 3 > 100) {
            ataque = 100; //llego al maximo
        }
        else {
            ataque = ataque + 3;//aumento la defensa
        }
    }

}

void cHabilidades::combate(cHabilidades h_dragon, cHabilidades hab_vikingo) {// hacelo recibir la referencia sino vas a modificar la copia
    if (h_dragon.defensa > hab_vikingo.ataque && h_dragon.ataque > hab_vikingo.defensa) {
        hab_vikingo.salud = hab_vikingo.salud - 50;
    }
    else if ((h_dragon.defensa < hab_vikingo.ataque && h_dragon.ataque < hab_vikingo.defensa)) {
        h_dragon.salud = h_dragon.salud - 50;
    }
    else {
        h_dragon.salud = h_dragon.salud - 25;
        hab_vikingo.salud = hab_vikingo.salud - 25;
    }
    if (hab_vikingo.salud <= 0) {
        throw new exception("Error: muerte de vikingo"); //el try catch se hace en el main. Se llama en el main a la funcion "baja"
    }
    if (hab_vikingo.salud <= 0) {
        throw new exception("Error: muerte de dragon");
    }

}


void cHabilidades::curandero() {// aumenta +30 la salud del vikingo/dragón.
    this->salud = salud + 30;
}
