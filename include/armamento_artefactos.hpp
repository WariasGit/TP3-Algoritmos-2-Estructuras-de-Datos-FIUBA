#ifndef AYED_TP3_1C2024_ARMAMENTO_ARTEFACTOS_HPP
#define AYED_TP3_1C2024_ARMAMENTO_ARTEFACTOS_HPP

#include "lista_circular.hpp"
#include "artefacto.hpp"

class armamento_artefactos {
private:
    lista_circular<artefacto> lista_artefactos;
    size_t maximos_artefactos;
    int id_armamento;
    std::string nombre_armamento;

public:
    /*
     * Pre:
     * Post: Construye un armamento vacio.
     */
    armamento_artefactos();

    /*
     * Pre: El formato del archivo debe ser correcto.
     * Post: Construye un armamento a partir de un archivo que contiene artefactos.
     */
    armamento_artefactos(std::string path_archivo);

    /*
     * Pre:
     * Post:
     */
    void agregar_artefacto(artefacto artefacto_a_agregar);

    /*
     * Pre:
     * Post: Muestra por pantalla el artefacto actual.
     */
    void mostrar_artefacto_actual();

    /*
     * Pre:
     * Post: Muestra por pantalla el artefacto siguiente.
     */
    void mostrar_artefacto_siguiente();

    /*
     * Pre:
     * Post: Muestra por pantalla el artefacto anterior.
     */
    void mostrar_artefacto_anterior();

    /*
     * Pre:
     * Post: Muestra por pantalla todos los artefactos.
     */
    void mostrar_artefactos();

    /*
     * Pre:
     * Post: Quita el artefacto actual del armamento.
     */
    void quitar_artefacto();

    /*
     * Pre:
     * Post: Guarda el armamento actual y lo exporta a un archivo UUID-NOMBRE_ARMAMENTO.csv con el formato ID,SET,TIPO,NIVEL,RAREZA.
     */
    void exportar_armamento();

    /*
     * Pre:
     * Post: Asigna los datos recibidos por parametro.
     */
    void asignar_id_nombre_armamento(int nuevo_id, const std::string& nuevo_nombre);

    /*
     * Pre:
     * Post:
     */
    std::string crear_nombre_archivo();

};

#endif