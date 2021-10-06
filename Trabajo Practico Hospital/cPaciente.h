#pragma once
#include "enums.h"
#include <string>
#include "cFecha.h"
using namespace std;

class cPaciente
{
private:
	bool Afiliado;
	string DNI;
	cFecha* Fecha_nacimiento;
	int Edad;
	string Nombre;
	unsigned int Numero_afiliado;
	eObraSocial Obra_social;
	eProblema Problema;
	char Sexo;
	bool Ayunas;
	int valor_hematocrito;
	int Saturacion;
public:
	cPaciente(bool afiliado,string nombre,cFecha*nacimiento,eObraSocial obra_social,string dni,char sexo,eProblema problema,bool ayunas);
	virtual ~cPaciente();
	void NumeroAfiliado();//si esta afiliado le asigna un numero de afiliado
	void Imprimir();
	string to_string();
	void GenerarValores_HematocritoySaturacion();
	int getEdad();
	char getSexo();
	int getSaturacion();
	int getValor_Hematocrito();
	bool getAyuno();

};

