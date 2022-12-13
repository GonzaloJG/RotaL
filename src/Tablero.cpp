//============================================================================
// Name        : Tablero.cpp
// Author      : Manuel David Hernández Pozo / Gonzalo Jiménez Gómez / Victor Manuel Basilio Montes
// Version     :
// Copyright   : Your copyright notice
// Description : Proyecto IASI
//============================================================================

#include "Tablero.h"

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

Tablero::Tablero() {
	// TODO Auto-generated constructor stub
}

void Tablero::asignarValoresCasillas(int fil, int col, int valor){
	Matriz[fil][col].setCordenadaX(fil);
	Matriz[fil][col].setCordenadaY(col);
	Matriz[fil][col].setValor(valor);
}

void Tablero::asignarValoresPieza(int posicion, int fil, int col, int valor){
	Pieza[posicion].setCordenadaX(fil);
	Pieza[posicion].setCordenadaY(col);
	Pieza[posicion].setValor(valor);
}

void Tablero::asignarValoresObjetivo(int posicion, int fil, int col, int valor){
	Objetivo[posicion].setCordenadaX(fil);
	Objetivo[posicion].setCordenadaY(col);
	Objetivo[posicion].setValor(valor);
}

Casilla Tablero::obtenerPieza(int i){
	return Pieza[i];
}

Casilla Tablero::obtenerObjetivo(int i){
	return Objetivo[i];
}

Casilla Tablero::VerticePieza(){
	return verticePieza;
}

void Tablero::mostrarMatriz(){
	for(int i=0; i<TAMPIEZA; i++){
		if(Matriz[Objetivo[i].getCordenadaX()][Objetivo[i].getCordenadaY()].getValor()==0){
			Matriz[Objetivo[i].getCordenadaX()][Objetivo[i].getCordenadaY()].setValor(3);
		}
	}
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cout<<Matriz[i][j].getValor()<<" ";
		}
		cout<<endl;
	}

}

void Tablero::borrarPieza(int x, int y){
		 Matriz[x][y].setValor(0);
}


void Tablero::moverPieza(int direccion){
	int x1,y1,x2, y2;

	for(int i=0; i<TAMPIEZA; i++){
		x1=Pieza[i].getCordenadaX();
		y1=Pieza[i].getCordenadaY();
		borrarPieza(x1,y1);
	}

	switch(direccion){
		case 0:

			for(int i=0; i<TAMPIEZA; i++){
				x1=Pieza[i].getCordenadaX();
				y1=Pieza[i].getCordenadaY();
				x2=x1-1;
				y2=y1;

				Pieza[i].setCordenadaX(x2);
				Pieza[i].setCordenadaY(y2);

				Matriz[x2][y2].setValor(2);
			}
			verticePieza.setCordenadaX(verticePieza.getCordenadaX()-1);

			break;

		case 1:
			for(int i=0; i<TAMPIEZA; i++){
				x1=Pieza[i].getCordenadaX();
				y1=Pieza[i].getCordenadaY();
				x2=x1+1;
				y2=y1;

				Pieza[i].setCordenadaX(x2);
				Pieza[i].setCordenadaY(y2);

				Matriz[x2][y2].setValor(2);

			}
			verticePieza.setCordenadaX(verticePieza.getCordenadaX()+1);

			break;

		case 2:
			for(int i=0; i<TAMPIEZA; i++){
				x1=Pieza[i].getCordenadaX();
				y1=Pieza[i].getCordenadaY();
				x2=x1;
				y2=y1+1;

				Pieza[i].setCordenadaX(x2);
				Pieza[i].setCordenadaY(y2);

				Matriz[x2][y2].setValor(2);
			}
			verticePieza.setCordenadaY(verticePieza.getCordenadaY()+1);

			break;

		case 3:
			for(int i=0; i<TAMPIEZA; i++){
				x1=Pieza[i].getCordenadaX();
				y1=Pieza[i].getCordenadaY();
				x2=x1;
				y2=y1-1;

				Pieza[i].setCordenadaX(x2);
				Pieza[i].setCordenadaY(y2);

				Matriz[x2][y2].setValor(2);
			}
			verticePieza.setCordenadaY(verticePieza.getCordenadaY()-1);

			break;
	}
}


int Tablero::consultarValor(int x, int y){
	return Matriz[x][y].getValor();
}

bool Tablero::comprobarMovimiento(int direccion){
	bool bandera=true;
	int auxX;
	int auxY;
	switch(direccion){
		case 0://arriba
			for(int i=0; i<TAMPIEZA && bandera; i++){
				auxX=Pieza[i].getCordenadaX()-1;
				auxY=Pieza[i].getCordenadaY();
				if(consultarValor(auxX,auxY)==1){
					bandera=false;
				}
			}

			break;
		case 1://abajo
			for(int i=0; i<TAMPIEZA && bandera; i++){
				auxX=Pieza[i].getCordenadaX()+1;
				auxY=Pieza[i].getCordenadaY();
				if(consultarValor(auxX,auxY)==1){
					bandera=false;
				}
			}

			break;
		case 2://Derecha
			for(int i=0; i<TAMPIEZA && bandera; i++){
				auxX=Pieza[i].getCordenadaX();
				auxY=Pieza[i].getCordenadaY()+1;
				if(consultarValor(auxX,auxY)==1){
					bandera=false;
				}
			}

			break;
		case 3://Izquierda
			for(int i=0; i<TAMPIEZA && bandera; i++){
				auxX=Pieza[i].getCordenadaX();
				auxY=Pieza[i].getCordenadaY()-1;
				if(consultarValor(auxX,auxY)==1){
					bandera=false;
				}
			}

			break;
		case 4://Rotar
			int posicionPieza=calcularPosicion(verticePieza);
			if(!comprobarRotar(posicionPieza)){
				bandera=false;
			}
			break;
	}
	return bandera;
}

/*
 * Servira para calcular el vertice de la pieza
 */
bool Tablero::esVertice(Casilla cas){
	int x1, y1;
	bool encontrado = false;
	x1=cas.getCordenadaX();
	y1=cas.getCordenadaY();

	if(Matriz[x1-1][y1].getValor()== 2 || Matriz[x1+1][y1].getValor() == 2 ){
		if (Matriz[x1][y1-1].getValor()== 2 || Matriz[x1][y1+1].getValor() == 2 ){
			encontrado = true;
		}
	}

	return encontrado;
}


int Tablero::calcularPosicion(Casilla vertice){
	int x1, y1;
	x1=vertice.getCordenadaX();
	y1=vertice.getCordenadaY();
	int posicion;

	if(piezaInvertida(vertice)==false){
		if(Matriz[x1+1][y1].getValor()==2){ //Comprobamos abajo
			if(Matriz[x1][y1-1].getValor()==2){ //Comprobamos izquierda
				posicion = 0; 	  //--
								  // -
								  // -

			}
			else {
				posicion = 3;     //- - -
								  //-

			}

		}else{
			if(Matriz[x1][y1-1].getValor()==2){ //Comprobamos izquierda
				posicion = 1; 	 //    -
								 //- - -

			}
			else {
				posicion = 2;    //-
								 //-
								 //- -

				}
		}
	}else{
		if(Matriz[x1+1][y1].getValor()==2){ //Comprobamos abajo
			if(Matriz[x1][y1+1].getValor()==2){ //Comprobamos derecha
				posicion = 4; 	  // --
								  // -
								  // -
			}
			else {
				posicion = 5;     //- - -
								  //    -
			}

		}else{
			if(Matriz[x1][y1+1].getValor()==2){ //Comprobamos derecha
				posicion = 7; 	 //-
			}	     			 //- - -
			else {
				posicion = 6;    //  -
								 //  -
								 //- -

			}
		}
	}
	return posicion;

	}


	bool Tablero::piezaInvertida(Casilla vertice){
		bool bandera=true;
		int x1, y1;
		x1=vertice.getCordenadaX();
		y1=vertice.getCordenadaY();
		if(Matriz[x1+1][y1].getValor()==2 && Matriz[x1][y1-1].getValor()==2 && Matriz[x1+2][y1].getValor()==2){
			bandera=false;   		//--
									// -
									// -
		}
		if(Matriz[x1-1][y1].getValor()==2 && Matriz[x1][y1-1].getValor()==2 && Matriz[x1][y1-2].getValor()==2){
			bandera=false;
							   //    -
						   	   //- - -
		}
		if(Matriz[x1-1][y1].getValor()==2 && Matriz[x1][y1+1].getValor()==2 && Matriz[x1-2][y1].getValor()==2){
			bandera=false;
							   //-
						   	   //-
						   	   //- -
		}
		if(Matriz[x1+1][y1].getValor()==2 && Matriz[x1][y1+1].getValor()==2 && Matriz[x1][y1+2].getValor()==2){
			bandera=false;
							   //- - -
						   	   //-
		}
		return bandera;
	}


void Tablero::calcularVerticePieza(){
	int j;
	for(int i=0; i<TAMPIEZA; i++){
		if(esVertice(Pieza[i])){
			j=i;
		}
	}
	verticePieza.setCordenadaX(Pieza[j].getCordenadaX());
	verticePieza.setCordenadaY(Pieza[j].getCordenadaY());
	verticePieza.setValor(2);

}

bool Tablero::comprobarRotar(int direccion){
	bool bandera=true;
	int x1 = verticePieza.getCordenadaX();
	int y1 = verticePieza.getCordenadaY();

	switch(direccion){
		case 0:
			for(int i=0; i<TAMPIEZA && bandera;i++){

				if(Pieza[i].getCordenadaX()==x1+1 && Pieza[i].getCordenadaY()==y1){
					if(Matriz[Pieza[i].getCordenadaX()-1][Pieza[i].getCordenadaY()-1].getValor()==1){
						bandera=false;
					}

				}

				if(Pieza[i].getCordenadaX()==x1+2 && Pieza[i].getCordenadaY()==y1){
					if(Matriz[Pieza[i].getCordenadaX()-2][Pieza[i].getCordenadaY()-2].getValor()==1){
						bandera=false;
					}

				}

				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1-1){
					if(Matriz[Pieza[i].getCordenadaX()-1][Pieza[i].getCordenadaY()+1].getValor()==1){
						bandera=false;
					}

				}

			}

			break;
		case 1:

			for(int i=0; i<TAMPIEZA && bandera;i++){

				if(Pieza[i].getCordenadaX()==x1-1 && Pieza[i].getCordenadaY()==y1){
					if(Matriz[Pieza[i].getCordenadaX()+1][Pieza[i].getCordenadaY()+1].getValor()==1){
						bandera=false;
					}
				}

				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1-1){
					if(Matriz[Pieza[i].getCordenadaX()-1][Pieza[i].getCordenadaY()+1].getValor()==1){
						bandera=false;
					}

				}

				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1-2){
					if(Matriz[Pieza[i].getCordenadaX()-2][Pieza[i].getCordenadaY()+2].getValor()==1){
						bandera=false;
					}
				}
			}

			break;
		case 2:

			for(int i=0; i<TAMPIEZA && bandera;i++){

				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1+1){
					if(Matriz[Pieza[i].getCordenadaX()+1][Pieza[i].getCordenadaY()-1].getValor()==1){
						bandera=false;
					}
				}

				if(Pieza[i].getCordenadaX()==x1-2 && Pieza[i].getCordenadaY()==y1){
					if(Matriz[Pieza[i].getCordenadaX()+2][Pieza[i].getCordenadaY()+2].getValor()==1){
						bandera=false;
					}

				}

				if(Pieza[i].getCordenadaX()==x1-1 && Pieza[i].getCordenadaY()==y1){
					if(Matriz[Pieza[i].getCordenadaX()+1][Pieza[i].getCordenadaY()+1].getValor()==1){
						bandera=false;
					}
				}
			}

			break;
		case 3:

			for(int i=0; i<TAMPIEZA && bandera;i++){
				if(Pieza[i].getCordenadaX()==x1+1 && Pieza[i].getCordenadaY()==y1 && bandera){
					if(Matriz[Pieza[i].getCordenadaX()-1][Pieza[i].getCordenadaY()-1].getValor()==1){
						bandera=false;
					}
				}

				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1+1 && bandera){
					if(Matriz[Pieza[i].getCordenadaX()+1][Pieza[i].getCordenadaY()-1].getValor()==1){
						bandera=false;
					}

				}

				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1+2 && bandera){
					if(Matriz[Pieza[i].getCordenadaX()+2][Pieza[i].getCordenadaY()-2].getValor()==1){
						bandera=false;
					}
				}

			}
			break;
		case 4:
			for(int i=0; i<TAMPIEZA && bandera;i++){
				if(Pieza[i].getCordenadaX()==x1+1 && Pieza[i].getCordenadaY()==y1){
					if(Matriz[Pieza[i].getCordenadaX()-1][Pieza[i].getCordenadaY()-1].getValor()==1){
						bandera=false;
					}
				}

				if(Pieza[i].getCordenadaX()==x1+2 && Pieza[i].getCordenadaY()==y1){
					if(Matriz[Pieza[i].getCordenadaX()-2][Pieza[i].getCordenadaY()-2].getValor()==1){
						bandera=false;
					}
				}

				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1+1){
					if(Matriz[Pieza[i].getCordenadaX()+1][Pieza[i].getCordenadaY()+1].getValor()==1){
						bandera=false;
					}
				}

			}
			break;

			case 5:
				for(int i=0; i<TAMPIEZA && bandera;i++){
					if(Pieza[i].getCordenadaX()==x1+1 && Pieza[i].getCordenadaY()==y1){
						if(Matriz[Pieza[i].getCordenadaX()-1][Pieza[i].getCordenadaY()-1].getValor()==1){
							bandera=false;
						}
					}

					if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1-1){
						if(Matriz[Pieza[i].getCordenadaX()-1][Pieza[i].getCordenadaY()+1].getValor()==1){
							bandera=false;
						}

					}

					if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1-2){
						if(Matriz[Pieza[i].getCordenadaX()-2][Pieza[i].getCordenadaY()+2].getValor()==1){
							bandera=false;
						}
					}
				}
				break;

			case 6:

				for(int i=0; i<TAMPIEZA && bandera;i++){
					if(Pieza[i].getCordenadaX()==x1-1 && Pieza[i].getCordenadaY()==y1 && bandera){
						if(Matriz[Pieza[i].getCordenadaX()+1][Pieza[i].getCordenadaY()+1].getValor()==1){
							bandera=false;
						}
					}

					if(Pieza[i].getCordenadaX()==x1-2 && Pieza[i].getCordenadaY()==y1 && bandera){
						if(Matriz[Pieza[i].getCordenadaX()+2][Pieza[i].getCordenadaY()+2].getValor()==1){
							bandera=false;
						}
					}

					if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1-1 && bandera){
						if(Matriz[Pieza[i].getCordenadaX()-1][Pieza[i].getCordenadaY()+1].getValor()==1){
							bandera=false;
						}

					}


				}

				break;
			case 7:

				for(int i=0; i<TAMPIEZA && bandera;i++){

					if(Pieza[i].getCordenadaX()==x1+1 && Pieza[i].getCordenadaY()==y1 && bandera){
						if(Matriz[Pieza[i].getCordenadaX()+1][Pieza[i].getCordenadaY()+1].getValor()==1){
							bandera=false;
						}
					}
					if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1+1 && bandera){
						if(Matriz[Pieza[i].getCordenadaX()+1][Pieza[i].getCordenadaY()-1].getValor()==1){
							bandera=false;
						}
					}

					if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1+2 && bandera){
						if(Matriz[Pieza[i].getCordenadaX()+2][Pieza[i].getCordenadaY()-2].getValor()==1){
							bandera=false;
						}
					}

				}
				break;
		}

	return bandera;
}



void Tablero::rotarPieza(int direccion){
	int x1= verticePieza.getCordenadaX();
	int y1 = verticePieza.getCordenadaY();

	switch(direccion){
		case 0:

			for(int i=0; i<TAMPIEZA;i++){
				bool bandera=true;	//esta bandera servira para que no haya confrontacion en las casillas

				if(Pieza[i].getCordenadaX()==x1+1 && Pieza[i].getCordenadaY()==y1 && bandera){
					borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()-1);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()-1);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;

				}
				if(Pieza[i].getCordenadaX()==x1+2 && Pieza[i].getCordenadaY()==y1 && bandera){
					borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()-2);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()-2);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;
				}

				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1-1 && bandera){

					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()-1);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()+1);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;

				}
			}

			break;
		case 1:

			for(int i=0; i<TAMPIEZA;i++){
				bool bandera=true;	//esta bandera servira para que no haya confrontacion en las casillas
				if(Pieza[i].getCordenadaX()==x1-1 && Pieza[i].getCordenadaY()==y1 && bandera){
					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()+1);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()+1);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;

				}
				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1-1 && bandera){
					borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()-1);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()+1);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;

				}

				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1-2 && bandera){
					borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()-2);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()+2);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;

				}

			}

			break;
		case 2:

			for(int i=0; i<TAMPIEZA;i++){
				bool bandera=true;	//esta bandera servira para que no haya confrontacion en las casillas

				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1+1 && bandera){

					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()+1);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()-1);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;

				}

				if(Pieza[i].getCordenadaX()==x1-2 && Pieza[i].getCordenadaY()==y1 && bandera){
					borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()+2);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()+2);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;

				}

				if(Pieza[i].getCordenadaX()==x1-1 && Pieza[i].getCordenadaY()==y1 && bandera){
					borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()+1);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()+1);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;

				}

			}

			break;
		case 3:

			for(int i=0; i<TAMPIEZA;i++){
				bool bandera=true;	//esta bandera servira para que no haya confrontacion en las casillas
					if(Pieza[i].getCordenadaX()==x1+1 && Pieza[i].getCordenadaY()==y1 && bandera){

						Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()-1);
						Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()-1);
						Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
						bandera=false;

					}
					if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1+1 && bandera){
						borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
						Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()+1);
						Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()-1);
						Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
						bandera=false;

					}

					if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1+2 && bandera){
						borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
						Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()+2);
						Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()-2);
						Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
						bandera=false;

					}

			}
			break;

		case 4:
			for(int i=0; i<TAMPIEZA ;i++){
				bool bandera=true;	//esta bandera servira para que no haya confrontacion en las casillas
				if(Pieza[i].getCordenadaX()==x1+1 && Pieza[i].getCordenadaY()==y1 && bandera){

					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()-1);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()-1);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;
				}

				if(Pieza[i].getCordenadaX()==x1+2 && Pieza[i].getCordenadaY()==y1 && bandera){
					borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()-2);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()-2);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;
				}

				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1+1 && bandera){
					borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()+1);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()-1);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;
				}

			}
			break;

			case 5:
				for(int i=0; i<TAMPIEZA ;i++){
					bool bandera=true;	//esta bandera servira para que no haya confrontacion en las casillas
					if(Pieza[i].getCordenadaX()==x1+1 && Pieza[i].getCordenadaY()==y1 && bandera){
						borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
						Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()-1);
						Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()-1);
						Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
						bandera=false;
					}

					if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1-1 && bandera){
						borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
						Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()-1);
						Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()+1);
						Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
						bandera=false;

					}

					if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1-2 && bandera){
						borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
						Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()-2);
						Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()+2);
						Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
						bandera=false;
					}
				}
				break;

			case 6:

				for(int i=0; i<TAMPIEZA;i++){
					bool bandera=true;	//esta bandera servira para que no haya confrontacion en las casillas
					if(Pieza[i].getCordenadaX()==x1-1 && Pieza[i].getCordenadaY()==y1 && bandera){
						borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
						Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()+1);
						Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()+1);
						Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
						bandera=false;
					}

					if(Pieza[i].getCordenadaX()==x1-2 && Pieza[i].getCordenadaY()==y1 && bandera){
						borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
						Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()+2);
						Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()+2);
						Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
						bandera=false;
					}

					if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1-1 && bandera){
						borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
						Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()-1);
						Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()+1);
						Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
						bandera=false;

					}


				}

				break;
		case 7:

			for(int i=0; i<TAMPIEZA;i++){
				bool bandera=true;	//esta bandera servira para que no haya confrontacion en las casillas
				if(Pieza[i].getCordenadaX()==x1-1 && Pieza[i].getCordenadaY()==y1 && bandera){
					borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()+1);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()+1);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;
				}
				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1+1 && bandera){
					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()+1);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()-1);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;
				}

				if(Pieza[i].getCordenadaX()==x1 && Pieza[i].getCordenadaY()==y1+2 && bandera){
					borrarPieza(Pieza[i].getCordenadaX(),Pieza[i].getCordenadaY());
					Pieza[i].setCordenadaX(Pieza[i].getCordenadaX()+2);
					Pieza[i].setCordenadaY(Pieza[i].getCordenadaY()-2);
					Matriz[Pieza[i].getCordenadaX()][Pieza[i].getCordenadaY()].setValor(2);
					bandera=false;
				}

			}
			break;
			}
}

bool Tablero::esVerticeObjetivo(Casilla cas){
	int x1, y1;
	bool encontrado = false;
	x1=cas.getCordenadaX();
	y1=cas.getCordenadaY();

	if(Matriz[x1-1][y1].getValor()== 3 || Matriz[x1+1][y1].getValor() == 3 ){
		if (Matriz[x1][y1-1].getValor()== 3 || Matriz[x1][y1+1].getValor() == 3 ){
			encontrado = true;
		}
	}

	return encontrado;

	}


void Tablero::calcularVerticeObjetivo(){
	int j;
	for(int i=0; i<TAMPIEZA; i++){
		if(esVerticeObjetivo(Objetivo[i])){
			j=i;
		}
	}
	verticeObjetivo.setCordenadaX(Objetivo[j].getCordenadaX());
	verticeObjetivo.setCordenadaY(Objetivo[j].getCordenadaY());
	verticeObjetivo.setValor(3);

}



 double Tablero::calcularHeuristica(){
	double distancia=0;
	distancia=(sqrt(pow(verticePieza.getCordenadaX()-verticeObjetivo.getCordenadaX(),2)+pow(verticePieza.getCordenadaY()-verticeObjetivo.getCordenadaY(),2)));
	return distancia;
}



Tablero::~Tablero() {
	// TODO Auto-generated destructor stub
}

