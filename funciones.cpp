#include <iostream>
#include <fstream>
#include <cstring>
#include "variables.h"

using namespace std;

void showTitle();
void showTitleCocina();
void showTitleMesero();
void showTitleBar();
void principal();
void menu1();
void menu2();
void menu3();
void employeInfo(int area);
void showInfoCocina();
void showInfoMesero();
void showInfoBar();


void principal()
{

    bool area_loop = true;
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
        {
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
            area_loop = false;
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
        cout << "3. Volver" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            employeInfo(1);
            break;
        case 2:
            showInfoCocina();
            break;
        case 3:
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
        cout << "3. Volver" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            employeInfo(2);
            break;
        case 2:
            showInfoMesero();
            break;
        case 3:
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
        cout << "3. Volver" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            employeInfo(3);
            break;
        case 2:
            showInfoBar();
            break;
        case 3:
            menu_loop = false;
            break;
        default:
            cout << "Opción invalida" << endl;
            break;
        }
    }
}

void employeInfo(int area)
{
    int numTrabajadores;
    cout << "Ingrese la cantidad de personas a agregar: ";
    cin >> numTrabajadores;
    cin.ignore(); // Limpiar el buffer de entrada

    Trabajador trabajadores[numTrabajadores];
    for (int i = 0; i < numTrabajadores; ++i)
    {
        cout << "Trabajador " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin.getline(trabajadores[i].nombre, MAX);
        cout << "Apellido: ";
        cin.getline(trabajadores[i].apellido, MAX);
        cout << "Hora de entrada (0-23): ";
        cin >> trabajadores[i].horaEntrada;
        cout << "Hora de salida (0-23): ";
        cin >> trabajadores[i].horaSalida;
        cin.ignore(); // Limpiar el buffer de entrada
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

    for (int i = 0; i < numTrabajadores; ++i)
    {
        outFile << trabajadores[i].nombre << " "
                << trabajadores[i].apellido << " "
                << trabajadores[i].horaEntrada << " "
                << trabajadores[i].horaSalida << endl;
    }

    outFile.close();
    principal();
}

void showInfoCocina()
{
    ifstream inFile("trabajadores_cocina.txt");
    if (!inFile)
    {
        cout << "No se pudo abrir el archivo de trabajadores de cocina." << endl;
        return principal();
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

void showInfoMesero()
{
    ifstream inFile("trabajadores_meseros.txt");
    if (!inFile)
    {
        cout << "No se pudo abrir el archivo de trabajadores de meseros." << endl;
        return principal();
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

void showInfoBar()
{
    ifstream inFile("trabajadores_bar.txt");
    if (!inFile)
    {
        cout << "No se pudo abrir el archivo de trabajadores de bar." << endl;
        return principal();
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

void showTitle()
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
}

void showTitleCocina(){
    
cout << " $$$$$$\\                                                                              $$\\                     " << endl;
cout << "$$  __$$\\                                                                             \\__|                    " << endl;
cout << "$$ /  $$ | $$$$$$\\   $$$$$$\\  $$$$$$$\\   $$$$$$\\         $$$$$$$\\  $$$$$$\\   $$$$$$$\\ $$\\ $$$$$$$\\   $$$$$$\\  " << endl;
cout << "$$$$$$$$ |$$  __$$\\ $$  __$$\\ $$  __$$\\  \\____$$\\       $$  _____|$$  __$$\\ $$  _____|$$ |$$  __$$\\  \\____$$\\ "<<endl;
cout << "$$  __$$ |$$ |  \\__|$$$$$$$$ |$$ |  $$ | $$$$$$$ |      $$ /      $$ /  $$ |$$ /      $$ |$$ |  $$ | $$$$$$$ |"<<endl;
cout << "$$ |  $$ |$$ |      $$   ____|$$ |  $$ |$$  __$$ |      $$ |      $$ |  $$ |$$ |      $$ |$$ |  $$ |$$  __$$ |"<<endl;
cout << "$$ |  $$ |$$ |      \\$$$$$$$\\ $$ |  $$ |\\$$$$$$$ |      \\$$$$$$$\\ \\$$$$$$  |\\$$$$$$$\\ $$ |$$ |  $$ |\\$$$$$$$ |"<<endl;
cout << "\\__|  \\__|\\__|       \\_______|\\__|  \\__| \\_______|       \\_______| \\______/  \\_______|\\__|\\__|  \\__| \\_______|"<<endl;
                                                                                                    
}

void showTitleMesero(){

cout << " $$$$$$\\                                                                                                                          "<< endl;
cout << "$$  __$$\\                                                                                                                         "<< endl;
cout << "$$ /  $$ | $$$$$$\\   $$$$$$\\  $$$$$$$\\   $$$$$$\\        $$$$$$\\$$$$\\   $$$$$$\\   $$$$$$$\\  $$$$$$\\   $$$$$$\\   $$$$$$\\   $$$$$$$\\ "<< endl;
cout << "$$$$$$$$ |$$  __$$\\ $$  __$$\\ $$  __$$\\  \\____$$\\       $$  _$$  _$$\\ $$  __$$\\ $$  _____|$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  _____|"<< endl;
cout << "$$  __$$ |$$ |  \\__|$$$$$$$$ |$$ |  $$ | $$$$$$$ |      $$ / $$ / $$ |$$$$$$$$ |\\$$$$$$\\  $$$$$$$$ |$$ |  \\__|$$ /  $$ |\\$$$$$$\\  "<< endl;
cout << "$$ |  $$ |$$ |      $$   ____|$$ |  $$ |$$  __$$ |      $$ | $$ | $$ |$$   ____| \\____$$\\ $$   ____|$$ |      $$ |  $$ | \\____$$\\ "<< endl;
cout << "$$ |  $$ |$$ |      \\$$$$$$$\\ $$ |  $$ |\\$$$$$$$ |      $$ | $$ | $$ |\\$$$$$$$\\ $$$$$$$  |\\$$$$$$$\\ $$ |      \\$$$$$$  |$$$$$$$  |"<< endl;
cout << "\\__|  \\__|\\__|       \\_______|\\__|  \\__| \\_______|      \\__| \\__| \\__| \\_______|\\_______/  \\_______|\\__|       \\______/ \\_______/ "<< endl;
                                                                                                                                  

}

void showTitleBar(){

cout << " $$$$$$\\                                                $$\\                           "<<endl;
cout << "$$  __$$\\                                               $$ |                          "<<endl;
cout << "$$ /  $$ | $$$$$$\\   $$$$$$\\  $$$$$$$\\   $$$$$$\\        $$$$$$$\\   $$$$$$\\   $$$$$$\\  "<<endl;
cout << "$$$$$$$$ |$$  __$$\\ $$  __$$\\ $$  __$$\\  \\____$$\\       $$  __$$\\  \\____$$\\ $$  __$$\\ "<<endl;
cout << "$$  __$$ |$$ |  \\__|$$$$$$$$ |$$ |  $$ | $$$$$$$ |      $$ |  $$ | $$$$$$$ |$$ |  \\__|"<<endl;
cout << "$$ |  $$ |$$ |      $$   ____|$$ |  $$ |$$  __$$ |      $$ |  $$ |$$  __$$ |$$ |      "<<endl;
cout << "$$ |  $$ |$$ |      \\$$$$$$$\\ $$ |  $$ |\\$$$$$$$ |      $$$$$$$  |\\$$$$$$$ |$$ |      "<<endl;
cout << "\\__|  \\__|\\__|       \\_______|\\__|  \\__| \\_______|      \\_______/  \\_______|\\__|      "<<endl;
                                                                                      
                                                                                      
                                                                                      

}