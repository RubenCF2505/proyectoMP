#include <iostream>
#include <cassert>
#include "Pelicula.h"
#include "Critica.h"
#include "Usuario.h"
#include "Fecha.h"



using namespace std;

int main() {
    Usuario ruben_banano(1,"Rubén","El Banano","ruben@bananos.com",HOMBRE);
    Usuario maria_chuminga(2,"María", "La Chuminga", "maria@chumingos.com",MUJER);

    Pelicula trainspotting(1,"Trainspotting",Fecha(23,9,1996),DRAMA);
    Pelicula poli(2,"Poli de Guardería", Fecha(22,11,1991), COMEDIA);
    Pelicula loca_academia(3,"Loca Academia de Policía", Fecha(2,7,1984),COMEDIA);
    Pelicula super_fumados(4,"Superfumados",Fecha(5,12,2008),ACCION);
    Pelicula nemo(5,"Buscando a Nemo",Fecha(28,11,2003),ANIMACION);
    Pelicula airbag(6,"Airbag",Fecha(20,6,1997),ACCION);
    Pelicula matrix(7,"The Matrix",Fecha(23,6,1999),CIENCIA_FICCION);



    assert(ruben_banano.aniadirMeGusta(&trainspotting)==true);
    assert(maria_chuminga.aniadirMeGusta(&poli)==true);

    assert(ruben_banano.getNumMeGusta()==1);

    assert(ruben_banano.aniadirMeGusta(&trainspotting)==false);
    assert(ruben_banano.getNumMeGusta()==1);

    assert(ruben_banano.aniadirMeGusta(&poli)==true);
    assert(ruben_banano.getNumMeGusta()==2);

    assert(ruben_banano.aniadirNoMeGusta(&loca_academia)==true);
    assert(ruben_banano.getNumNoMeGusta()==1);

    assert(ruben_banano.aniadirMeGusta(&super_fumados)==true);
    assert(ruben_banano.getNumMeGusta()==3);

    assert(ruben_banano.aniadirMeGusta(&nemo)==true);
    assert(ruben_banano.getNumMeGusta()==4);

    assert(ruben_banano.aniadirMeGusta(&airbag)==true);
    assert(ruben_banano.getNumMeGusta()==5);

   
    assert(ruben_banano.aniadirMeGusta(&matrix)==true);
    assert(ruben_banano.getNumMeGusta()==6);
    assert(ruben_banano.getMaxMeGusta()==10);

    cout << "Peliculas preferidas de " << ruben_banano.getNombre() + " " << ruben_banano.getApellidos() << endl;
    
    for (int i=0 ; i < ruben_banano.getNumMeGusta(); i++) {
        cout << ruben_banano.getMeGusta()[i].toString() << endl;
    }
    cout << "----------------------------------------------" << endl;


    assert(ruben_banano.eliminarMeGusta(&nemo)==true);
    assert(ruben_banano.getNumMeGusta()==5);
    assert(ruben_banano.getMaxMeGusta()==10);

    assert(ruben_banano.eliminarMeGusta(&matrix)==true);
    assert(ruben_banano.getNumMeGusta()==4);
    assert(ruben_banano.getMaxMeGusta()==5);


    cout << "Peliculas preferidas de " << ruben_banano.getNombre() + " " << ruben_banano.getApellidos() << endl;
    
    for (int i=0 ; i < ruben_banano.getNumMeGusta(); i++) {
        cout << ruben_banano.getMeGusta()[i].toString() << endl;
    }
    cout << "----------------------------------------------" << endl;

    Critica critica_trainspotting(8.5,"La detención de Rubén El Banano, desata la guerra entre los clanes de la droga de Granada: Los Mindolos, los Chumingos y los Tripolos",&trainspotting);

    ruben_banano.aniadirCritica(&critica_trainspotting);
    assert(ruben_banano.getNumCriticas()==1);
    assert(ruben_banano.getMaxCriticas()==5);







}