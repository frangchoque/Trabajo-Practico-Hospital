#include "cHistoriaClinica.h"
unsigned int cHistoriaClinica::Contador = 0;
cHistoriaClinica::cHistoriaClinica(cPaciente* paciente, cIntervencion* intervencion,bool internacion):ID(Contador++) {
	
	m_paciente = paciente;
	m_cIntervencion = intervencion;
	Internado = internacion;
	L_intervenciones = new ListaT<cIntervencion>();


}



cHistoriaClinica::~cHistoriaClinica() {

}





void cHistoriaClinica::Imprimir() {

}


string cHistoriaClinica::to_string() {

	
}