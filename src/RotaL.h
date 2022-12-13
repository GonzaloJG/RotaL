//============================================================================
// Name        : RotaL.h
// Author      : Manuel David Hernández Pozo / Gonzalo Jiménez Gómez / Victor Manuel Basilio Montes
// Version     :
// Copyright   : Your copyright notice
// Description : Proyecto IASI
//============================================================================


#include "Tablero.h"
#ifndef ROTAL_H_
#define ROTAL_H_
#include "IList.h"
using namespace std;

class RotaL {
	Tablero tab;
	double heuristica;
	string movimientoDeIteracion;




public:
	RotaL();
	RotaL(Tablero t);

	/*
	 * Carga el tablero a partir de un fichero determinado. Tambien calcula los vertices tanto de la pieza como del objetivo y la heuristica
	 */
	void cargarTablero(string nombreFichero);

	/*
	 * Copia el tablero t1 en el tablero t2
	 */
	void copiarTablero(Tablero t1, Tablero &t2);

	/*
	 * Almacena en listaDeMovimientos todos los nodos que se pueden generar a partir del tablero actual
	 */
	void calcularMovimientos(IList <RotaL> &listaDeMovimientos1);

	/*
	 * Algoritmo de escalada simple que calcula los movimientos necesarios para llegar desde el origen al destino.
	 */
	void escaladaSimple(RotaL &rota, int &suma, bool &bloqueo, IList <RotaL> &listaDeMovimientos1);

	/*
	 * Muestra el tablero
	 */
	void mostrarTablero();

	/*
	 * Si devuelve true es que hemos llegado al objetivo
	 */
	bool hemosLlegadoObjetivo();

	/*
	 * Algoritmo de Maxima Pendiente que calcula los movimientos necesarios para llegar desde el origen al destino
	 */
	void maximaPendiente(RotaL &rota, int &suma, bool &bloqueo, IList <RotaL> &listaDeMovimientos1);

	/*
	 * Vacia la lista de movimientos pasada como parametro.
	 */
	void vaciarListaMovimiento(IList <RotaL> &listaDeMovimientos1);

	virtual ~RotaL();
};

#endif /* ROTAL_H_ */
