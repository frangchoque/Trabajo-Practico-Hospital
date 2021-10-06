#include "cPractica.h"


cPractica::cPractica(cFecha* FyH, cMedico* medico1):cIntervencion(FyH,medico1) {
	Autorizacion_Obra_social = false;
	Informe = "NADA";
}



cPractica::~cPractica() {

}


void cPractica::PedirAutorizacion(cPaciente* paciente) {
	if(paciente->getObra_Social()::)



}


void cPractica::RealizarIntervencion(cPaciente* paciente) {
	
}


string cPractica::to_string() {

	return  NULL;
}

void cPractica::Imprimir() {

}