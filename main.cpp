#include <iostream>
#include "armamento_artefactos.hpp"
#include "combate_multiple.hpp"

/*
 * Pre:
 * Post: Muestra las opciones al usuario.
 */
void mostrar_menu();

/*
 * Pre:
 * Post: Prueba los diferentes metodos de la clase armamento_artefactos.
 */
void probar_armamento_artefactos();

/*
 * Pre:
 * Post: Prueba los diferentes metodos de la clase combates_multiples.
 */
void probar_combates_multiples();

int main() {
    int opcion;
    bool salir = false;
    do {
        mostrar_menu();
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        switch (opcion) {
            case 1:
                probar_armamento_artefactos();
                break;
            case 2:
                probar_combates_multiples();
                break;
            case 3:
                std::cout << "Saliendo del programa..." << std::endl;
                salir = true;
                break;
            default:
                std::cout << "Opción no válida. Por favor, seleccione una opción válida." << std::endl;
        }
    } while (!salir);

    return 0;
}





void mostrar_menu() {
    std::cout << "Este es un menú de prueba. Vamos a probar el funcionamiento de las clases Armamento Artefactos y Combates Múltiples." << std::endl;
    std::cout << "1. Testear Armamento Artefactos" << std::endl;
    std::cout << "2. Testear Combates Múltiples" << std::endl;
    std::cout << "3. Salir" << std::endl;
}

void probar_armamento_artefactos() {
    std::string path_archivo = "armamento_para_importar_prueba.csv";
    armamento_artefactos armamento(path_archivo);
    int id;
    std::string nombre;
    std::cout << "Es una prueba, este campo debe ser un numero entero. Ingrese el UUID del usuario: ";
    std::cin >> id;
    std::cout << "Es una prueba, este campo debe ser una palabra sin espacios. Ingrese el nombre del armamento: ";
    std::cin >> nombre;
    armamento.asignar_id_nombre_armamento(id,nombre);

    std::cout << "Artefacto actual:\n";
    armamento.mostrar_artefacto_actual();

    for (int i = 0; i <6; i++){
        std::cout << "\nSiguiente artefacto:\n";
        armamento.mostrar_artefacto_siguiente();
    }

    for (int i = 0; i <6; i++){
        std::cout << "\nAnterior artefacto:\n";
        armamento.mostrar_artefacto_anterior();
    }

    std::cout << "\nTodos los artefactos:\n";
    armamento.mostrar_artefactos();

    armamento.quitar_artefacto();

    std::cout << "\nArtefactos después de quitar uno:\n";
    armamento.mostrar_artefactos();

    armamento.exportar_armamento();
}

void probar_combates_multiples() {
    std::string descripcion_1 = "Defensa del Dominio de la Llama: En este combate, los jugadores deben proteger un dominio de las fuerzas enemigas que intentan invadirlo. Enemigos variados, como hilichurls y mitichurls, atacarán en oleadas, y los jugadores deben derrotarlos para mantener la defensa.";
    size_t enemigos_1 = 78;
    size_t gastos_1 = 150;

    std::string descripcion_2 = "Invasión de las Ruinas Antiguas: Los jugadores se aventuran en las ruinas antiguas para desenterrar tesoros y artefactos, pero se enfrentan a una horda de enemigos mecánicos y guardianes antiguos que protegen los secretos del pasado. Deben luchar estratégicamente para abrirse paso a través de las trampas y los enemigos poderosos.";
    size_t enemigos_2 = 115;
    size_t gastos_2 = 190;

    std::string descripcion_3 = "Batalla contra el Dragón del Abismo: En esta batalla épica, los jugadores se enfrentan a un dragón maligno que ha despertado de su sueño ancestral y amenaza con destruir la ciudad de Mondstadt. Deben utilizar todas sus habilidades y poderes elementales para derrotar al dragón y salvar la ciudad.";
    size_t enemigos_3 = 42;
    size_t gastos_3 = 300;

    combate combate_1(descripcion_1, enemigos_1, gastos_1);
    combate combate_2(descripcion_2, enemigos_2, gastos_2);
    combate combate_3(descripcion_3, enemigos_3, gastos_3);

    combate_multiple combates;
    combates.agragar_combate(combate_1);
    combates.agragar_combate(combate_2);
    combates.agragar_combate(combate_3);

    size_t total_gastado = combates.pelear();

    std::cout << "Este es el total de poder de trazacaminos gastado: " << std::endl;
    std::cout << total_gastado << std::endl;
}
