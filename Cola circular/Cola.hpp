#ifndef COLA_HPP
#define COLA_HPP

#include <exception>


template <typename T>
class Cola {

public:
    /** Default constructor */
    Cola();

    /** Default destructor */
    ~Cola();

    /** Constructor de copias
     *  \param La cola que se desea copiar
     */
    Cola(const Cola& cola);

    /** Operador de asignación
     *  \param La cola que se desea copiar
     *  \return Una referencia a this
     */
    Cola& operator=(const Cola& cola);


    void Agregar(T valor);

    void Eliminar();

    T ObtenerCabeza() const;

    T ObtenerCola() const;

    int ObtenerNumElem() const;

    bool EstaVacia() const;

    void Vaciar();

    void Imprimir() const;

    class ColaVacia : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n PilaVacia.
         */
        ColaVacia() throw();

        /** \brief Devuelve una descripci&oacute;n del error al intentar operar con una pila vac&iacute;a.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

    class ColaNoMemoria : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n PilaNoMemoria.
         */
        ColaNoMemoria() throw();

        /** \brief Devuelve una descripci&oacute;n del error cuando no haya memoria disponible.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

private:
    int numElem; //!< Member variable "numElem"

    struct Elemento{
        T valor;
        Elemento *siguiente;
        Elemento(T val, Elemento *sig); // Constructor de Elemento
    };

    Elemento *ultimo;
};

#include "Cola.tpp"

#endif // COLA_HPP
