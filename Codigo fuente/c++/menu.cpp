#include <iostream>
#include "funciones.cpp"
#include "Cocina.cpp"
#include "Mesero.cpp"
#include "Bar.cpp"
#include "titulos.cpp"

using namespace std;

void principal();
void menu1();
void menu2();
void menu3();

void principal()
{
    // Menu principal
    bool area_loop = true; // loop para que siempre se muestre el menu
    while (area_loop)
    {
        system("cls");
        showTitle();
        int choice;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "1. Area de Cocina" << endl;
        cout << endl;
        cout << "2. Area de Meseros" << endl;
        cout << endl;
        cout << "3. Area de Bar" << endl;
        cout << endl;
        cout << "4. Salir" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> choice;

        switch (choice)
        { // Cada area tiene su propio menu
        case 1:
            menu1();
            break;
        case 2:
            menu2();
            break;
        case 3:
            menu3();
            break;
        case 4:
            cout << "Saliendo..." << endl;
            area_loop = false; // La unica opción para salir del programa es con este boton
            break;
        default:
            cout << "Opcion inválida" << endl;
            break;
        }
    }
}

void menu1()
{
    bool menu_loop = true;

    while (menu_loop)
    {
        int choice;
        system("cls");
        showTitleCocina();
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "1. Agregar trabajador" << endl;
        cout << endl;
        cout << "2. Mostrar trabajadores" << endl;
        cout << endl;
        cout << "3. Editar trabajador" << endl;
        cout << endl;
        cout << "4. Eliminar trabajador" << endl;
        cout << endl;
        cout << "5. Volver" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            showTitleAdd();
            employeInfo(1);
            break;
        case 2:
            system("cls");
            showTitlelist();
            showInfoCocina();
            break;
        case 3:
            system("cls");
            showTitleEdit();
            editarTrabajador(1);
            break;
        case 4:
            system("cls");
            showTitleDelete();
            eliminarTrabajador(1);
            break;
        case 5:
            menu_loop = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    }
}

void menu2()
{
    bool menu_loop = true;
    while (menu_loop)
    {
        int choice;
        system("cls");
        showTitleMesero();
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "1. Agregar trabajador" << endl;
        cout << endl;
        cout << "2. Mostrar trabajadores" << endl;
        cout << endl;
        cout << "3. Editar trabajador" << endl;
        cout << endl;
        cout << "4. Eliminar trabajador" << endl;
        cout << endl;
        cout << "5. Volver" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            showTitleAdd();
            employeInfo(2);
            break;
        case 2:
            system("cls");
            showTitlelist();
            showInfoMesero();
            break;
        case 3:
            system("cls");
            showTitleEdit();
            editarTrabajador(2);
            break;
        case 4:
            system("cls");
            showTitleDelete();
            eliminarTrabajador(2);
            break;
        case 5:
            menu_loop = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    }
}

void menu3()
{
    bool menu_loop = true;
    while (menu_loop)
    {
        int choice;
        system("cls");
        showTitleBar();
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "1. Agregar trabajador" << endl;
        cout << endl;
        cout << "2. Mostrar trabajadores" << endl;
        cout << endl;
        cout << "3. Editar trabajador" << endl;
        cout << endl;
        cout << "4. Eliminar trabajador" << endl;
        cout << endl;
        cout << "5. Volver" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            showTitleAdd();
            employeInfo(3);
            break;
        case 2:
            system("cls");
            showTitlelist();
            showInfoBar();
            break;
        case 3:
            system("cls");
            showTitleEdit();
            editarTrabajador(3);
            break;
        case 4:
            system("cls");
            showTitleDelete();
            eliminarTrabajador(3);
            break;
        case 5:
            menu_loop = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    }
}