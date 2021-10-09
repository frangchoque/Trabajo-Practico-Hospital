#define _CRT_SECURE_NO_WARNINGS
#include "cFecha.h"
cFecha::cFecha() {
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_year;
	fecha.tm_hour = aux->tm_hour;
	fecha.tm_min = aux->tm_min;
	fecha.tm_sec = 0;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
};

cFecha::cFecha(int d, int m, int a, int h, int min) {

	fecha.tm_hour = h;
	fecha.tm_min = min;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m - 1;
	fecha.tm_year = a - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}
void cFecha::ImprimirFecha()
{
	cout << tm_to_string_Fecha();
}
void cFecha::ImprimirHora()
{
	cout << tm_to_string_Hora();
}
string cFecha::tm_to_string_Fecha()
{
	return std::to_string(fecha.tm_mday) + " / " + std::to_string(fecha.tm_mon + 1) + " / " + std::to_string(fecha.tm_year + 1900);
}
string cFecha::tm_to_string_Hora()
{
	return std::to_string(fecha.tm_hour) + " : " + std::to_string(fecha.tm_min);
}
int cFecha::getDia()
{
	return fecha.tm_mday;
}
int cFecha::getMes()
{
	return fecha.tm_mon;
}
int cFecha::getAnio()
{
	return fecha.tm_year;
}

bool cFecha::CompararFecha(cFecha fecha1, cFecha fecha2)
{
	if (fecha1.getDia() == fecha2.getDia() && fecha1.getMes() == fecha2.getMes() && fecha1.getAnio() == fecha2.getAnio()) {
		return true;
	}
	else return false;
}
cFecha::~cFecha()
{

}
/*int cFecha::CalcularEdad(cFecha* nacimiento)
{
	int dif = 0;
	int anio = (nacimiento->fecha.tm_year);
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo el anio actual
	if (nacimiento->fecha.tm_mon < aux->tm_mon)
	{
		dif = (aux->tm_year) - anio;
		return dif;
	}
	else { dif = (aux->tm_year) - anio;
	return dif - 1;//todavia no cumplio anios
	}
	if (anio > aux->tm_year) { return -1;}

}*/
//cFecha::~cFecha()
//{
//}
//;

void cFecha::SetHoy()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_year;
	fecha.tm_hour = aux->tm_hour;
	fecha.tm_min = aux->tm_min;
}

void cFecha::setHora(int num)
{
	fecha.tm_hour + num;
}

int cFecha::getHora()
{
	return fecha.tm_hour;
}

void cFecha::setFecha(int dia, int mes, int anio)
{
	fecha.tm_mon = mes;
	fecha.tm_mday = dia;
	fecha.tm_year = anio;
}
