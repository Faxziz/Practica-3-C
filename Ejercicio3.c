#include <stdio.h>
#include <math.h>

struct point {
	double x;
	double y;
};

typedef struct point Point;

struct Rectangulo {
	Point punto1;
	Point punto2;
};

typedef struct Rectangulo Rec;

Point CrearPunto(int,int);
double POINTdist(Point p1, Point p2);
Rec CrearRec(Point p1,Point p2);
int POINTeq(Point p1,Point p2);
double RECTarea(Rec r1);
int RECTin(Point p1,Rec r1);

int main()
{
	int x,y,x1,y1,x2,y2;
	
	printf("\nIngrese una coordeanada x para un punto: ");
	scanf("%d", &x);
	printf("\nIngrese una coordeanada y para un punto: ");
	scanf("%d", &y);
	
	printf("\nIngrese una coordeanada x para otro punto: ");
	scanf("%d", &x1);
	printf("\nIngrese una coordeanada y para otro punto: ");
	scanf("%d", &y1);
	
	printf("\nIngrese una coordeanada x para otro punto: ");
	scanf("%d", &x2);
	printf("\nIngrese una coordeanada y para otro punto: ");
	scanf("%d", &y2);
	
	Point p1 = CrearPunto(x,y);
	Point p2 = CrearPunto(x1,y1);
	Point p3 = CrearPunto(x2,y2);
	Rec r1 = CrearRec(p1,p2);
	
	printf("\nLa distancia euclidiana entre ambos puntos es: %lf", POINTdist(p1,p2));
	printf("\nRetorna 1 si ambos puntos son iguales, sino, 0: %d", POINTeq(p1,p2));
	printf("\nEl area formada por el rectangulo con el punto 2, y el punto 1, es: %lf", RECTarea(r1));
	printf("\nSi l tercer punto ingresado se encuentra dentro del rectangulo retorna 1, sino, 0: %d", RECTin(p3,r1));
	return 0;
}

Point CrearPunto(int x,int y) {
	Point punto;
	punto.x = x;
	punto.y = y;
	return punto;
}

double POINTdist(Point p1,Point p2) {
	double calc;
	calc = sqrt(((pow((p1.x-p2.x),2)) + (pow((p1.y-p2.y),2))));
	return calc;
}

int POINTeq(Point p1,Point p2) {
	if ((p1.x == p2.x) && (p1.y == p2.y)) {
		return 1;
	}
	return 0;
}

Rec CrearRec(Point p1,Point p2) {
	Rec r1;
	r1.punto1 = p1;
	r1.punto2 = p2;
	return r1;
}

double RECTarea(Rec r1) {
	double calc;
	calc = (r1.punto2.x-r1.punto1.x)*(r1.punto2.y-r1.punto1.y);
	return calc;
}

int RECTin(Point p1, Rec r1) {
	if (p1.x <= r1.punto2.x && p1.x >= r1.punto1.x) {
		if (p1.y >= r1.punto1.y && p1.y <= r1.punto2.y) {
			return 1;
		}
	}
	return 0;
}
