Algoritmo almacenar_nombres_apellidos
	Dimension nombres[100];
	Dimension apellidos[100];
	Definir nombres, apellidos Como Caracter;
	Definir cantidadpersonas, i Como Entero;
    cantidadpersonas <- 0;
	
    Escribir "Ingrese la cantidad de personas: ";
    Leer cantidadpersonas;
	
    Para i <- 1 Hasta cantidadpersonas Hacer
        Escribir "Ingrese el nombre de la persona #", i, ": ";
        Leer nombres[i];
		
        Escribir "Ingrese el apellido de la persona #", i, ": ";
        Leer apellidos[i];
    FinPara
	
    Escribir "Lista de personas ingresadas:";
    Para i <- 1 Hasta cantidadpersonas Hacer
        Escribir "Persona ", i, ": ", nombres[i], " ", apellidos[i];
    FinPara
FinAlgoritmo
