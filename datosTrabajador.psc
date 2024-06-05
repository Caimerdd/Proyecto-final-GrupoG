Proceso datosTrabajador
	Definir name, lastname Como caracter;
	definir horaentrada, horasalida, i, cantidadpersonas como entero;
	Dimension name[100], lastname[100], horaentrada[100], horasalida[100];
	
	Escribir "Información del trabajador";
	Escribir "Digite la cantidad de personas";
	leer cantidadpersonas;
	
	Para i <- 1 hasta cantidadpersonas Hacer
		Escribir "Escriba el nombre del trabajador: ";
		Leer name[i];
		Escribir "Escriba el apellido del trabajador: ";
		leer lastname[i];
		Escribir "Hora de entrada: (reloj 24hrs)";
		leer horaentrada[i];
		Escribir "Hora de salida: (reloj 24hrs)";
		leer horasalida[i];
		
	FinPara
	
	
FinProceso
