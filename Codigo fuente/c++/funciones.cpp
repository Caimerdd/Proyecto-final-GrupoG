#include <iostream>
#include <fstream>
#include <cstring>
#include "variables.h"

using namespace std;

void employeInfo(int area);
void editarTrabajador(int area);
void eliminarTrabajador(int area);

void employeInfo(int area) // se le agrega la variable que se usara para el switch
{   
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

    Trabajador trabajador;
    do {
        cout << "Ingrese ID del trabajador (0 para salir): ";
        cin >> trabajador.id;
        if (trabajador.id == 0) break;
        cin.ignore();
        cout << "Nombre: ";
        cin.getline(trabajador.nombre, MAX);
        cout << "Apellido: ";
        cin.getline(trabajador.apellido, MAX);
        do {
            cout << "Hora de entrada (0-23): ";
            cin >> trabajador.horaEntrada;
        } while (trabajador.horaEntrada < 0 || trabajador.horaEntrada > 23);
        do {
            cout << "Hora de salida (0-23): ";
            cin >> trabajador.horaSalida;
        } while (trabajador.horaSalida < 0 || trabajador.horaSalida > 23);
        cin.ignore();

        trabajador.paga = (trabajador.horaSalida - trabajador.horaEntrada) *
                          (area == 1 ? 400 : (area == 2 ? 300 : 400));

        outFile << trabajador.id << " "
                << trabajador.nombre << " "
                << trabajador.apellido << " "
                << trabajador.horaEntrada << " "
                << trabajador.horaSalida << " "
                << trabajador.paga << endl;
    } while (true);

    outFile.close();
}

void editarTrabajador(int area)
{
    ifstream inFile;
    ofstream outFile;
    char filename[MAX];

    switch (area)
    {
    case 1:
        strcpy(filename, "trabajadores_cocina.txt");
        break;
    case 2:
        strcpy(filename, "trabajadores_meseros.txt");
        break;
    case 3:
        strcpy(filename, "trabajadores_bar.txt");
        break;
    }

    inFile.open(filename);
    if (!inFile) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    int id;
    cout << "Ingrese el ID del trabajador a editar: ";
    cin >> id;

    Trabajador trabajador;
    ofstream tempFile("temp.txt");

    bool found = false;
    while (inFile >> trabajador.id >> trabajador.nombre >> trabajador.apellido >> trabajador.horaEntrada >> trabajador.horaSalida >> trabajador.paga)
    {
        if (trabajador.id == id) {
            found = true;
            cout << "Ingrese nuevos datos para el trabajador con ID " << id << ":" << endl;
            cin.ignore();
            cout << "Nombre: ";
            cin.getline(trabajador.nombre, MAX);
            cout << "Apellido: ";
            cin.getline(trabajador.apellido, MAX);
            do {
                cout << "Hora de entrada (0-23): ";
                cin >> trabajador.horaEntrada;
            } while (trabajador.horaEntrada < 0 || trabajador.horaEntrada > 23);
            do {
                cout << "Hora de salida (0-23): ";
                cin >> trabajador.horaSalida;
            } while (trabajador.horaSalida < 0 || trabajador.horaSalida > 23);

            trabajador.paga = (trabajador.horaSalida - trabajador.horaEntrada) *
                              (area == 1 ? 400 : (area == 2 ? 300 : 400));
        }
        tempFile << trabajador.id << " " << trabajador.nombre << " " << trabajador.apellido << " " << trabajador.horaEntrada << " " << trabajador.horaSalida << " " << trabajador.paga << endl;
    }

    inFile.close();
    tempFile.close();
    remove(filename);
    rename("temp.txt", filename);

    if (!found) {
        cout << "No se encontró un trabajador con ID " << id << endl;
    }
}

void eliminarTrabajador(int area)
{
    ifstream inFile;
    ofstream outFile;
    char filename[MAX];

    switch (area)
    {
    case 1:
        strcpy(filename, "trabajadores_cocina.txt");
        break;
    case 2:
        strcpy(filename, "trabajadores_meseros.txt");
        break;
    case 3:
        strcpy(filename, "trabajadores_bar.txt");
        break;
    }

    inFile.open(filename);
    if (!inFile) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    int id;
    cout << "Ingrese el ID del trabajador a eliminar: ";
    cin >> id;

    Trabajador trabajador;
    ofstream tempFile("temp.txt");

    bool found = false;
    while (inFile >> trabajador.id >> trabajador.nombre >> trabajador.apellido >> trabajador.horaEntrada >> trabajador.horaSalida >> trabajador.paga)
    {
        if (trabajador.id != id) {
            tempFile << trabajador.id << " " << trabajador.nombre << " " << trabajador.apellido << " " << trabajador.horaEntrada << " " << trabajador.horaSalida << " " << trabajador.paga << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (!found) {
        remove("temp.txt");
    } else {
        remove(filename);
        rename("temp.txt", filename);
    }
}
