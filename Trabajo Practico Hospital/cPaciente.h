#pragma once
#include "enums.h"
#include <string>
#include "cFecha.h"
using namespace std;


class cPaciente
{
private:

	friend class cHistoriaClinica;

	bool Afiliado;
	string DNI;
	cFecha Fecha_nacimiento;
	unsigned int Edad;
	string Nombre;
	unsigned int Numero_afiliado;
	eObraSocial Obra_social;
	eProblema Problema;
	string Sexo;
	bool Ayunas;
	unsigned int valor_hematocrito;
	unsigned int Saturacion;
public:
	cPaciente(bool afiliado, string nombre, cFecha nacimiento, eObraSocial obra_social, string dni, string sexo, eProblema problema, bool ayunas);
	~cPaciente();
	unsigned int NumeroAfiliado();//si esta afiliado le asigna un numero de afiliado
	void Imprimir();
	string to_string();
	void GenerarValores_HematocritoySaturacion();
	int getEdad();
	string getSexo();
	int getSaturacion();
	int getValor_Hematocrito();
	bool getAyuno();
	string getDNI();
	unsigned int CalcularEdad(cFecha* nacimiento);
	eProblema getProblema() { return Problema; };
	string getProblemaString() { return Problema_to_string(Problema); }
	ObraSocial getObra() { return Obra_social; };
	string getNombre() { return Nombre; };
};
//Calcular edad devuelve un int

