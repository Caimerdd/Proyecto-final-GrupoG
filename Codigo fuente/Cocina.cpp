#include <iostream>
#include <fstream>

using namespace std;

void showInfoCocina();
void showTitleCocina();

void showInfoCocina() // Cada area de trabajo tiene su propio Showinfo
{
    ifstream inFile("trabajadores_cocina.txt");
    if (!inFile) // Si el archivo no existe o no se puede abrir pasa esto
    {
        cout << "No se pudo abrir el archivo de trabajadores de cocina." << endl;
        return;
    }

    char nombre[MAX], apellido[MAX]; // definen variables que se deberian encontrar en el archivo
    int horaEntrada, horaSalida;
    while (inFile >> nombre >> apellido >> horaEntrada >> horaSalida) // minetras existan estas variables dentro del archivo se muestra lo siguiente...
    {
        int resul = (horaSalida - horaEntrada) * 500;
        cout << endl;
        cout << "Trabajador: " << nombre << " " << apellido << endl;
        cout << "Horario: " << horaEntrada << ":00 - " << horaSalida << ":00" << endl;
        cout << "Paga: " << resul << " C$" << endl;
        cout << endl;
    }
    inFile.close();
    system("pause");
}

void showTitleCocina()
{
    // Cada area tiene su propio titulo para ubicar al usuario donde se encuentra trabajando
    cout << " $$$$$$\\                                                                              $$\\                     " << endl;
    cout << "$$  __$$\\                                                                             \\__|                    " << endl;
    cout << "$$ /  $$ | $$$$$$\\   $$$$$$\\  $$$$$$$\\   $$$$$$\\         $$$$$$$\\  $$$$$$\\   $$$$$$$\\ $$\\ $$$$$$$\\   $$$$$$\\  " << endl;
    cout << "$$$$$$$$ |$$  __$$\\ $$  __$$\\ $$  __$$\\  \\____$$\\       $$  _____|$$  __$$\\ $$  _____|$$ |$$  __$$\\  \\____$$\\ " << endl;
    cout << "$$  __$$ |$$ |  \\__|$$$$$$$$ |$$ |  $$ | $$$$$$$ |      $$ /      $$ /  $$ |$$ /      $$ |$$ |  $$ | $$$$$$$ |" << endl;
    cout << "$$ |  $$ |$$ |      $$   ____|$$ |  $$ |$$  __$$ |      $$ |      $$ |  $$ |$$ |      $$ |$$ |  $$ |$$  __$$ |" << endl;
    cout << "$$ |  $$ |$$ |      \\$$$$$$$\\ $$ |  $$ |\\$$$$$$$ |      \\$$$$$$$\\ \\$$$$$$  |\\$$$$$$$\\ $$ |$$ |  $$ |\\$$$$$$$ |" << endl;
    cout << "\\__|  \\__|\\__|       \\_______|\\__|  \\__| \\_______|       \\_______| \\______/  \\_______|\\__|\\__|  \\__| \\_______|" << endl;
}
