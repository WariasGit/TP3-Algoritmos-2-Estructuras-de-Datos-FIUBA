#ifndef AYED_TP3_1C2024_COLA_HPP
#define AYED_TP3_1C2024_COLA_HPP

#include <exception>
#include "nodo.hpp"

class cola_exception : public std::exception {
    // Excepción especifica y exclusiva para errores dentro de la cola.
    // Usar de la forma "throw cola_exception();" cuando una precondición no se cumple.

    // Ejemplo:
    //     if (condición_de_error) {
    //         throw cola_exception();
    //     }
};

template<typename T>
class cola {
private:
    nodo<T>* primer_nodo;
    nodo<T>* ultimo_nodo;
    size_t cantidad_datos;
public:
    /*
    * Pre:
    * Post: Construye una cola vacia. Primer_nodo y ultimo_nodo apuntan a a nulo.
    * */
    cola();

    // Pre: -
    // Post: Agrega el dato al final de la cola.
    void alta(T dato);

    // Pre: La cola no puede estar vacía.
    // Post: Devuelve el primer dato de la cola.
    T primero();

    // Pre: La cola no puede estar vacía.
    // Post: Elimina y devuelve el primer dato de la cola.
    T baja();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la cola.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la cola esta vacía.
    bool vacio();

    // El constructor de copia está deshabilitado.
    cola(const cola& c) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const cola& c) = delete;

    /*
    * Pre:
    * Post: Libera todos los recursos de la cola.
    * */
    ~cola();
};

template<typename T>
cola<T>::cola() {
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
    cantidad_datos = 0;
}

template<typename T>
void cola<T>::alta(T dato) {
    nodo<T>* nuevo_nodo = new nodo<T>(dato);
    if (this->vacio()){
        primer_nodo = nuevo_nodo;
    }
    else{
        ultimo_nodo->siguiente = nuevo_nodo;
    }
    ultimo_nodo = nuevo_nodo;
    cantidad_datos ++;
}

template<typename T>
T cola<T>::primero() {
    if (this->vacio()){
        throw cola_exception();
    }
    else {
        return primer_nodo->dato;
    }
}

template<typename T>
T cola<T>::baja() {
    if (this->vacio()){
        throw cola_exception();
    }
    else{
        nodo<T>* nodo_auxiliar = primer_nodo;
        T dato_a_eliminar = nodo_auxiliar->dato;
        if (this->tamanio() == 1){
            primer_nodo = nullptr;
            ultimo_nodo = nullptr;
        }
        else{
            primer_nodo = nodo_auxiliar->siguiente;
        }
        delete nodo_auxiliar;
        cantidad_datos --;
        return dato_a_eliminar;
    }
}

template<typename T>
size_t cola<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool cola<T>::vacio() {
    return cantidad_datos == 0;
}

template<typename T>
cola<T>::~cola() {
    while (!vacio()){
        baja();
    }
}

#endif