#include <stdio.h>
#include <stdlib.h>

struct Tiempo {
	int hora;
	int minutos;
	int segundos;
};


struct Tiempo crearTiempo(int,int,int);
void imprimir(struct Tiempo t1);
void suma_Tiempo(struct Tiempo t1, struct Tiempo t2);
void resta_Tiempo(struct Tiempo t1, struct Tiempo t2);
void Tiempo_dias(struct Tiempo t1);

int main() {
	struct Tiempo tiempo1;
	struct Tiempo tiempo2;
	
	printf("Ingrese una hora(1): ");
	scanf("%d", &tiempo1.hora);
	printf("Ingrese los minutos(1): ");
	scanf("%d", &tiempo1.minutos);
	printf("Ingrese los segundos(1): ");
	scanf("%d", &tiempo1.segundos);
	
	printf("Ingrese una hora(2): ");
	scanf("%d", &tiempo2.hora);
	printf("Ingrese los minutos(2): ");
	scanf("%d", &tiempo2.minutos);
	printf("Ingrese los segundos(2): ");
	scanf("%d", &tiempo2.segundos);
	
	printf("\n--------------------------\n");
	imprimir(crearTiempo(tiempo1.hora, tiempo1.minutos, tiempo1.segundos));
	printf("\n--------------------------\n");
	suma_Tiempo(crearTiempo(tiempo1.hora, tiempo1.minutos, tiempo1.segundos), crearTiempo(tiempo2.hora, tiempo2.minutos, tiempo2.segundos));
	printf("\n--------------------------\n");
	resta_Tiempo(crearTiempo(tiempo1.hora, tiempo1.minutos, tiempo1.segundos), crearTiempo(tiempo2.hora, tiempo2.minutos, tiempo2.segundos));
	printf("\n--------------------------\n");
	printf("\n El tiempo en dias del primer tiempo ingresado es: ");
	Tiempo_dias(crearTiempo(tiempo1.hora, tiempo1.minutos, tiempo1.segundos));
	printf("\n--------------------------\n");
	printf("\n El tiempo en dias del segundo tiempo ingresado es: ");
	Tiempo_dias(crearTiempo(tiempo2.hora, tiempo2.minutos, tiempo2.segundos));

	return 0;
}


struct Tiempo crearTiempo(int hora,int minutos,int segundos) {
	struct Tiempo t1;
	t1.hora = hora;
	t1.minutos = minutos;
	t1.segundos = segundos;
	
	if (hora < 0 || hora > 24) {
		if (minutos < 0 || minutos > 60) {
			if (segundos < 0 || minutos > 60) {
				printf("Datos incorrectos");
			}
		}
	}	
	return t1;	
}

void imprimir(struct Tiempo t1) {
	printf("Hora creada: %d:%d:%d", t1.hora, t1.minutos, t1.segundos);
}

void suma_Tiempo(struct Tiempo t1, struct Tiempo t2) {
	int sumaHora = t1.hora + t2.hora;
	int sumaMins = t1.minutos + t2.minutos;
	int sumaSeg = t1.segundos + t2.segundos;
	
	if (sumaHora >= 24) {
		sumaHora -= 24;
	}
	if (sumaMins >= 60) {
		sumaMins -= 60;
		sumaHora++;
	}
	if (sumaSeg >= 60) {
		sumaSeg -= 60;
		sumaMins++;
	}
	
	printf("La suma de los tiempos es: %d:%d:%d", sumaHora,sumaMins,sumaSeg);
}

void resta_Tiempo(struct Tiempo t1, struct Tiempo t2) {
	int sumaHora = t1.hora - t2.hora;
	int sumaMins = t1.minutos - t2.minutos;
	int sumaSeg = t1.segundos - t2.segundos;
	
	if (sumaHora < 0) {
		sumaHora += 24;
	}
	if (sumaMins < 0) {
		sumaMins += 60;
	}
	if (sumaSeg < 0) {
		sumaSeg += 60;
	}
	
	printf("La resta de los tiempos es: %d:%d:%d", sumaHora,sumaMins,sumaSeg);
}


void Tiempo_dias(struct Tiempo t1) {
	int auxYear = 0;
	int auxDias;
	
	if(t1.segundos > 60) {
		t1.minutos++;
	}
	if(t1.minutos > 60) {
		t1.hora++;
	}
	if(t1.hora > 24) {
		auxDias = t1.hora/24;
	}
	if (auxDias >= 365) {
		auxYear++;
	}
	
	printf("La cantidad de tiempo en dias es: %d year y %d dias", auxYear, auxDias);
}
