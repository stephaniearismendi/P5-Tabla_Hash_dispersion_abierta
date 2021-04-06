/**
 * @file main.cpp
 * @author Stephanie Andreina Arismendi Escobar (alu0101351728@ull.edu.es)
 * @brief El programa principal pide al usuario el tamaño de la tabla y la función de dispersión a utilizar.
 *  Crea el objeto que implementa la función de dispersión e instancia la tabla hash con el tipo de Clave=int. 
 *  A continuación implementa un menú que permita insertar y buscar valores de clave solicitadas al usuario, mostrando el resultado de la operación.
 * @version 0.1
 * @date 2021-04-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "tabla_hash.hpp"
#include "lista.hpp"
#include <unistd.h>

int main()
{
    using Clave = int;
    unsigned size;
    int eleccion;
    bool seguir = false;
    FuncionDispersion<Clave> *fd;
    TablaHash<Clave> *hash;
    Clave valor;

    cout << "\t\t╔═══════════════╗" << endl;
    cout << "\t\t   TABLA HASH    " << endl;
    cout << "\t\t╚═══════════════╝" << endl;
    cout << endl;

    while (seguir == false)
    {
        cout << "\nIntroduce el tamaño de la tabla: ";
        cin >> size;
        cout << "\n¿Qué función de dispersión deseas utilizar?" << endl;
        cout << "1. Función de dispersión módulo." << endl;
        cout << "2. Función de dispersión pseudoaleatoria." << endl;
        cout << "Introduce tu elección: ";
        cin >> eleccion;
        if (eleccion == 1 || eleccion == 2)
        {
            seguir = true;
        }
        else
        {
            cout << "\nElección no disponible. Intentalo de nuevo";
        }
    }

    switch (eleccion)
    {
    case 1:
        fd = new fdModulo<Clave>(size);
        break;
    case 2:
        fd = new fdPseudoaleatoria<Clave>(size);
        break;
    default:
        cout << endl;
        break;
    }

    hash = new TablaHash<Clave>(size, fd);
    seguir = true;
    int numero;
    while (seguir == true)
    {
        // sleep(20);

        cout << "¿Qué quieres hacer a continuación?" << endl;
        cout << "1. Insertar un valor." << endl;
        cout << "2. Buscar un valor." << endl;
        cout << "3. Salir." << endl;
        cout << "Introduce tu eleccion: ";
        cin >> eleccion;

        switch (eleccion)
        {
        case 1: 
            cout << "\n¿Qué valor quieres insertar?" << endl; 
            cin >> valor;
            if (hash->Insertar(valor) == true)
            {
                cout << "El valor se ha introducido correctamente" << endl;
            }
            else 
            {
                cout << "El valor no se ha introducido" << endl;
            }
            break;
        case 2:
            cout << "\n¿Qué valor quieres buscar?" << endl;
            cin >> valor;
            if (hash->Buscar(valor) == true)
            {
                cout << "El valor se ha encontrado." << endl;
            }
            else
            {
                cout << "El valor no se ha encontrado." << endl;
            }
            break;
        case 3:
            cout << "\nFinalizando el programa..." << endl;
            seguir = false;
            break;
        default:
            cout << "\nElección no disponible. Vuelve a intentarlo." << endl;
            break;
        }
    }
}