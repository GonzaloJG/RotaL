//============================================================================
// Name        : RotaL.cpp
// Author      : Manuel David Hernández Pozo / Gonzalo Jiménez Gómez / Victor Manuel Basilio Montes
// Version     :
// Copyright   : Your copyright notice
// Description : Proyecto IASI
//============================================================================

#include "RotaL.h"
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

RotaL::RotaL(){

}

RotaL::RotaL(Tablero t) {
	// TODO Auto-generated constructor stub
	tab=t;

}

void RotaL::cargarTablero(string nombreFichero){
	ifstream fichero_lectura;
	string aux;
	int auxi;
	int valor=0;
	int objetivo=0;
	fichero_lectura.open(nombreFichero); //Abre el fichero
	if(fichero_lectura.is_open()){ //Si esta abierto
		for(int i=0; i<10; i++){
			for(int j=0; j<11; j++){
				if(j==10){
					getline(fichero_lectura, aux);
				}else{
					getline(fichero_lectura, aux, ',');
					auxi=atoi(aux.c_str());

					tab.asignarValoresCasillas(i ,j, auxi);

					if(auxi==2){
						tab.asignarValoresPieza(valor, i, j, auxi);

						valor++;
					}

					if(auxi==3){
						tab.asignarValoresObjetivo(objetivo, i, j, auxi);
						objetivo++;
					}
				}
			}
		}
	}
	fichero_lectura.close();

	tab.calcularVerticePieza();
	tab.calcularVerticeObjetivo();
	heuristica=tab.calcularHeuristica();
	}

void RotaL::copiarTablero(Tablero t1, Tablero &t2){
	t2=t1;
}


bool RotaL::hemosLlegadoObjetivo(){
		bool bandera[4]={false, false, false, false};
		bool aux=true;
		for(int i=0; i<4 && aux; i++){
			for(int j=0; j<4; j++){
				if(tab.obtenerPieza(i).getCordenadaX()==tab.obtenerObjetivo(j).getCordenadaX() && tab.obtenerPieza(i).getCordenadaY()==tab.obtenerObjetivo(j).getCordenadaY()){
					bandera[i]=true;
				}
			}
			if(bandera[i]==false){
				aux=false;
			}
		}
		return aux;
	}


void RotaL::calcularMovimientos(IList <RotaL> &listaDeMovimientos1){

	if(tab.comprobarMovimiento(0)){
		Tablero aux;
		copiarTablero(tab, aux);
		aux.moverPieza(0);
		RotaL auxRotal(aux);
		auxRotal.heuristica=auxRotal.tab.calcularHeuristica();
		auxRotal.movimientoDeIteracion="A";
		listaDeMovimientos1.insertar(auxRotal);
		listaDeMovimientos1.avanzar();
	}
	if(tab.comprobarMovimiento(1)){
		Tablero aux;
		copiarTablero(tab, aux);
		aux.moverPieza(1);
		RotaL auxRotal(aux);
		auxRotal.heuristica=auxRotal.tab.calcularHeuristica();
		auxRotal.movimientoDeIteracion="B";
		listaDeMovimientos1.insertar(auxRotal);
		listaDeMovimientos1.avanzar();
	}

	if(tab.comprobarMovimiento(2)){
		Tablero aux;
		copiarTablero(tab, aux);
		aux.moverPieza(2);
		RotaL auxRotal(aux);
		auxRotal.heuristica=auxRotal.tab.calcularHeuristica();
		auxRotal.movimientoDeIteracion="D";
		listaDeMovimientos1.insertar(auxRotal);
		listaDeMovimientos1.avanzar();

	}

	if(tab.comprobarMovimiento(3)){
		Tablero aux;
		copiarTablero(tab, aux);
		aux.moverPieza(3);
		RotaL auxRotal(aux);
		auxRotal.heuristica=auxRotal.tab.calcularHeuristica();
		auxRotal.movimientoDeIteracion="I";
		listaDeMovimientos1.insertar(auxRotal);
		listaDeMovimientos1.avanzar();

	}

	if(tab.comprobarMovimiento(4)){
		Tablero aux;
		copiarTablero(tab, aux);
		aux.rotarPieza(aux.calcularPosicion(aux.VerticePieza()));
		RotaL auxRotal(aux);
		auxRotal.heuristica=auxRotal.tab.calcularHeuristica();
		auxRotal.movimientoDeIteracion="R";
		listaDeMovimientos1.insertar(auxRotal);
		listaDeMovimientos1.avanzar();

	}


}


void RotaL::mostrarTablero(){
	tab.mostrarMatriz();
}


void RotaL::escaladaSimple(RotaL &rota, int &suma, bool &bloqueo, IList <RotaL> &listaDeMovimientos1){
			if(rota.hemosLlegadoObjetivo()){
				cout<<"Hemos llegado al objetivo"<<endl;
			}
			else{
				RotaL r;
				rota.vaciarListaMovimiento(listaDeMovimientos1);
				rota.calcularMovimientos(listaDeMovimientos1);
				listaDeMovimientos1.moverInicio();
				bloqueo=true;		//me ayuda a saber si se ha parado el algoritmo por no encontrar nodos mejores.
				bool bandera=true;
				while(bandera && !listaDeMovimientos1.finLista()){
					listaDeMovimientos1.consultar(r);
					suma++;
						if(r.heuristica<=rota.heuristica){ //Siempre va a ser menor, el unico caso en el que va ha quedarse con el igual es cuando rota, ya que en otro
							bloqueo=false;					//caso es imposible que al trabajar con double genere dos valores iguales.
							bandera=false;
							rota=r;
							cout<<movimientoDeIteracion<<"-";
							escaladaSimple(rota, suma, bloqueo, listaDeMovimientos1);
						}
					listaDeMovimientos1.avanzar();
				}

			}
}

void RotaL::maximaPendiente(RotaL &rota, int &suma, bool &bloqueo, IList <RotaL> &listaDeMovimientos1){
	if(bloqueo==false){
		bloqueo=true;
		if(rota.hemosLlegadoObjetivo()){
			cout<<"Hemos llegado al objetivo"<<endl;
		}
		else{
			RotaL r;
			rota.vaciarListaMovimiento(listaDeMovimientos1);
			rota.calcularMovimientos(listaDeMovimientos1);
			listaDeMovimientos1.moverInicio();
			while(!listaDeMovimientos1.finLista()){
				listaDeMovimientos1.consultar(r);
				suma++;
					if(r.heuristica<=rota.heuristica){ //EL menor igual se hace por el hecho de que solo se va a encontrar en la situacion del igual cuando el vertice coincida
						rota=r;							//pues al trabajar con double la coincidencia de heuristicas en cualquier otro caso es practicamente imposible
						bloqueo=false;					//Ademas, cuando el vertice coincide, una rotacion es mejor siempre que el estado anterior. TAmbien se rotara cuando sea la única opcion que se puede tomar;
					}
				listaDeMovimientos1.avanzar();

			}
			if(bloqueo==false){
				cout<<movimientoDeIteracion<<"-";
			}


			maximaPendiente(rota, suma, bloqueo, listaDeMovimientos1);

		}
	}else{
		cout<<" No hay nodos mejores se para el algoritmo"<<endl;
	}
}


void RotaL::vaciarListaMovimiento(IList <RotaL> &listaDeMovimientos1){
	listaDeMovimientos1.moverInicio();
	while(!listaDeMovimientos1.estaVacia()){
		listaDeMovimientos1.borrar();
	}
}

RotaL::~RotaL() {
	// TODO Auto-generated destructor stub
}

