#include <iostream>
#include <fstream>

#define MAX 100

using namespace std;

void showTitleBar();
void showInfoBar();

void showInfoBar() // Cada area de trabajo tiene su propio Showinfo... sigan los consejos del primer showinfo
{   
    ifstream inFile;
    inFile.open("trabajadores_bar.txt");
    if (!inFile)
    {
        return;
    }

    Trabajador trabajador;
    while (inFile >> trabajador.id >> trabajador.nombre >> trabajador.apellido >> trabajador.horaEntrada >> trabajador.horaSalida >> trabajador.paga)
    {
        cout << "ID: " << trabajador.id << endl;
        cout << "Nombre: " << trabajador.nombre << endl;
        cout << "Apellido: " << trabajador.apellido << endl;
        cout << "Hora de entrada: " << trabajador.horaEntrada << endl;
        cout << "Hora de salida: " << trabajador.horaSalida << endl;
        cout << "Paga: " << trabajador.paga << endl;
        cout << "--------------------------" << endl;
    }

    inFile.close();
    system("pause");
}
