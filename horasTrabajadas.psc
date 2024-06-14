Proceso  CalcularHorasTrabajadas
	Definir horaEntrada, minutoEntrada, horaSalida, minutoSalida, horasTrabajadas, minutosTrabajados Como Entero;
	Escribir "Ingrese la hora de entrada en formato 24 horas:";
	Leer horaEntrada;
	Escribir "Ingrese los minutos de entrada:";
	Leer minutoEntrada;
	Escribir "Ingrese la hora de salida en formato 24 horas:";
	Leer horaSalida;
	Escribir "Ingrese los minutos de salida:";
	Leer minutoSalida;
	
	horasTrabajadas <- horaSalida - horaEntrada;
	minutosTrabajados <- minutoSalida - minutoEntrada;
	
	Si minutosTrabajados < 0 Entonces
		horasTrabajadas <- horasTrabajadas - 1;
		minutosTrabajados <- minutosTrabajados + 60;
	FinSi
	
	Escribir "El empleado trabajó ", horasTrabajadas, " horas y ", minutosTrabajados, " minutos.";
FinProceso

