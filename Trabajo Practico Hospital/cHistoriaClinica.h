#pragma once
#include "cIntervencion.h"
#include "cPaciente.h"
#include <string>
//#include "enums.h"
//#include  "cFecha.h"
#include "cListaT.h"
using namespace std;
//class cPaciente;



class cHistoriaClinica
{
private:

	static unsigned int Contador;

	//Atributos de paciente
	bool Afiliado;
	string DNI;
	cFecha Fecha_nacimiento;
	unsigned int Edad;
	string Nombre;
	unsigned int Numero_afiliado;
	eObraSocial Obra_social;
	string Sexo;

	const string ID;
	bool Internado;
	ListaT<cIntervencion>* L_intervenciones;

public:
	cHistoriaClinica(cPaciente* paciente);
	virtual ~cHistoriaClinica();
	void setInternado();
	void setAlta();
	void Imprimir_Intervenciones(cFecha fecha);
	void AgregarIntervencion(cIntervencion* nueva_intervencion);
	void Imprimir();
	string to_string();
	//cIntervencion* CrearIntervencion(cFecha FyH, cMedico* medico, unsigned int tipo);
	string getID() { return ID; };
	//void Imprimir_Intervenciones_Medico_Fecha(cMedico* aux, cFecha fecha);


	ListaT<cIntervencion>* getIntervencion() { return L_intervenciones; }
};


