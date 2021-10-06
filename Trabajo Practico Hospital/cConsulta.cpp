#include "cConsulta.h"


cConsulta::cConsulta(cFecha* FyH, cMedico* medico):cIntervencion(FyH,medico) {
	Indicaciones = "Todavia no hay indicaciones";
}

cConsulta::~cConsulta() {

}

void cConsulta::RealizarIntervencion(cPaciente* paciente) {
	if (paciente->getProblema()::Fiebre)
	{
		Indicaciones = "Tomar Paracetamol";
	}
	else if (paciente->getProblema()::Tos)
	{
		Indicaciones = "Beber te con miel y guarar reposo";
	}
	
}

string cConsulta::to_string() {


}

void cConsulta::Imprimir() {

}