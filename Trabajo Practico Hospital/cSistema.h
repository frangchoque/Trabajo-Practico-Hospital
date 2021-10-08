#pragma once
#include "cPersonal.h"
#include "cHistoriaClinica.h"

#include "cListaT.h"
#include <string>
#include "cIntervencion.h"
using namespace std;

class cSistema//Hacer ingreso paciente que reciba un paciente, busque el historial del paciente, le asigne un médico, el medico lo vea, diagnostique 
{//Lo trate, agregue la intervencion a la lista y lo saque
	
	ListaT<cPersonal>* Lista_Personal;
	cPersonal* m_personal;
	ListaT<cHistoriaClinica>* Lista_Hist_Clinicas;
	cHistoriaClinica* L_Historias;
	cIntervencion* m_Intervencion;
public:
	cSistema(ListaT<cHistoriaClinica>* lista_historial_paciente, ListaT<cPersonal>* lista_personal);
	~cSistema();
	
	void IngresarPaciente(cPaciente* paciente);//recibe un paciente y le asigna un medico
	void AñadirPersonal(cPersonal* personal);
	cHistoriaClinica* Buscar_por_DNI(string dni);
	void CalcularGananciaTotal();
	void EliminarPersonal();
	void Imprimir();
	void ImprimirProcedimientos(cMedico* medico, cFecha fecha);
	void AgregarIntervencion_al_Historial(cIntervencion*intervencion,cPaciente*paciente);//agrega la nueva intervencion hecha al paciente en su historial
	string to_string();
	void Asociar_Medico_Paciente(cPaciente*paciente);
	string Problema_Especilidad(string problema);//dice que medico es el correcto para tratar al paciente
};

