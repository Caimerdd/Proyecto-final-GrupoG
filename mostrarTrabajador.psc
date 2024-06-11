Proceso mostrarTrabajador
	Definir cantidadpersonas, i Como Entero;
	Escribir "Cantidad de personas a ingresar";
	Leer cantidadpersonas;
	
	Escribir "Lista de personas ingresadas:";
	Escribir "";
	
    Para i <- 1 Hasta cantidadpersonas Hacer
        Escribir "Persona ", i, ": [ejemplo nombre][ejemplo apellido]";
		Escribir "Hora de entrada[ejemplo] Hora salida: [ejemplo]";
		Escribir "La paga es [ejemplo] $";
		Escribir "**********************************************************";
		Escribir "";
    FinPara
FinProceso
