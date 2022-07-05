#include <stdio.h>

struct complejo {
	int entero;
	int imaginaria;
};

struct complejo CrearComplejo(int,int);
void imprimir(struct complejo n1);
void suma_complejo(struct complejo n1,struct complejo n2);
void resta_complejo(struct complejo n1,struct complejo n2);
void multiplica_complejo(struct complejo n1,struct complejo n2);

int main()
{
	struct complejo n1;
	struct complejo n2;
	
	printf("Ingrese la parte entera del primer numero: ");
	scanf("%d", &n1.entero);
	printf("Ingrese la parte imaginaria del primer numero: ");
	scanf("%d", &n1.imaginaria);
	printf("Ingrese la parte entera del segundo numero: ");
	scanf("%d", &n2.entero);
	printf("Ingrese la parte imaginaria del segundo numero: ");
	scanf("%d", &n2.imaginaria);
	
	imprimir(CrearComplejo(n1.entero,n1.imaginaria));
	printf("\n--------------------------\n");
	imprimir(CrearComplejo(n2.entero,n2.imaginaria));
	printf("\n--------------------------\n");
	suma_complejo(CrearComplejo(n1.entero,n1.imaginaria), CrearComplejo(n2.entero,n2.imaginaria));
	printf("\n--------------------------\n");
	resta_complejo(CrearComplejo(n1.entero,n1.imaginaria), CrearComplejo(n2.entero,n2.imaginaria));
	printf("\n--------------------------\n");
	multiplica_complejo(CrearComplejo(n1.entero,n1.imaginaria), CrearComplejo(n2.entero,n2.imaginaria));
	printf("\n--------------------------\n");
	return 0;
}

struct complejo CrearComplejo(int entero,int imaginaria) {
	struct complejo n1;
	n1.entero = entero;
	n1.imaginaria = imaginaria;
	return n1;
}

void imprimir(struct complejo n1) {
	printf(" %d + %d i", n1.entero, n1.imaginaria);
}

void suma_complejo(struct complejo n1,struct complejo n2) {
	int auxEntera = n1.entero + n2.entero;
	int auxComplejo = n1.imaginaria + n2.imaginaria;
	
	printf("El resultado de la suma es: %d + %d i", auxEntera, auxComplejo);
}

void resta_complejo(struct complejo n1,struct complejo n2) {
	int auxEntera = n1.entero - n2.entero;
	int auxComplejo = n1.imaginaria - n2.imaginaria;
	
	printf("El resultado de la resta es: %d + %d i", auxEntera, auxComplejo);
}

void multiplica_complejo(struct complejo n1,struct complejo n2) {
	int aux1,aux2;
	aux1 = (n1.entero*n2.entero) - (n1.imaginaria*n2.imaginaria);
	aux2 = (n1.entero*n2.imaginaria) + (n1.imaginaria*n2.entero);
	
	printf("El resultado de la multiplicacion es: %d + %d i", aux1, aux2);
}
