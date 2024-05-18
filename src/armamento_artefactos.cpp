#include "armamento_artefactos.hpp"
#include "artefacto.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

armamento_artefactos::armamento_artefactos() {
    maximos_artefactos = 6;
}

armamento_artefactos::armamento_artefactos(std::string path_archivo) {
    maximos_artefactos = 6;
    std::ifstream archivo(path_archivo);
    std::string linea;
    char delimitador = ',';
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            std::stringstream stream(linea);
            std::string ID, SET, TIPO, NIVEL, RAREZA;
            getline(stream, ID, delimitador);
            getline(stream, SET, delimitador);
            getline(stream, TIPO, delimitador);
            getline(stream, NIVEL, delimitador);
            getline(stream, RAREZA, delimitador);

            int id;
            try {
                id = std::stoi(ID);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error al convertir ID a entero: " << ID << std::endl;
                continue;
            }

            std::string set = SET;

            tipo tipo1;
            try {
                tipo1 = static_cast<tipo>(std::stoi(TIPO));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error al convertir TIPO a tipo: " << TIPO << std::endl;
                continue;
            }

            size_t nivel = std::stoul(NIVEL);

            rareza rareza1;
            try {
                rareza1 = static_cast<rareza>(std::stoi(RAREZA));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error al convertir RAREZA a rareza: " << RAREZA << std::endl;
                continue;
            }

            artefacto artefacto_actual(id, SET, tipo1, nivel, rareza1);
            agregar_artefacto(artefacto_actual);
        }
        archivo.close();
    } else {
        std::cerr << "Error al abrir el archivo: " << path_archivo << std::endl;
    }

}
/*
 * Pre:
 * Post: Agrega el artefacto al armamento.
 */
void armamento_artefactos::agregar_artefacto(artefacto artefacto_a_agregar) {
    if (lista_artefactos.tamanio() < maximos_artefactos) {
        bool artefacto_existe = false;
        size_t i = 0;
        while (i < lista_artefactos.tamanio() && !artefacto_existe) {
            if (lista_artefactos.actual() == artefacto_a_agregar) {
                artefacto_existe = true;
            }
            i++;
        }
        if (!artefacto_existe) {
            lista_artefactos.alta(artefacto_a_agregar);
        } else {
            std::cout << "El artefacto ya está presente en el armamento." << std::endl;
        }
    } else {
        std::cout << "No se pueden agregar más de seis artefactos." << std::endl;
    }
}


void armamento_artefactos::mostrar_artefacto_actual() {
    if (!lista_artefactos.vacio()){
        artefacto artefacto_actual = lista_artefactos.actual();
        std::cout<<artefacto_actual<< std::endl;
    }
}

void armamento_artefactos::mostrar_artefacto_siguiente() {
    if (!lista_artefactos.vacio()){
        lista_artefactos.avanzar();
        mostrar_artefacto_actual();
    }
}

void armamento_artefactos::mostrar_artefacto_anterior() {
    if (!lista_artefactos.vacio()) {
        lista_artefactos.retroceder();
        mostrar_artefacto_actual();
    }
}

void armamento_artefactos::mostrar_artefactos() {
    if (!lista_artefactos.vacio()){
        for (size_t i = 0; i < lista_artefactos.tamanio(); i++){
            mostrar_artefacto_actual();
            lista_artefactos.avanzar();
        }
    }
}

void armamento_artefactos::quitar_artefacto() {
    if (!lista_artefactos.vacio()) {
        lista_artefactos.baja();
    }
}

void armamento_artefactos::exportar_armamento() {
    std::string nombre_archivo = crear_nombre_archivo();
    std::ofstream archivo(nombre_archivo);
    if (archivo.is_open()) {
        for (size_t i = 0; i < lista_artefactos.tamanio(); ++i) {
            archivo << lista_artefactos.actual() << std::endl;
            lista_artefactos.avanzar();
        }
        archivo.close();
        std::cout << "Armamento exportado correctamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo para exportar el armamento." << std::endl;
    }
}

void armamento_artefactos::asignar_id_nombre_armamento(int nuevo_id, const std::string &nuevo_nombre) {
    id_armamento = nuevo_id;
    nombre_armamento = nuevo_nombre;
}

std::string armamento_artefactos::crear_nombre_archivo() {
    std::stringstream nombre_archivo_stream;
    nombre_archivo_stream << std::setw(8) << std::setfill('0') << id_armamento << "-" << nombre_armamento << ".csv";
    return nombre_archivo_stream.str();
}


