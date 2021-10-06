#pragma once
#include <time.h>
#include <string>
#include <iostream>

using namespace std;

class cFecha
{
	tm fecha;
public:
	//constructor de inicio en la fecha y hora actual
	cFecha();
	//constructor de inicio con dia mes, anio y la hora
	cFecha(int d, int m, int a,int h,int min);
	
	//cambia la fecha a fecha actual
	//void setHoy(); no se si la vamos a usar
	void ImprimirFecha();
	void ImprimirHora();
	string tm_to_string_Fecha();
	string tm_to_string_Hora();
	int getDia();
	int getMes();
	int getAnio();

	~cFecha();
};

