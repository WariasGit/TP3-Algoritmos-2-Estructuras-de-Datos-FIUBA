#ifndef AYED_TP3_1C2024_COMBATE_MULTIPLE_HPP
#define AYED_TP3_1C2024_COMBATE_MULTIPLE_HPP

#include "cola.hpp"
#include "combate.hpp"

class combate_multiple {
private:
    cola<combate> cola_combates;
    size_t combates_maximos;

public:
    /*
     * Pre:
     * Post: Constructor.
     */
    combate_multiple();

    /*
     * Pre:
     * Post: Agrega el nuevo combate a la cola de combates.
     */
    void agragar_combate(combate nuevo_combate);

    /*
     * Pre:
     * Post: Si la cola de combates está vacía, devuelve 0.
     *       Si la cola tiene combates, llama al método pelear_recursivo() para resolverlos y obtener la cantidad total de poder gastado.
     */
    size_t pelear();

    /*
     * Pre:
     * Post: Si la cola tiene combates, extrae el combate actual, muestra su información, calcula el poder gastado, elimina el combate de la cola y realiza una llamada recursiva para resolver los combates restantes.
     *       Este metodo utiliza una recursividad de cola y también está involucrada en recursividad múltiple debido a la llamada indirecta desde el metodo pelear().
     *       Caso base: Si la cola de combates está vacía, devuelve 0.
     */
    size_t pelear_recursivo();
};

#endif