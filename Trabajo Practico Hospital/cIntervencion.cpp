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

}


void cIntervencion::RealizarIntervencion(cPaciente* paciente) {

}


string cIntervencion::to_string() {


}
