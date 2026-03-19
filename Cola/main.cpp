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

    system("pause");
    system("CLS");

    cout << "=== INICIANDO SIMULACION ===" << endl;
    cout << "Primer elemento en: " << esperaAgregar << " vueltas." << endl;
    cout << "Primera eliminacion en: " << esperaEliminar << " vueltas.\n" << endl;

    srand(time(NULL));

    try{

        for(int i = 0 ; i < 100 ; ++i){

            cout << "==========" << endl;

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
                cout << "[EXITO] se agrego el eleemnto " << i << " a la cola" << endl;

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
