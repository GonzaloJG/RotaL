//============================================================================
// Name        : Casilla.h
// Author      : Manuel David Hernández Pozo / Gonzalo Jiménez Gómez / Victor Manuel Basilio Montes
// Version     :
// Copyright   : Your copyright notice
// Description : Proyecto IASI
//============================================================================

#ifndef CASILLA_H_
#define CASILLA_H_

class Casilla {
	int cordenadaX;
	int cordenadaY;
	int valor;		//0->libre, 1-> muro, 2-> pieza, 3-> objetivo


public:
	Casilla();

	/*
	 * Asigna coordenada x
	 */
	void setCordenadaX(int _cordenadaX);

	/*
	 * Devuelve coordenada x
	 */
	int getCordenadaX();

	/*
	 * Asigna coordenada y
	 */
	void setCordenadaY(int _cordenadaY);

	/*
	 * Devuelve coordenada y
	 */
	int getCordenadaY();

	/*
	 * Asigna un valor a la casilla
	 */
	void setValor(int _valor);

	/*
	 * Devuelve el valor de la casilla
	 */
	int getValor();

	/*
	 * Determina si la casilla pertence al objetivo
	 */
	bool esObjetivo();

	/*
	 * Determina si la casilla pertence a la pieza
	 */
	bool esPieza();

	/*
	 * Determina si la casilla es muro
	 */
	bool esMuro();

	/*
	 * Determina si la casilla esta libre, es decir, si es un cero
	 */
	bool esLibre();


	virtual ~Casilla();
};

#endif /* CASILLA_H_ */
