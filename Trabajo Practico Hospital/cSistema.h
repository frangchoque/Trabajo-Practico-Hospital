#pragma once
#include "cPersonal.h"
#include "cHistoriaClinica.h"
#include "cLista_HIstorias_Clinicas.h"
#include "cListaT.h"
#include <string>
using namespace std;

class cSistema//Hacer ingreso paciente que reciba un paciente, busque el historial del paciente, le asigne un médico, el medico lo vea, diagnostique 
{//Lo trate, agregue la intervencion a la lista y lo saque
	
	ListaT<cPersonal>* Lista_Personal;
	cLista_HIstorias_Clinicas* historial;

public:
	cSistema(cLista_HIstorias_Clinicas* lista_historial, ListaT<cPersonal>* lista_personal);
	~cSistema();
	
	void IngresarPaciente(cPaciente* paciente);
	void AñadirPersonal(cPersonal* personal);
	cHistoriaClinica* Buscar_por_DNI(string dni);
	void CalcularFananciaTotal();
	void EliminarPersonal();
	void Imprimir();
	void ImprimirProcedimientos(cMedico* medico, cFecha fecha);
	void AgregarIntervencion_al_Historial(cIntervencion*intervencion,cPaciente*paciente);//agrega la intervencion hecha al paciente en su historial
	string to_string();

};

