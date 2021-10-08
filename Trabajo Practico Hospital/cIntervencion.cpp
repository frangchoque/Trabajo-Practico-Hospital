#include "cIntervencion.h"

cIntervencion::cIntervencion(cFecha*FyH,cMedico* medico1) {

	FechayHora = new cFecha(*FyH);
	m_cMedico = medico1;
	Diagnostico = "Todavia no hay diagnostico";
	Monto = 0.0;
}



cIntervencion::~cIntervencion() {

}





void cIntervencion::Imprimir() {
	cout << to_string() << endl;
}


void cIntervencion::RealizarIntervencion(cPaciente* paciente) {

}


string cIntervencion::to_string() {
	string aux = "\nFecha: " + FechayHora->tm_to_string_Fecha() + "\nDiagnostico: " + Diagnostico + "\nMonto: " + std::to_string(Monto);
	return aux;
}
