#include <stdio.h>
#include <string.h>

struct persona {
	char nombre[100];
	char apellido[100];
	long dni;
	long telefono;
	int edad;
};

struct Estudiante {
	struct persona p1;
	float promedio;
	int inasistencia;
};

struct Empleado {
	struct persona p1;
	int salario;
};

struct Socio {
	struct persona p1;
	long numerodesocio;
};

struct persona CrearPersona(char nombre[100],char apellido[100],long,long,int);
struct Estudiante CrearEstudiante(struct persona p1,float,int);
struct Empleado CrearEmpleado(struct persona p1,int);
struct Socio CrearSocio(struct persona p1, long);
void imprimir_Persona(struct persona p1);
void imprimirEstudiante(struct Estudiante e1);
void imprimirEmpleado(struct Empleado e1);
void imprimirSocio(struct Socio s1);
int igual_Identidad(struct persona p1, struct persona p2);

int main()
{
	// VARIABLES PERSONAS

	char nombre[100];
	char apellido[100];
	long dni;
	long telefono;
	int edad;
	
	char nombre2[100];
	char apellido2[100];
	long dni2;
	long telefono2;
	int edad2;
	
	// PEDIR DATOS
	printf("Ingrese el nombre de una persona: ");
	gets(nombre);
	fflush(stdin);
	printf("Ingrese el apellido de una persona: ");
	gets(apellido);
	fflush(stdin);
	printf("Ingrese el dni: ");
	scanf("%ld", &dni);
	fflush(stdin);
	printf("Ingrese el telefono: ");
	scanf("%ld", &telefono);
	fflush(stdin);
	printf("Ingrese la edad: ");
	scanf("%d", &edad);
	fflush(stdin);
	printf("\n----------------------------------\n");
	printf("Ingrese el nombre de otra persona: ");
	gets(nombre2);
	fflush(stdin);
	printf("Ingrese el apellido de otra persona: ");
	gets(apellido2);
	fflush(stdin);
	printf("Ingrese el dni: ");
	scanf("%ld", &dni2);
	fflush(stdin);
	printf("Ingrese el telefono: ");
	scanf("%ld", &telefono2);
	fflush(stdin);
	printf("Ingrese la edad: ");
	scanf("%d", &edad2);
	fflush(stdin);
	
	struct persona p1 = CrearPersona(nombre,apellido,dni,telefono,edad);
	imprimir_Persona(p1);
	struct persona p2 = CrearPersona(nombre2,apellido2,dni2,telefono2,edad2);
	imprimir_Persona(p2);
	
	printf("Devuelve 1 si ambas personas son la misma, 0 en caso contrario: %d", igual_Identidad(CrearPersona(nombre,apellido,dni,telefono,edad), CrearPersona(nombre2,apellido2,dni2,telefono2,edad2)));
	
	// VARIABLE DE PEDIR DATOS
	int opcion1;
	int opcion;
	
	// PEDIR DATOS
	printf("\nDesea ingresar un estudiante, empleado o un socio? (1) Si (0) No: ");
	scanf("%d", &opcion1);
	fflush(stdin);
	
	// VARIABLE EMPLEADO - SOCIO - ESTUDIANTE
	char nombreOtro[100];
	char apellidoOtro[100];
	long dniOtro;
	long telefonoOtro;
	int edadOtro;
	float promedioOtro;
	int inasistenciaOtro;
	int salarioOtro;
	long numerodesocioOtro;
	
	switch (opcion1) {
		case 1:
		printf("Que tipo desea ingresar? (1) Estudiante (2) Empleado (3) Socio:");
		scanf("%d", &opcion);
		fflush(stdin);
		
		printf("Ingrese el nombre de una persona: ");
		gets(nombreOtro);
		fflush(stdin);
		printf("Ingrese el apellido de una persona: ");
		gets(apellidoOtro);
		fflush(stdin);
		printf("Ingrese el dni: ");
		scanf("%ld", &dniOtro);
		fflush(stdin);
		printf("Ingrese el telefono: ");
		scanf("%ld", &telefonoOtro);
		fflush(stdin);
		printf("Ingrese la edad: ");
		scanf("%d", &edadOtro);
		fflush(stdin);
		
		struct persona OtraPersona = CrearPersona(nombreOtro,apellidoOtro,dniOtro,telefonoOtro,edadOtro);
		
		switch (opcion) {
			case 1:
			fflush(stdin);
			printf("Ingrese el promedio del alumno: ");
			scanf("%f", &promedioOtro);
			fflush(stdin);
			printf("Ingrese la inasistencia del alumno: ");
			scanf("%d", &inasistenciaOtro);
			fflush(stdin);
			
			imprimirEstudiante(CrearEstudiante(OtraPersona,promedioOtro,inasistenciaOtro));
			break;
			case 2:
			printf("Ingrese el salario: ");
			scanf("%d", &salarioOtro);
			fflush(stdin);
			
			imprimirEmpleado(CrearEmpleado(OtraPersona,salarioOtro));
			break;
			case 3:
			printf("Ingrese el numero de socio: ");
			scanf("%ld", &numerodesocioOtro);
			fflush(stdin);
			
			imprimirSocio(CrearSocio(OtraPersona,numerodesocioOtro));
			break;
			default:
			printf("Dato invalido");
		}
		case 2:
		break;
	}
	return 0;
}

struct persona CrearPersona(char nombre[100],char apellido[100],long dni,long telefono,int edad) {
	struct persona p1;
	strcpy(p1.nombre,nombre);
	strcpy(p1.apellido,apellido);	
	p1.dni = dni;
	p1.telefono = telefono;
	p1.edad = edad;
	return p1;
}

struct Estudiante CrearEstudiante(struct persona p1,float prom,int ins) {
	struct Estudiante e1;
	e1.promedio = prom;
	e1.inasistencia = ins;
	
	if (prom < 0 && prom > 100) {
		if (ins < 0) {
			printf("Dato invalido");
		}
	}
	return e1;
}

struct Empleado CrearEmpleado(struct persona p1, int sal) {
	struct Empleado e1;
	e1.salario = sal;
	
	if (sal < 0) {
		printf("Dato invalido");
	}
	return e1;
}

struct Socio CrearSocio(struct persona p1, long num) {
	struct Socio s1;
	s1.numerodesocio = num;
	
	if (num < 0) {
		printf("Dato invalido");
	}
	return s1;
}

void imprimir_Persona(struct persona p1) {
	printf("Nombre: %s\n Apellido: %s\n Dni: %ld\n Telefono: %ld\n Edad: %d\n", p1.nombre, p1.apellido,p1.dni,p1.telefono,p1.edad);                                                                               
}

void imprimirEstudiante(struct Estudiante e1) {
	printf("Nombre: %s\n Apellido: %s\n Dni: %ld\n Promedio: %f\n Inasistencia: %d", e1.p1.nombre, e1.p1.apellido, e1.p1.dni, e1.promedio, e1.inasistencia);
}

void imprimirEmpleado(struct Empleado e1) {
	printf("Nombre: %s\n Apellido: %s\n Dni: %ld\n Salario: %d", e1.p1.nombre, e1.p1.apellido, e1.p1.dni, e1.salario);
}

void imprimirSocio(struct Socio s1) {
	printf("Nombre: %s\n Apellido: %s\n Dni: %ld\n Numero de socio: %ld", s1.p1.nombre, s1.p1.apellido, s1.p1.dni, s1.numerodesocio);
}

int igual_Identidad(struct persona p1,struct persona p2) {
	if (p1.dni == p2.dni) {
		return 1;
	}
	return 0;	
}
