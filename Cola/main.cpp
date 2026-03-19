#include <iostream>
#include <thread>
#include <chrono>

#include "Cola.hpp"
#include "Aleatorio.hpp"

using namespace std;

int main()
{
    int numeritoRandom = aleatorio(1,7);

    Cola colita;

    cout << colita << endl;

    for(int i = 0 ; i < 7 ; ++i){
        colita.Agregar(i);
        cout << colita << endl;
    }

    cout << "\nEliminando un elemento..." << endl;
    colita.Eliminar();
    cout << colita << endl;

    cout << "Eliminando un elemento..." << endl;
    colita.Eliminar();
    cout << colita << endl;

    cout << "\nCabeza de la cola: " << colita.ObtenerCabeza() << endl;

    cout << "Ultimo en la cola: " << colita.ObtenerCola() << endl;

    cout << "Numero de elementos: " << colita.ObtenerNumElem() << endl;

    colita.Vaciar();

    int esperaAgregar = aleatorio(1, 7);
    int esperaEliminar = aleatorio(1, 10);


    cout << "=== INICIANDO SIMULACION ===" << endl;
    cout << "Primer elemento en: " << esperaAgregar << " vueltas." << endl;
    cout << "Primera eliminacion en: " << esperaEliminar << " vueltas.\n" << endl;

    srand(time(NULL));

    try{

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


            cout << "\n==========" << endl;

            // a) Imprima el número de vuelta en que va
            cout << "Número de vuelta: " << i << endl;

            // b) Haga una pausa temporal
            std::this_thread::sleep_for(std::chrono::seconds(1));

            // c) Si ya se cumplió el número de vueltas que debe esperar para agregar:
            // a) Agregue un elemento a la cola
            // b) Genere otro número al azar entre 1 y 7 para agregar otro elemento en la cola
            if (esperaAgregar > 0) esperaAgregar--;
            if (esperaEliminar > 0) esperaEliminar--;


            if(esperaAgregar == 0){

                colita.Agregar(i);
                cout << "[EXIGO] se agrego el eleemnto " << i << " a la cola" << endl;

                esperaAgregar = aleatorio(1, 7);
                cout << "Siguiente elemento en: " << esperaAgregar << " vueltas" << endl;
            }

            if(esperaEliminar == 0){

                if(!colita.EstaVacia()){

                    int eliminado = colita.ObtenerCabeza();
                    colita.Eliminar();

                    cout << "Se ELIMINO el elemento " << eliminado << " de la cola" << endl;
                    esperaEliminar = aleatorio(5, 10);

                    cout << "Siguiente eliminacion en: " << esperaEliminar << " vueltas" << endl;

                }else{
                    cout << "ESPERA!... la cola esta vacia. Esperando..." << endl;
                }

            }

            cout << "Estado actual: " << colita << endl << endl;

        }

    }catch(const char* mensaje){
        cerr << "Error: " << mensaje << endl;
    }catch(const exception &error){
        cerr << "Error: " << error.what();
    }catch(...){
        cerr << "El programa tuvo un error inesperado." << endl;
    }

    return 0;
}
