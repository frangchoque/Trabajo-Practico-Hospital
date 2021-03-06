#pragma once
//#include "cPersonal.h"
#include "cEnfermero.h"
#include "cMedico.h"
#include "cHistoriaClinica.h"
#include "cListaT.h"
#include <string>

class cIntervencion;
using namespace std;

class cSistema//Hacer ingreso paciente que reciba un paciente, busque el historial del paciente, le asigne un médico, el medico lo vea, diagnostique 
{//Lo trate, agregue la intervencion a la lista y lo saque

	ListaT<cPersonal>* Lista_Personal;
	ListaT<cHistoriaClinica>* Lista_Hist_Clinicas;//Que todo lo haga el sistema
	float Ganancia;


public:
	cSistema(ListaT<cHistoriaClinica>* lista_historial_paciente = NULL, ListaT<cPersonal>* lista_personal = NULL);
	~cSistema();

	void IngresarPaciente(cPaciente* paciente, bool CirugiaAmbulatoria = false);//recibe un paciente y le asigna un medico
	void AñadirPersonal(cPersonal* personal);
	cHistoriaClinica* Buscar_por_DNI(string dni);
	void CalcularGananciaTotal();
	void EliminarPersonal(cPersonal* personal);
	void Imprimir();
	void ImprimirProcedimientos(cMedico* medico, cFecha fecha);//imprime los procedimientos de un medico en una fecha
	void AgregarIntervencion_al_Historial(cIntervencion* intervencion, cPaciente* paciente);//agrega la nueva intervencion hecha al paciente en su historial
	string to_string();
	cMedico* Asociar_Medico_Paciente(cPaciente* paciente);
	string Problema_Especilidad(string problema);//dice que medico es el correcto para tratar al paciente
	cPersonal* Buscar_Tipo_Personal(unsigned int Tipo);

};


