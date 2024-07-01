#include <iostream>
#include <fstream>
using namespace std;

void showinfoBar();
void showTitleBar();

void showInfoBar() // Cada area de trabajo tiene su propio Showinfo... sigan los consejos del primer showinfo
{
    ifstream inFile("trabajadores_bar.txt");
    if (!inFile)
    {
        cout << "No se pudo abrir el archivo de trabajadores de bar." << endl;
        return;
    }

    char nombre[MAX], apellido[MAX];
    int horaEntrada, horaSalida;
    while (inFile >> nombre >> apellido >> horaEntrada >> horaSalida)
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

void showTitleBar()
{
    
    cout << " $$$$$$\\                                                $$\\                           " << endl;
    cout << "$$  __$$\\                                               $$ |                          " << endl;
    cout << "$$ /  $$ | $$$$$$\\   $$$$$$\\  $$$$$$$\\   $$$$$$\\        $$$$$$$\\   $$$$$$\\   $$$$$$\\  " << endl;
    cout << "$$$$$$$$ |$$  __$$\\ $$  __$$\\ $$  __$$\\  \\____$$\\       $$  __$$\\  \\____$$\\ $$  __$$\\ " << endl;
    cout << "$$  __$$ |$$ |  \\__|$$$$$$$$ |$$ |  $$ | $$$$$$$ |      $$ |  $$ | $$$$$$$ |$$ |  \\__|" << endl;
    cout << "$$ |  $$ |$$ |      $$   ____|$$ |  $$ |$$  __$$ |      $$ |  $$ |$$  __$$ |$$ |      " << endl;
    cout << "$$ |  $$ |$$ |      \\$$$$$$$\\ $$ |  $$ |\\$$$$$$$ |      $$$$$$$  |\\$$$$$$$ |$$ |      " << endl;
    cout << "\\__|  \\__|\\__|       \\_______|\\__|  \\__| \\_______|      \\_______/  \\_______|\\__|      " << endl;
}
