#include "cConsulta.h"
#include "cPaciente.h"
#include<sstream>


cConsulta::cConsulta(cFecha* FyH, cMedico* medico):cIntervencion(FyH,medico) {
	Indicaciones = "Todavia no hay indicaciones";
}

cConsulta::~cConsulta() {

}

void cConsulta::RealizarIntervencion(cPaciente* paciente) {
	if (paciente->getProblema() == eProblema::DolorPecho)
	{
		Indicaciones = "Necesita realizarse un electrograma , Analisis de Sangre y Radiografia de torax";
		//Como pasarle el paciente
		Monto = 100.0;
	}
	if (paciente->getProblema() == eProblema::DolorAbdominal)
	{
		Indicaciones = "Necesita realizarse un ecografia Abdominal";
		//Como pasarle el paciente
		Monto = 100.0;
	}
	if (paciente->getProblema() == eProblema::Problemas_de_Vision)
	{
		Indicaciones = "Necesita ir a un oftalmologo";
		//Como pasarle el paciente
		Monto = 100.0;
	}
	if (paciente->getProblema() == eProblema::COVID)
	{
		Indicaciones = "Necesita ser hospitalizado inmediatamente";
		//Como pasarle el paciente
		Monto = 100.0;

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
	string imprimr = to_string();
	cout << Imprimir;
}