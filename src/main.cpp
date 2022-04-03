/**
 * @file main.cpp
 * @author Stephanie Arismendi (alu0101351728@ull.edu.es)
 * @brief Implementación de Tablas Hash con dispersión abierta y cerrada
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "include/hashTable/hashTable.hpp"
using namespace std;

int main()
{
    using Key = long;
    unsigned size;
    int funciondispersion, tecnicadispersion, funcionexploracion;
    int blocksize;
    FuncionDispersion<Key> *fd;
    FuncionExploracion<Key> *fe;
    bool seguir = true;
    HashTable<Key> *hash;
    Key valor;

    cout << "\t\t __    __   ______    ______   __    __        ________   ______   _______   __        ________ " << endl;
    cout << "\t\t|  \\  |  \\ /      \\  /      \\ |  \\  |  \\      |        \\ /      \\ |       \\ |  \\      |        \\ " << endl;
    cout << "\t\t| $$  | $$|  $$$$$$\\|  $$$$$$\\| $$  | $$       \\$$$$$$$$|  $$$$$$\\| $$$$$$$\\| $$      | $$$$$$$$" << endl;
    cout << "\t\t| $$__| $$| $$__| $$| $$___\\$$| $$__| $$         | $$   | $$__| $$| $$__/ $$| $$      | $$__    " << endl;
    cout << "\t\t| $$    $$| $$    $$ \\$$    \\ | $$    $$         | $$   | $$    $$| $$    $$| $$      | $$  \\   " << endl;
    cout << "\t\t| $$$$$$$$| $$$$$$$$ _\\$$$$$$\\| $$$$$$$$         | $$   | $$$$$$$$| $$$$$$$\\| $$      | $$$$$   " << endl;
    cout << "\t\t| $$  | $$| $$  | $$|  \\__| $$| $$  | $$         | $$   | $$  | $$| $$__/ $$| $$_____ | $$_____ " << endl;
    cout << "\t\t| $$  | $$| $$  | $$ \\$$    $$| $$  | $$         | $$   | $$  | $$| $$    $$| $$     \\| $$     \\ " << endl;
    cout << "\t\t \\$$   \\$$ \\$$   \\$$  \\$$$$$$  \\$$   \\$$          \\$$    \\$$   \\$$ \\$$$$$$$  \\$$$$$$$$ \\$$$$$$$$" << endl;
    cout << "                                                                                                " << endl;
    cout << endl;

    cout << "\nIntroduce el tamaño de la tabla: ";
    std::cin >> size;
    while (size <= 0)
    {
        cout << "El tamaño debe ser mayor que 0. Introduce el tamaño de la tabla: ";
        std::cin >> size;
    }
    cout << "\n¿Qué función de dispersión deseas utilizar?" << endl;
    cout << "\t1. Función de dispersión módulo." << endl;
    cout << "\t2. Función de dispersión pseudoaleatoria." << endl;
    cout << "\t3. Función de dispersión basada en la suma." << endl;
    cout << "Introduce tu elección: ";
    std::cin >> funciondispersion;
    while (funciondispersion != 1 && funciondispersion != 2 && funciondispersion != 3)
    {
        cout << "La opción introducida no es válida. Introduce tu elección: ";
        std::cin >> funciondispersion;
    }
    cout << "\n¿Qué técnica de dispersión deseas utilizar?" << endl;
    cout << "\t1. Dispersión abierta." << endl;
    cout << "\t2. Dispersión cerrada." << endl;
    cout << "Introduce tu elección: ";
    std::cin >> tecnicadispersion;
    while (tecnicadispersion != 1 && tecnicadispersion != 2)
    {
        cout << "La opción introducida no es válida. Introduce tu elección: ";
        std::cin >> tecnicadispersion;
    }
    if (tecnicadispersion == 2)
    {
        cout << "\nIntroduzca el tamaño del bloque: ";
        std::cin >> blocksize;
        cout << "\tSelecicone la función de exploración: " << endl;
        cout << "\t1. Función de exploración lineal." << endl;
        cout << "\t2. Función de exploración cuadrática." << endl;
        cout << "\t3. Función de exploración de doble dispersión." << endl;
        cout << "\t4. Función de exploración de redispersión." << endl;
        cout << "Introduce tu elección: ";
        std::cin >> funcionexploracion;
        while (funcionexploracion != 1 && funcionexploracion != 2 && funcionexploracion != 3 && funcionexploracion != 4)
        {
            cout << "La opción introducida no es válida. Introduce tu elección: ";
            std::cin >> funcionexploracion;
        }
    }
    switch (funciondispersion)
    {
    case 1:
        fd = new fdModulo<Key>(size);
        break;
    case 2:
        fd = new fdPseudoaleatoria<Key>(size);
        break;
    case 3:
        fd = new fdSuma<Key>(size);
        break;
    default:
        break;
    }
    if (tecnicadispersion == 2)
    {
        switch (funcionexploracion)
        {
        case 1:
            fe = new feLineal<Key>();
            break;
        case 2:
            fe = new feCuadratica<Key>();
            break;
        case 3:
            fe = new feDobleDispersion<Key>(fd);
            break;
        case 4:
            fe = new feRedispersion<Key>();
            break;
        default:
            break;
        }
    }
    if (tecnicadispersion == 1)
    {
        hash = new HashTable<Key>(size, fd, nullptr, 0);
    }
    else if (tecnicadispersion == 2)
    {
        hash = new HashTable<Key>(size, fd, fe, blocksize);
    }
    while (seguir == true)
    {
        // sleep(20);

        cout << "¿Qué quieres hacer a continuación?" << endl;
        cout << "1. Insertar un valor." << endl;
        cout << "2. Buscar un valor." << endl;
        cout << "3. Salir." << endl;
        cout << "Introduce tu funciondispersion: ";
        cin >> funciondispersion;

        switch (funciondispersion)
        {
        case 1:
            cout << "\n¿Qué valor quieres insertar?" << endl;
            cin >> valor;
            if (hash->Insert(valor) == true)
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
            if (hash->Search(valor) == true)
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