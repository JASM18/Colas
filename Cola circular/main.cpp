#include <iostream>
#include "Cola.hpp"
#include "Aleatorio.hpp"

using namespace std;

int main()
{
    Cola<int> colita;

    cout << colita << endl;

    colita.Agregar(1);

    cout << colita << endl;

    colita.Agregar(2);

    cout << colita << endl;

    colita.Agregar(3);

    cout << colita << endl;

    colita.Agregar(4);

    cout << colita << endl;

    colita.Eliminar();

    cout << colita << endl;

    /*
    for(int i = 0 ; i < 100 ; ++i){

        // Cada cierto tiempo al azar (cada 3 vueltas, cada 5 vueltas...) metan un elemento a la cola
        // Al iniciar el ciclo meter un numero al azar entre 1-7
        // Esperar esa cantidad de vueltas para meter un elemento, despues de eso escoger otra vez el umero al azar y meterlo
        //imprimir la vuelta en la que vamos
        //imprimir el numero de vueltas al azar que tenemos q esperar
        //pausa de 1 segundo cada vuelta


        //despues
        //al mismo tiempo generar otro tiempo al azar (puede ser 1-7, 1-10, 5-10, etc)
        //cuando se cumpla esa cantidad de vueltas, eliminar uno de la cola
        //revisar antes si está vacia

        int vuelta = aleatorio(1,7);


    }
    */

    return 0;
}
