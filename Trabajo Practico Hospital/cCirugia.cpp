#include "cCirugia.h"

cCirugia::cCirugia(cFecha* FyH, cMedico* medico1,cFecha* alta, cFecha* FyHinicio, unsigned int duracion, bool ambulatoria, cMedico* medicoadicional, cEnfermero* enfermero):cIntervencion(FyH,medico1) {
	Alta = alta;
	Fecha_Hora_inicio = FyHinicio;
	Duracion = duracion;
	Ambulatoria = ambulatoria;
	Procedimiento = "NADA";
	MedicoAdicional = medicoadicional;
	Enfermero = enfermero;
	
}



cCirugia::~cCirugia() {

}





void cCirugia::Imprimir() {

}


void cCirugia::Prequirurgico(cPaciente* paciente) {


}


void cCirugia::RealizarIntervencion() {

}


string cCirugia::to_string() {

	return  NULL;
}