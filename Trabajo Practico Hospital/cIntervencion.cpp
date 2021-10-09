#include "cIntervencion.h"
//#include "cFecha.h"

cIntervencion::cIntervencion(cFecha FyH, cMedico* medico1) {

	FechayHora = FyH;
	Medico_Principal = medico1;
	Diagnostico = "";
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
	string aux = "\nFecha: " + FechayHora.tm_to_string_Fecha() + "\nDiagnostico: " + Diagnostico + "\nMonto: " + std::to_string(Monto);
	return aux;
}

cMedico* cIntervencion::getMedico()
{
	return Medico_Principal;
}

cFecha cIntervencion::getFecha()
{
	return FechayHora;
}
