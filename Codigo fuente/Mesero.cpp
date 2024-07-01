#include <iostream>
#include <fstream>
using namespace std;

void showInfoMesero();
void showTitleMesero();

void showInfoMesero() // Cada area de trabajo tiene su propio Showinfo... sigan los consejos del primer showinfo
{
    ifstream inFile("trabajadores_meseros.txt");
    if (!inFile)
    {
        cout << "No se pudo abrir el archivo de trabajadores de meseros." << endl;
        return;
    }

    char nombre[MAX], apellido[MAX];
    int horaEntrada, horaSalida;
    while (inFile >> nombre >> apellido >> horaEntrada >> horaSalida)
    {
        int resul = (horaSalida - horaEntrada) * 300;
        cout << endl;
        cout << "Trabajador: " << nombre << " " << apellido << endl;
        cout << "Horario: " << horaEntrada << ":00 - " << horaSalida << ":00" << endl;
        cout << "Paga: " << resul << " C$" << endl;
        cout << endl;
    }
    inFile.close();
    system("pause");
}
 
void showTitleMesero()
{
    

    cout << " $$$$$$\\                                                                                                                          " << endl;
    cout << "$$  __$$\\                                                                                                                         " << endl;
    cout << "$$ /  $$ | $$$$$$\\   $$$$$$\\  $$$$$$$\\   $$$$$$\\        $$$$$$\\$$$$\\   $$$$$$\\   $$$$$$$\\  $$$$$$\\   $$$$$$\\   $$$$$$\\   $$$$$$$\\ " << endl;
    cout << "$$$$$$$$ |$$  __$$\\ $$  __$$\\ $$  __$$\\  \\____$$\\       $$  _$$  _$$\\ $$  __$$\\ $$  _____|$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  _____|" << endl;
    cout << "$$  __$$ |$$ |  \\__|$$$$$$$$ |$$ |  $$ | $$$$$$$ |      $$ / $$ / $$ |$$$$$$$$ |\\$$$$$$\\  $$$$$$$$ |$$ |  \\__|$$ /  $$ |\\$$$$$$\\  " << endl;
    cout << "$$ |  $$ |$$ |      $$   ____|$$ |  $$ |$$  __$$ |      $$ | $$ | $$ |$$   ____| \\____$$\\ $$   ____|$$ |      $$ |  $$ | \\____$$\\ " << endl;
    cout << "$$ |  $$ |$$ |      \\$$$$$$$\\ $$ |  $$ |\\$$$$$$$ |      $$ | $$ | $$ |\\$$$$$$$\\ $$$$$$$  |\\$$$$$$$\\ $$ |      \\$$$$$$  |$$$$$$$  |" << endl;
    cout << "\\__|  \\__|\\__|       \\_______|\\__|  \\__| \\_______|      \\__| \\__| \\__| \\_______|\\_______/  \\_______|\\__|       \\______/ \\_______/ " << endl;
}

