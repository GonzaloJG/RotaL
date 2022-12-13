//============================================================================
// Name        : Principal.cpp
// Author      : Manuel David Hernández Pozo / Gonzalo Jiménez Gómez / Victor Manuel Basilio Montes
// Version     :
// Copyright   : Your copyright notice
// Description : Proyecto IASI
//============================================================================

#include "Tablero.h"
#include "RotaL.h"
#include <iostream>
#include <ctime>
#include "IList.h"
using namespace std;

int main() {

	string nombreFicheros[12];
	nombreFicheros[0]="Ficheros/ROTAL1.txt";
	nombreFicheros[1]="Ficheros/ROTAL2.txt";
	nombreFicheros[2]="Ficheros/ROTAL3.txt";
	nombreFicheros[3]="Ficheros/ROTAL4.txt";
	nombreFicheros[4]="Ficheros/ROTAL5.txt";
	nombreFicheros[5]="Ficheros/ROTAL6.txt";
	nombreFicheros[6]="Ficheros/ROTAL7.txt";
	nombreFicheros[7]="Ficheros/ROTAL8.txt";
	nombreFicheros[8]="Ficheros/ROTAL9.txt";
	nombreFicheros[9]="Ficheros/ROTAL10.txt";
	nombreFicheros[10]="Ficheros/ROTAL11.txt";
	nombreFicheros[11]="Ficheros/ROTAL12.txt";

	Tablero t;
	RotaL r(t);
	IList <RotaL> listaMovimientos;
	bool bloqueo;

	for(int i=0; i<12; i++){

		cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
		cout<<"------------------------ "<< nombreFicheros[i] <<" --------------------------------------------------"<<endl;
		cout<<"-----------------------------------------------------------------------------------------------------"<<endl;

		bloqueo=true;
		string tablero=nombreFicheros[i];
		r.cargarTablero(tablero);
		cout<<"ESCALADA SIMPLE"<<endl;
		int suma=0;
		cout<<"Camino: ";
		unsigned t0=clock();
		r.escaladaSimple(r, suma, bloqueo, listaMovimientos);
		unsigned t1=clock();
		double time = (double (t1-t0)/CLOCKS_PER_SEC);
		if(bloqueo==true){
			cout<<" No hay nodos mejores se para el algoritmo"<<endl;
		}
		cout<<"Los nodos generados son: "<<suma<<endl;
		cout<<"Tiempo de ejecucion "<<time*1000<<" milisegundos"<<endl;


		bloqueo=false;
		r.cargarTablero(tablero);
		cout<<endl;

		cout<<"MAXIMA PENDIENTE"<<endl;
		suma=0;
		cout<<"Camino: ";
		t0=clock();
		r.maximaPendiente(r, suma, bloqueo, listaMovimientos);
		t1=clock();
		time = (double (t1-t0)/CLOCKS_PER_SEC);
		cout<<"Los nodos generados son: "<<suma<<endl;
		cout<<"Tiempo de ejecucion "<<time*1000<<" milisegundos"<<endl;

		cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
		cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
		cout<<endl;
	}


}
