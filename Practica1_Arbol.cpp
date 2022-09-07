//Arboles.cpp
#include <iostream>
#include "Nodo.h"
#include "Arbol.h"

void menu();
int opcionesMenu();
int pedirDato();
int seleccionarOrden();

int main()
{
    menu();
}

void menu() {
    Nodo root(NULL);
    int opcion;
    int submenu;
    do
    {
        opcion = opcionesMenu();
        switch (opcion)
        {
        case 1: {
            int dato = pedirDato();
            root.root = root.push(root.root, dato);
            break;
        }
        case 2: {
            root.buscar(pedirDato());
            system("Pause");
            break;
        }
        case 3: {
            submenu = seleccionarOrden();
            if(submenu == 1)
                    root.preOrder(root.root);
            else if(submenu == 2)
                    root.inOrder(root.root);
            else if(submenu == 3)
                    root.postOrder(root.root);                
            system("Pause");
            break;
        }
        case 4: {
            root.imprimir(root.root,0);
            system("Pause");
            break;
        }
        case 0: {
            exit(1);
            break;
        }
        default:
            break;
        }
    } while (true);
}

int seleccionarOrden() {
    int opcion;
    std::cout << "Seleciona Orden\n [1] PreOrden\n [2] InOrden\n [3] PostOrden\n [4]Regresar\n";
    std::cin.ignore();
    std::cin >> opcion;
    return opcion;
}

int opcionesMenu() {
    int menu;
    system("cls");
    std::cout << "Bienvenido\n Seleccione opcion\n"
        << "Opcion [1] = Insetar Dato\n"
        << "Opcion [2] = Buscar Dato\n"
        << "Opcion [3] = Mostrar Orden\n"
        << "Opcion [4] = Mostrar Arbol\n"
        << "Opcion [0] = Salir\n";
    std::cin.ignore();
    std::cin >> menu;
    return menu;
}

int pedirDato() {
    int dato;
    std::cout << "Insertar Dato\n" << std::endl;
    std::cin.ignore();
    std::cin >> dato;
    return dato;
}