Algoritmo opciones
	Definir num Como Entero
	Definir op Como Caracter
	
	Escribir "Ingrese un n�mero"
	Leer num
	Escribir "Ingrese una operaci�n"
	Leer op
	
	Segun op Hacer
		"sumar 10":
			num <- num + 10
		"restar 10":
			num <- num - 10
		"multiplicar 10":
			num <- num * 10
		"restar 5":
			num <- num - 5
		De Otro Modo:
			num <- 0
	FinSegun
	
	Escribir "El n�mero es: ", num
	
FinAlgoritmo

