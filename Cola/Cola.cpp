#include <iostream>
#include "Cola.hpp"

//**********************************************
// CONSTRUCTORES
//**********************************************

Cola::Cola()
{
    numElem = 0;
    cabeza = nullptr;
    ultimo = nullptr;
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
    ultimo = nullptr;
    *this = Cola;

}

Cola& Cola::operator=(const Cola& cola)
{
    if (this == &cola) return *this; // handle self assignment
    //assignment operator

    Vaciar();

    if(cola.cabeza == nullptr){
        return *this;
    }

    Elemento *visitado = cola.cabeza;

    while(visitado != nullptr){
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
    try{
        Elemento *nuevo = new Elemento(valor, nullptr);

        if(EstaVacia()){
            cabeza = nuevo;
            ultimo = nuevo;
        }else{
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }

        ++numElem;
    }catch(const std::bad_alloc&){
        throw ColaNoMemoria();
    }
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
        ultimo = nullptr;
    }
}

//**********************************************

bool Cola::EstaVacia() const
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

int Cola::ObtenerCabeza() const
{
    if(EstaVacia()){
        throw ColaVacia();
    }
    return cabeza->valor;
}

//**********************************************

int Cola::ObtenerCola() const
{
    if(EstaVacia()){
        throw ColaVacia();
    }

    return ultimo->valor;
}

//**********************************************

int Cola::ObtenerNumElem() const
{
    return numElem;
}

//***********************************

void Cola::Imprimir() const
{
    Elemento *visitado = cabeza;
    std::cout << "Cabeza-> ";

    while(visitado != nullptr){
        std::cout << visitado->valor << ", ";
        visitado = visitado->siguiente;
    }

    if(!EstaVacia()) std::cout << "\b\b <- Ultimo";
}

//***********************************

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

//***********************************

std::ostream & operator<<(std::ostream & salida, const Cola &cola)
{
    cola.Imprimir();
    return salida;
}

