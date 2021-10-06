#pragma once
#include "cIntervencion.h"
#include "cPaciente.h"
#include <string>
#include "enums.h"
#include  "cFecha.h"
#include "cListaT.h"
using namespace std;

class cHistoriaClinica
{
private:
	/**
	 * si no esta afiliado, no tiene numero de afiliado
	 */
	//bool Afiliado;
	static unsigned int Contador;
	//const string DNI;
	//const cFecha Fecha_nacimiento;
	const unsigned int ID;
	bool Internado;
	//string Nombre;
	//unsigned int Numero_afiliado;
	//eObraSocial Obra_social;
	//string Sexo;
	cPaciente* m_paciente;//asi tiene toda la infromacion del paciente
	cIntervencion* m_cIntervencion;
	ListaT<cIntervencion>* L_intervenciones;
	
public:
	cHistoriaClinica(cPaciente* paciente,cIntervencion*intervencion,bool internacion);
	virtual ~cHistoriaClinica();
	void setInternado();
	void setAlta();

	void Imprimir();
	string to_string();


};

