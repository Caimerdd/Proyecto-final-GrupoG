Proceso menuPaga
	Definir Op Como entero;
	Escribir "En que area del restaurante trabaja usted: ";
	Escribir "1. Area de Concina";
	Escribir "2. Area de Bar";
	Escribir "3. Area de Meseros";
	leer Op;
	Segun Op Hacer
		1:
			Escribir "Su paga por trabajar en el area de la cocina es de...";
		2:
			Escribir  "Su paga por trabajar en el area del bar es de...";
		3:
			Escribir "Su paga por trabajar en el area de mesero es de...";
		De Otro Modo:
			Escribir "Opción no valida";
	FinSegun
	
	
	
FinProceso
