Proceso calculoPaga
	Dimension nombres[100], apellidos[100], horaEntrada[100], horaSalida[100], paga[10000];
	Definir nombres, apellidos Como Caracter;
	Definir cantidadpersonas, i, horaSalida, horaEntrada, paga Como Entero;
    cantidadpersonas <- 0;
	
    Escribir "Ingrese la cantidad de personas: ";
    Leer cantidadpersonas;
	
    Para i <- 1 Hasta cantidadpersonas Hacer
        Escribir "Ingrese el nombre de la persona #", i, ": ";
        Leer nombres[i];
		
        Escribir "Ingrese el apellido de la persona #", i, ": ";
        Leer apellidos[i];
		
		Escribir "Ingrese la hora de entrada: (Reloj 24 hrs) ";
		Leer horaEntrada[i];
		Escribir "Ingrese la hora de salida: (Reloj 24 hrs) ";
		Leer horaSalida[i];
    FinPara
	
	
    Escribir "Lista de personas ingresadas:";
    Para i <- 1 Hasta cantidadpersonas Hacer
		paga[i] <- (horaSalida[i]-horaEntrada[i])*3000;
        Escribir "Persona ", i, ": ", nombres[i], " ", apellidos[i];
		Escribir "Hora de entrada: ", horaEntrada[i], " ", "Hora salida: ", horaSalida[i];
		Escribir "La paga es ", paga[i], "$";
    FinPara
	
	
	
FinProceso
