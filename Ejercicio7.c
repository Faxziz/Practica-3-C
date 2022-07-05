#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 13

struct Carta {
	int valor;
	char palo[10];
};

struct Carta CrearCarta(int, char palo[50]);
void imprimirCarta(struct Carta c1);
struct Carta barajar();
int es_igual(struct Carta c1,struct Carta c2);
int es_igualPalo(struct Carta c1,struct Carta c2);
int es_igualNumero(struct Carta c1,struct Carta c2);
int es_full(struct Carta c1,struct Carta c2,struct Carta c3,struct Carta c4);
int es_poker(struct Carta c1,struct Carta c2,struct Carta c3,struct Carta c4);
int es_escaleraVerdadera(struct Carta c1,struct Carta c2,struct Carta c3);
int es_escaleraFalsa(struct Carta c1,struct Carta c2,struct Carta c3);
int es_escaleraReal(struct Carta c1,struct Carta c2,struct Carta c3);

int main()
{
	/* printf("\n---------------------------\n");
	int valor;
	char palo[10];
	int valor1;
	char palo1[10];
	int valor2;
	char palo2[10];
	int valor3;
	char palo3[10];
	
	printf("Ingrese el valor de la carta: ");
	scanf("%d", &valor);
	fflush(stdin);
	printf("Ingrese el palo de la carta: ");
	gets(palo);
	fflush(stdin);
	printf("\n----------------------------\n");
	printf("Ingrese el valor de la carta: ");
	scanf("%d", &valor1);
	fflush(stdin);
	printf("Ingrese el palo de la carta: ");
	gets(palo1);
	fflush(stdin);
	printf("\n----------------------------\n");
	printf("Ingrese el valor de la carta: ");
	scanf("%d", &valor2);
	fflush(stdin);
	printf("Ingrese el palo de la carta: ");
	gets(palo2);
	fflush(stdin);
	printf("\n----------------------------\n");
	printf("Ingrese el valor de la carta: ");
	scanf("%d", &valor3);
	fflush(stdin);
	printf("Ingrese el palo de la carta: ");
	gets(palo3);
	fflush(stdin);
	printf("\n----------------------------\n");
	
	// CARTAS GENERADAS
	struct Carta carta1 = CrearCarta(valor,palo);
	struct Carta carta2 = CrearCarta(valor1,palo1);
	struct Carta carta3 = CrearCarta(valor2,palo2);
	struct Carta carta4 = CrearCarta(valor3,palo3);
	*/
	
	int opcion,opcion2;

	
	printf("\nDesea barajar? (1) Si (0) No: ");
	scanf("%d", &opcion);
	
	if (opcion == 1) {
		do {
			printf("\n2 cartas barajadas. son iguales? (1) Si (0) No : %d\n", es_igual(barajar(),barajar()));
			printf("\n2 cartas barajadas. tienen igual palo? (1) Si (0) No : %d\n", es_igualPalo(barajar(),barajar()));
			printf("\n2 cartas barajadas. tienen igual numero? (1) Si (0) No : %d\n", es_igualNumero(barajar(),barajar()));
			printf("\n4 cartas barajadas. Forman full? (1) Si (0) No : %d\n", es_full(barajar(),barajar(),barajar(),barajar()));
			printf("\n4 cartas barajadas. Forman poker? (1) Si (0) No : %d\n", es_poker(barajar(),barajar(),barajar(),barajar()));
			printf("\n3 cartas barajadas. Forman escalera verdadera? (1) Si (0) No : %d\n", es_escaleraVerdadera(barajar(),barajar(),barajar()));
			printf("\n3 cartas barajadas. Forman escalera falsa? (1) Si (0) No : %d\n", es_escaleraFalsa(barajar(),barajar(),barajar()));
			printf("\n3 cartas barajadas. Forman escalera real? (1) Si (0) No : %d\n", es_escaleraReal(barajar(),barajar(),barajar()));
			
			printf("\nDesea barajar nuevamente? (1) Si (0) No: ");
			scanf("%d", &opcion2);
			srand(time(0));
		} while (opcion2 != 0);
	}
			
	return 0;
}

struct Carta CrearCarta(int valor, char palo[50]) {
	struct Carta c1;
	c1.valor = valor;
	c1.palo[10] = palo[10];
	return c1;
}

void imprimirCarta(struct Carta c1) {
	printf("Palo: %s\n Valor: %d\n", &c1.palo[10], c1.valor);
}

struct Carta barajar() {
	struct Carta c1;
	int grande1 = 13;
	int grande2 = 4;
	int chico1 = 1;
	int chico2 = 1;
	
	srand(time(0));
	int r = (rand() % (grande2 - chico2 + 1)) + 1;
	
	srand(time(0));
	c1.valor = (rand() % (grande1 - chico1 + 1)) + 1;
	
	switch (r) {
		case 1:
		strcpy(c1.palo, "corazon");
		break;
		case 2:
		strcpy(c1.palo, "pica");
		break;
		case 3:
		strcpy(c1.palo, "trebol");
		break;
		case 4:
		strcpy(c1.palo, "diamante");
		break;
		default: 
		break;
	}
	return c1;
}

int es_igual(struct Carta c1,struct Carta c2) {
	int respuesta1;
	int respuesta2;
	
	if (c1.valor == c2.valor) {
		respuesta1 = 1;
	}
	
	for(int i=0;i<10;i++) {
		for (int j=0;j<10;j++) {
			if (c1.palo[i] == c2.palo[j]) {
				respuesta2 = 1;
			}
		}
	}
	
	if (respuesta1 == respuesta2) return 1;
	return 0;	
}

int es_igualPalo(struct Carta c1,struct Carta c2) {
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			if (c1.palo[i] == c2.palo[j]) {
				return 1;
			}
		}
	}
	return 0;
}

int es_igualNumero(struct Carta c1,struct Carta c2) {
	if (c1.valor == c2.valor) {
		return 1;
	}
	return 0;
}

int es_full(struct Carta c1,struct Carta c2,struct Carta c3,struct Carta c4) {
	int respuesta = 0;
	if (es_igualNumero(c1,c2) == 1) {
		if (es_igualPalo(c1,c2) == 0) {
			if (es_igualNumero(c3,c4) == 1) {
				if (es_igualPalo(c3,c4) == 0) {
					respuesta = 1;
					}
					}
				}
			}
	if (es_igualNumero(c2,c3) == 1) {
		if (es_igualPalo(c2,c3) == 0) {
			if (es_igualNumero(c1,c4) == 1) {
				if (es_igualPalo(c1,c4) == 0) {
					respuesta = 1;
					}
				}
			}
		}

	if (es_igualNumero(c1,c4) == 1) {
		if (es_igualPalo(c1,c4) == 0) {
			if (es_igualNumero(c2,c3) == 1) {
				if (es_igualPalo(c2,c3) == 0) {
					respuesta = 1;
				}
			}
		}
	}
		if (es_igualNumero(c1,c3) == 1) {
		if (es_igualPalo(c1,c3) == 0) {
			if (es_igualNumero(c2,c4) == 1) {
				if (es_igualPalo(c2,c4) == 0) {
					respuesta = 1;
				}
			}
		}
	}
	return respuesta;
}

int es_poker(struct Carta c1,struct Carta c2,struct Carta c3,struct Carta c4) {
	int respuesta = 0;
	if (es_igual(c1,c2)) {
		if (es_igual(c3,c4)) {
			respuesta = 1;
		}
	}
	if (es_igual(c2,c3)) {
		if (es_igual(c1,c4)) {
			respuesta = 1;
		}
	}
	if (es_igual(c1,c3)) {
		if (es_igual(c2,c4)) {
			respuesta = 1;
		}
	}
	return respuesta;
}

int es_escaleraVerdadera(struct Carta c1,struct Carta c2,struct Carta c3) {
	int respuesta = 0;
	if (((es_igualPalo(c1,c2)) == (es_igualPalo(c1,c3)) == (es_igualPalo(c2,c3))) == 1) {
		if ((c1.valor + 1 == c2.valor) && (c2.valor + 1 == c3.valor) && (c1.valor + 2 == c3.valor)) {
			respuesta = 1;
		}
	}
	return respuesta;		 
}

int es_escaleraFalsa(struct Carta c1,struct Carta c2,struct Carta c3) {
	int respuesta = 0;
	if ((c1.valor + 1 == c2.valor) && (c2.valor + 1 == c3.valor) && (c1.valor + 2 == c3.valor)) {
		if (((es_igualPalo(c1,c2)) == (es_igualPalo(c1,c3)) == (es_igualPalo(c2,c3))) == 1) {
			respuesta = 1;
		}
	}
	return respuesta;
}

int es_escaleraReal(struct Carta c1,struct Carta c2,struct Carta c3) {
	int respuesta = 0;
	if (((es_igualPalo(c1,c2)) == (es_igualPalo(c1,c3)) == (es_igualPalo(c2,c3))) == 1) {
		if ((c1.valor <= 11) && (c1.valor + 1 == c2.valor) && (c2.valor + 1 == c3.valor) && (c1.valor + 2 == c3.valor)) {
			respuesta = 1;
		}
	}
	if (((es_igualPalo(c1,c2)) == (es_igualPalo(c1,c3)) == (es_igualPalo(c2,c3))) == 1) {
		if ((c1.valor == 12) && (c1.valor + 1 == c2.valor) && (c2.valor - 12 == c3.valor) && (c1.valor - 11 == c3.valor)) {
			respuesta = 1;
		}
	}
	if (((es_igualPalo(c1,c2)) == (es_igualPalo(c1,c3)) == (es_igualPalo(c2,c3))) == 1) {
		if ((c1.valor == 13) && (c1.valor - 12 == c2.valor) && (c2.valor + 1 == c3.valor) && (c1.valor - 11 == c3.valor)) {
			respuesta = 1;
		}
	}
	return respuesta;
}
