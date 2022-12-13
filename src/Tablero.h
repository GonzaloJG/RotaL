//============================================================================
// Name        : Tablero.h
// Author      : Manuel David Hernández Pozo / Gonzalo Jiménez Gómez / Victor Manuel Basilio Montes
// Version     :
// Copyright   : Your copyright notice
// Description : Proyecto IASI
//============================================================================

#ifndef TABLERO_H_
#define TABLERO_H_
#include "Casilla.h"

#include <string>
using namespace std;

int const TAMPIEZA=4;
int const TAM=10;
class Tablero {
	Casilla Matriz[TAM][TAM];

	Casilla Pieza[4];
	Casilla verticePieza;

	Casilla Objetivo[4];
	Casilla verticeObjetivo;

public:
	Tablero();

	/*
	 * Asigna fila, columna y valor a una casilla
	 */
	void asignarValoresCasillas(int fil, int col, int valor);

	/*
	 * Asigna a una pieza determinada Pieza[posicion] la fila y la columna a la que corresponden
	 * y su valor.
	 */
	void asignarValoresPieza(int posicion, int fil, int col, int valor);

	/*
	 * Asigna a un componente determinado del objetivo Objetivo[posicion] la fila y la columna
	 * en la que esta situada y su valor
	 */
	void asignarValoresObjetivo(int posicion, int fil, int col, int valor);

	/*
	 * Devuelve una casilla de la pieza (i)
	 */
	Casilla obtenerPieza(int i);

	/*
	 * Devuelve una casilla del objetivo (i)
	 */
	Casilla obtenerObjetivo(int i);

	/*
	 * Devuelve el vertice de la pieza
	 */
	Casilla VerticePieza();

	/*
	 * se muestra la matriz de casillas
	 */
	void mostrarMatriz();

	/*
	 * Pone a cero el valor de una casilla determinada del tablero
	 */
	void borrarPieza(int x, int y);

	/*
	 * Se mueve la pieza dependiendo del parámetro de entrada
	 * 0--> arriba / 1--> abajo /2--> derecha/ 3-->izquierda
	 */
	void moverPieza(int direccion);

	/*
	 * Devuelve el valor de una casilla determinada
	 */
	int consultarValor(int x, int y);

	/*
	 * C0mprueba si el movimiento pasado por parametro se puede realizar o no
	 * 0--> arriba / 1--> abajo /2--> derecha/ 3-->izquierda/ 4--> rotar
	 */
	bool comprobarMovimiento(int direccion);

	/*
	 * Nos dice si cas es el vertice o no de la pieza
	 */
	bool esVertice(Casilla cas);

	/*
	 * Nos devuelve un valor identificando la posicion de la pieza pasandole el vertice la misma
	 */
	int calcularPosicion(Casilla vertice);

	/*
	 * Comprueba si la pieza esta invertida o no
	 */
	bool piezaInvertida(Casilla vertice);

	/*
	 * Guarda en el atributo verticePieza las coordenadas y el valor del vertice de la pieza
	 */
	void calcularVerticePieza();

	/*
	 * Rota la pieza en funcion de la posicion en la que se encuentra(direccion)
	 */
	void rotarPieza(int direccion);

	/*
	 * Comprueba si se puede rotar la pieza dependiendo de la posición en la que se encuentre
	 */
	bool comprobarRotar(int direccion);

	/*
	 * Comprueba si la casilla pasada como parametro es vertice objetivo
	 */
	bool esVerticeObjetivo(Casilla cas);

	/*
	 * Calcula el vertice de la pieza objetivo almacenandolo en el atributo verticeObjetivo
	 */
	void calcularVerticeObjetivo();

	/*
	 * Calcula la distancia pitagorica entre el vertice de la pieza y el vertice objetivo
	 */
	double calcularHeuristica();




	virtual ~Tablero();
};

#endif /* TABLERO_H_ */
