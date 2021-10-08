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
	
	static unsigned int Contador;
	
	const unsigned int ID;
	bool Internado;
	cPaciente* m_paciente;//asi tiene toda la infromacion del paciente
	cIntervencion* m_cIntervencion;
	ListaT<cIntervencion>* L_intervenciones;
	
public:
	cHistoriaClinica(cPaciente* paciente,cIntervencion*intervencion,bool internacion);
	virtual ~cHistoriaClinica();
	void setInternado();
	void setAlta();
	cPaciente* getPaciente();
	void Imprimir_Intervenciones(cFecha* fecha);
	void AgregarIntervencion(cIntervencion*nueva_intervencion);
	void Imprimir();
	string to_string();

	ListaT<cIntervencion>* getIntervencion() { return L_intervenciones; }
};

