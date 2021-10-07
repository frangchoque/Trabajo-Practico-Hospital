#pragma once
#include "cPersonal.h"
#include "cHistoriaClinica.h"
#include "cListaT.h"
#include <string>
using namespace std;

class cSistema//Hacer ingreso paciente que reciba un paciente, busque el historial del paciente, le asigne un médico, el medico lo vea, diagnostique 
{//Lo trate, agregue la intervencion a la lista y lo saque
	
	ListaT<cHistoriaClinica>* Lista_Historias_Clinicas;
	ListaT<cPersonal>* Lista_Personal;

public:
	cSistema();
	~cSistema();
	

	void AgregarHistoriaClinica(cPaciente* paciente);
	void AñadirPersonal(cPersonal* personal);
	cHistoriaClinica* Buscar_por_DNI(string dni);
	void CalcularFananciaTotal();
	void EliminarPersonal();
	void Imprimir();
	void ImprimirProcedimientos(cMedico* medico, cFecha fecha);
	string to_string();

};

