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

void cHistoriaClinica::setInternado()
{
	Internado = true;
}

void cHistoriaClinica::setAlta()
{
	Internado = false;
}

cPaciente* cHistoriaClinica::getPaciente()
{
	return m_paciente;
}





void cHistoriaClinica::Imprimir() {

}


string cHistoriaClinica::to_string() {

	
}