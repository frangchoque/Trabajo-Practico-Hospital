#include "cConsulta.h"
#include<sstream>

cConsulta::cConsulta(cFecha* FyH, cMedico* medico):cIntervencion(FyH,medico) {
	Indicaciones = "Todavia no hay indicaciones";
}

cConsulta::~cConsulta() {

}

void cConsulta::RealizarIntervencion(cPaciente* paciente) {
	if (paciente->getProblema() == eProblema::DolorPecho)
	{
		FechayHora->tm_to_string_Fecha();
		FechayHora->tm_to_string_Hora();
		Indicaciones = "Necesita realizarse un electrograma , Analisis de Sangre y Radiografia de torax";
		Monto = 100.0;
		
	}
	if (paciente->getProblema() == eProblema::DolorAbdominal)
	{
		FechayHora->tm_to_string_Fecha();
		FechayHora->tm_to_string_Hora();
		Indicaciones = "Necesita realizarse un ecografia Abdominal";
		Monto = 100.0;
	}
	if (paciente->getProblema() == eProblema::Problemas_de_Vision)
	{
		FechayHora->tm_to_string_Fecha();
		FechayHora->tm_to_string_Hora();
		Indicaciones = "Necesita ir a un oftalmologo";
		Monto = 100.0;
	}
	if (paciente->getProblema() == eProblema::COVID)
	{
		FechayHora->tm_to_string_Fecha();
		FechayHora->tm_to_string_Hora();
		Indicaciones = "Necesita ser hospitalizado inmediatamente";
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