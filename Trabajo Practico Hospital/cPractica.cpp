#include "cPractica.h"


cPractica::cPractica(cFecha* FyH, cMedico* medico1):cIntervencion(FyH,medico1) {
	Autorizacion_Obra_social = false;
	Informe = "NADA";
}



cPractica::~cPractica() {

}





void cPractica::Imprimir() {

}


void cPractica::PedirAutorizacion() {

}


void cPractica::RealizarIntervencion() {

}


string cPractica::to_string() {

	return  NULL;
}