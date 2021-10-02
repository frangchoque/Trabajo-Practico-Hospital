#pragma once
#include <time.h>
#include <iostream>
#include <sstream>

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
	int CalcularEdad(cFecha*nacimiento);
	void SetHoy();
	//~cFecha();
};

