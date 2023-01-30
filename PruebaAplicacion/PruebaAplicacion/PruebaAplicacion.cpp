// PruebaAplicacion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//Incluímos las librerías
#include <iostream>
#include <omp.h>

//Eliminar los 'std::' de todos los comandos c
using namespace std;

//Definimos las constantes del programa
#define N 1000 //Cambia el tamaño de los arreglos.
#define chunk 200 //Es la cantidad de partes en que se distribuirá la carga de trabajo.
#define mostrar 10 //Valores del arreglo que se mostrarán.

//Función para imprimir valor de los arreglos
void imprimeArreglo(float *d);

int main()
{
	
	//Título
	cout << "--Sumando Arreglos en paralelo--\n\n";
	//Variables
	float a[N], b[N], c[N];//arreglos
	int i; //iterador
	int pedazos = chunk;//división de carga

	//Llenado de arreglos a y b
	for (i = 0; i < N; i++)
	{
		//Aquí podemos cambiar el cálculo para tener distintos valores
		a[i] = (i*10) + 20;
		b[i] = (i*7) * 33;
	}
	//Definimos que la instrucción 'for' va a ser realizada en paralelo 
#pragma omp parallel for \
    shared(a,b,c, pedazos) private(i) \
    schedule(static, pedazos)

	//El siguiente ciclo suma los valores de a + b y son guardados en c
	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];

	//Imprimimos los resultados
	cout << "Primeros " << mostrar << " valores del arreglo a: " << endl;
	imprimeArreglo(a);
	cout << "Primeros " << mostrar << " valores del arreglo b: " << endl;
	imprimeArreglo(b);
	cout << "Primeros " << mostrar << " valores del arreglo c: " << endl;
	imprimeArreglo(c);
}

//Declaramos la función vacía para imprimir los valores del arreglo
//La variable 'mostrar' controla el número de valores a mostrar
void imprimeArreglo(float* d) {
	int separador = 0;
	for (int x = 0; x < mostrar; x++)
	{
		cout << "|" << d[x] << "|\t";
	}
	cout << endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
