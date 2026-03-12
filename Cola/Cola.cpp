#include <iostream>
#include "Cola.hpp"

//**********************************************
// CONSTRUCTORES
//**********************************************

Cola::Cola()
{
    numElem = 0;
    cabeza = nullptr;
    cola = nullptr;
}

//**********************************************

Cola::~Cola()
{
    Vaciar();
}

//**********************************************

Cola::Cola(const Cola& Cola)
{
    numElem = 0;
    cabeza = nullptr;
    cola = nullptr;
    *this = Cola;

}

Cola& Cola::operator=(const Cola& cola)
{
    if (this == &cola) return *this; // handle self assignment
    //assignment operator

    Vaciar();
    Elemento *visitado = cola.cabeza;
    while (visitado != nullptr) {
        Agregar(visitado->valor);
        visitado = visitado->siguiente;
    }

    return *this;
}

//**********************************************
// MÉTODOS DE CLASE
//**********************************************

void Cola::Agregar(int valor)
{
    Elemento *nuevo = new Elemento(valor, nullptr);

    if(EstaVacia()){
        cabeza = nuevo;
        cola = nuevo;
    }else{
        cola->siguiente = nuevo;
        cola = nuevo;
    }
    ++numElem;
}

//**********************************************

void Cola::Eliminar()
{
    if(EstaVacia()){
        throw ColaVacia();
    }
    Elemento *porBorrar = cabeza;
    cabeza = cabeza->siguiente;
    delete porBorrar;
    --numElem;

    if(cabeza == nullptr){
        cola = nullptr;
    }
}

//**********************************************

bool Cola::EstaVacia()
{
    if(cabeza == nullptr){
        return true;
    }

    return false;
}

//**********************************************

void Cola::Vaciar()
{
    while(!EstaVacia()) Eliminar();
}

//**********************************************

int Cola::ObtenerCabeza()
{
    return cabeza->valor;
}

//**********************************************

int Cola::ObtenerCola()
{
    return cola->valor;
}

int Cola::ObtenerNumElem()
{
    return numElem;
}

void Cola::Imprimir()
{
    Elemento *visitado = cabeza;
    std::cout << "Cabeza-> ";

    while(visitado != nullptr){
        std::cout << visitado->valor << ", ";
        visitado = visitado->siguiente;
    }

    if(!EstaVacia()) std::cout << "\b\b <- Inicio";
}

Cola::Elemento::Elemento(int val, Elemento *sig /*=nullptr*/) : valor(val), siguiente(sig){}


//***********************************
// Implementación de la clase ColaVacia
//***********************************

Cola::ColaVacia::ColaVacia() throw() {}

//***********************************

Cola::ColaNoMemoria::ColaNoMemoria() throw(){}

//***********************************

const char *Cola::ColaVacia::what() const throw()
{
    return "La Cola se encuentra vac\241a.";
}

//***********************************

const char *Cola::ColaNoMemoria::what() const throw()
{
    return "No hay memoria disponible.";
}

