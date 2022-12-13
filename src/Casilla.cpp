//============================================================================
// Name        : Casilla.cpp
// Author      : Manuel David Hernández Pozo / Gonzalo Jiménez Gómez / Victor Manuel Basilio Montes
// Version     :
// Copyright   : Your copyright notice
// Description : Proyecto IASI
//============================================================================

#include "Casilla.h"

Casilla::Casilla() {

	cordenadaX=0;
	cordenadaY=0;
	valor=0;

}

void Casilla::setCordenadaX(int _cordenadaX){
	cordenadaX=_cordenadaX;
}

int Casilla::getCordenadaX(){
	return cordenadaX;
}

void Casilla::setCordenadaY(int _cordenadaY){
	cordenadaY=_cordenadaY;
}

int Casilla::getCordenadaY(){
	return cordenadaY;
}

void Casilla::setValor(int _valor){
	valor=_valor;
}

int Casilla::getValor(){
	return valor;
}

bool Casilla::esObjetivo(){
	if(getValor()==3){
		return true;
	}
	return false;
}

bool Casilla::esPieza(){
	if(getValor()==2){
		return true;
	}
	return false;
}

bool Casilla::esMuro(){
	if(getValor()==1){
		return true;
	}
	return false;
}

bool Casilla::esLibre(){
	if(getValor()==0){
		return true;
	}
	return false;
}

Casilla::~Casilla() {
	// TODO Auto-generated destructor stub
}

