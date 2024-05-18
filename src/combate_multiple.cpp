#include "combate_multiple.hpp"
#include <iostream>

combate_multiple::combate_multiple() {
    combates_maximos = 6;
}

void combate_multiple::agragar_combate(combate nuevo_combate) {
    if (cola_combates.tamanio() < combates_maximos) {
        cola_combates.alta(nuevo_combate);
    } else {
        std::cerr << "No se pueden agregar más de seis combates." << std::endl;
    }
}

size_t combate_multiple::pelear() {
    if (cola_combates.vacio()) {
        return 0;
    } else {
        return pelear_recursivo();
    }
}

size_t combate_multiple::pelear_recursivo() {
    if (cola_combates.vacio()) {
        return 0;
    } else {
        combate combate_actual = cola_combates.primero();
        std::cout << "Resolviendo combate: \n" << combate_actual << std::endl;
        size_t poder_gastado_combate_actual = combate_actual.obtener_poder_gastado();
        cola_combates.baja();
        return poder_gastado_combate_actual + pelear_recursivo();
    }
}



