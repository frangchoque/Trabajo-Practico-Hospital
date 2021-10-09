#include "cConsulta.h"
#include "cPaciente.h"
#include "cMedico.h"
#include<sstream>


cConsulta::cConsulta(cFecha FyH, cMedico* medico) :cIntervencion(FyH, medico) {
	Indicaciones = "";
}

cConsulta::~cConsulta() {

}

void cConsulta::RealizarIntervencion(cPaciente* paciente) {

	if (paciente->getProblema() == eProblema::Tos)
	{
		Indicaciones = Medico_Principal->ModificarIndicaciones(paciente->getProblema());
		Monto = FuncionRand(3000, 500);
	}
	if (paciente->getProblema() == eProblema::Fiebre)
	{
		Indicaciones = Medico_Principal->ModificarIndicaciones(paciente->getProblema());
		Monto = FuncionRand(2000, 500);
	}

}

string cConsulta::to_string() {
	stringstream ss;

	ss << "Diagnostico: " << Diagnostico << endl;
	ss << "Indicaciones: " << Indicaciones << endl;
	ss << "Monto: " << Monto << endl;
	return ss.str();

}

void cConsulta::Imprimir() {
	string imprimir = ((cIntervencion*)this)->to_string() + this->to_string();
	cout << imprimir << endl;
}