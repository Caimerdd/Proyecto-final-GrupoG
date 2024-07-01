#include <iostream>
#include <fstream>
#include "variables.h"

using namespace std;

void showTitle();
void employeInfo(int area);
void showTitleAdd();
void showTitlelist();

void employeInfo(int area) // se le agrega la variable que se usara para el switch
{
    int numTrabajadores; // se define variable
    cout << "Ingrese la cantidad de personas a agregar: ";
    cin >> numTrabajadores;
    cin.ignore();

    Trabajador trabajadores[numTrabajadores]; // arreglo tipo Trabajador, que usa la variable definida
    for (int i = 0; i < numTrabajadores; ++i)
    {
        cout << "Trabajador " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin.getline(trabajadores[i].nombre, MAX);
        cout << "Apellido: ";
        cin.getline(trabajadores[i].apellido, MAX);
        cout << "Hora de entrada (0-24): ";
        cin >> trabajadores[i].horaEntrada;
        cout << "Hora de salida (0-24): ";
        cin >> trabajadores[i].horaSalida;
        cin.ignore(); // Se limpia el enter que se dio al ingresar la hora de entrada
    }

    // Guardar información en archivos separados según el área
    ofstream outFile;
    switch (area)
    {
    case 1:
        outFile.open("trabajadores_cocina.txt", ios::app);
        break;
    case 2:
        outFile.open("trabajadores_meseros.txt", ios::app);
        break;
    case 3:
        outFile.open("trabajadores_bar.txt", ios::app);
        break;
    }

    for (int i = 0; i < numTrabajadores; ++i) // for para agregar la información en el archivo de texto
    {
        outFile << trabajadores[i].nombre << " "
                << trabajadores[i].apellido << " "
                << trabajadores[i].horaEntrada << " "
                << trabajadores[i].horaSalida << endl;
    }

    outFile.close();
};

void showTitle() // funcion para mostrar el titulo principal
{
    cout << "  ________  __  __    __               __               _______                             __    __                          __                    " << endl;
    cout << " /        |/  |/  |  /  |             /  |             /       \\                           /  \\  /  |                        /  |                   " << endl;
    cout << " $$$$$$$$/ $$ |$$/  _$$ |_     ______ $$/_______       $$$$$$$  |  ______    ______        $$  \\ $$ |  ______   _____  ____  $$/  _______    ______  " << endl;
    cout << " $$ |__    $$ |/  |/ $$   |   /      \\$//       |      $$ |__$$ | /      \\  /      \\       $$$  \\$$ | /      \\ /     \\/    \\ /  |/       \\  /      \\ " << endl;
    cout << " $$    |   $$ |$$ |$$$$$$/   /$$$$$$  |/$$$$$$$/       $$    $$<  $$$$$$  |/$$$$$$  |      $$$$  $$ |/$$$$$$  |$$$$$$ $$$$  |$$ |$$$$$$$  | $$$$$$  |" << endl;
    cout << " $$$$$/    $$ |$$ |  $$ | __ $$    $$ |$$      \\       $$$$$$$  | /    $$ |$$ |  $$/       $$ $$ $$ |$$ |  $$ |$$ | $$ | $$ |$$ |$$ |  $$ | /    $$ |" << endl;
    cout << " $$ |_____ $$ |$$ |  $$ |/  |$$$$$$$$/  $$$$$$  |      $$ |__$$ |/$$$$$$$ |$$ |            $$ |$$$$ |$$ \\__$$ |$$ | $$ | $$ |$$ |$$ |  $$ |/$$$$$$$ |" << endl;
    cout << " $$       |$$ |$$ |  $$  $$/ $$       |/     $$/       $$    $$/ $$    $$ |$$ |            $$ | $$$ |$$    $$/ $$ | $$ | $$ |$$ |$$ |  $$ |$$    $$ |" << endl;
    cout << " $$$$$$$$/ $$/ $$/    $$$$/   $$$$$$$/ $$$$$$$/        $$$$$$$/   $$$$$$$/ $$/             $$/   $$/  $$$$$$/  $$/  $$/  $$/ $$/ $$/   $$/  $$$$$$$/ " << endl;
};

void showTitleAdd()
{

    cout << "  /$$$$$$                                                                    /$$                      " << endl;
    cout << " /$$__  $$                                                                  | $$                      " << endl;
    cout << "| $$  \\ $$  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$$  /$$$$$$             " << endl;
    cout << "| $$$$$$$$ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$ |____  $$| $$__  $$ /$$__  $$ /$$__  $$            " << endl;
    cout << "| $$__  $$| $$  \\ $$| $$  \\__/| $$$$$$$$| $$  \\ $$  /$$$$$$$| $$  \\ $$| $$  | $$| $$  \\ $$            " << endl;
    cout << "| $$  | $$| $$  | $$| $$      | $$_____/| $$  | $$ /$$__  $$| $$  | $$| $$  | $$| $$  | $$            " << endl;
    cout << "| $$  | $$|  $$$$$$$| $$      |  $$$$$$$|  $$$$$$$|  $$$$$$$| $$  | $$|  $$$$$$$|  $$$$$$//$$ /$$ /$$ " << endl;
    cout << "|__/  |__/ \\____  $$|__/       \\_______/ \\____  $$ \\_______/|__/  |__/ \\_______/ \\______/|__/|__/|__/ " << endl;
    cout << "           /$$  \\ $$                     /$$  \\ $$                                                    " << endl;
    cout << "          |  $$$$$$/                    |  $$$$$$/                                                    " << endl;
    cout << "           \\______/                      \\______/                                                     " << endl;
    cout << endl;
    cout << endl;
};

void showTitlelist()
{
    cout << "               /$$       /$$             /$$                            " << endl;
    cout << "              | $$      |__/            | $$                            " << endl;
    cout << "              | $$       /$$  /$$$$$$$ /$$$$$$    /$$$$$$               " << endl;
    cout << " /$$$$$$      | $$      | $$ /$$_____/|_  $$_/   |____  $$       /$$$$$$" << endl;
    cout << "|______/      | $$      | $$|  $$$$$$   | $$      /$$$$$$$      |______/" << endl;
    cout << "              | $$      | $$ \\____  $$  | $$ /$$ /$$__  $$              " << endl;
    cout << "              | $$$$$$$$| $$ /$$$$$$$/  |  $$$$/|  $$$$$$$              " << endl;
    cout << "              |________/|__/|_______/    \\___/   \\_______/              " << endl;
    cout << "                                                                        " << endl;
    cout << "                                                                        " << endl;
    cout << endl;
};
