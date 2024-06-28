#include <iostream>
#include <fstream>
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
    //Menu principal
    bool area_loop = true; //loop para que siempre se muestre el menu
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
        { //Cada area tiene su propio menu
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
            area_loop = false; //La unica opción para salir del programa es con este boton
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
            employeInfo(1); //Agregar la información al caso 1 del switch dentro de la función
            break;
        case 2:
            showInfoCocina();
            break;
        case 3:
            menu_loop = false; //Sale del loop, pero vuelve al primer loop
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
            employeInfo(2); //Agregar la información al caso 2 del switch dentro de la función
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
            employeInfo(3); //Agregar la información al caso 3 del switch dentro de la función
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

void employeInfo(int area) //se le agrega la variable que se usara para el switch
{
    int numTrabajadores; //se define variable
    cout << "Ingrese la cantidad de personas a agregar: ";
    cin >> numTrabajadores;
    cin.ignore(); 

    Trabajador trabajadores[numTrabajadores]; //arreglo tipo Trabajador, que usa la variable definida 
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
        cin.ignore(); //Se limpia el enter que se dio al ingresar la hora de entrada
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

    for (int i = 0; i < numTrabajadores; ++i) //for para agregar la información en el archivo de texto
    {
        outFile << trabajadores[i].nombre << " "
                << trabajadores[i].apellido << " "
                << trabajadores[i].horaEntrada << " "
                << trabajadores[i].horaSalida << endl;
    }

    outFile.close();
    principal();
}

void showInfoCocina() //Cada area de trabajo tiene su propio Showinfo
{
    ifstream inFile("trabajadores_cocina.txt");
    if (!inFile) //Si el archivo no existe o no se puede abrir pasa esto
    {
        cout << "No se pudo abrir el archivo de trabajadores de cocina." << endl;
        return principal();
    }

    char nombre[MAX], apellido[MAX]; //definen variables que se deberian encontrar en el archivo
    int horaEntrada, horaSalida;
    while (inFile >> nombre >> apellido >> horaEntrada >> horaSalida) //minetras existan estas variables dentro del archivo se muestra lo siguiente...
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

void showInfoMesero() //Cada area de trabajo tiene su propio Showinfo... sigan los consejos del primer showinfo
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

void showInfoBar() //Cada area de trabajo tiene su propio Showinfo... sigan los consejos del primer showinfo
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

void showTitle() //funcion para mostrar el titulo principal
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
    //Cada area tiene su propio titulo para ubicar al usuario donde se encuentra trabajando
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