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

void cHistoriaClinica::Imprimir_Intervenciones(cFecha* fecha)
{
	bool aux;
	cIntervencion* intervencion;
	
	for (int i = 0; i < L_intervenciones->getCA(); i++)
	{
		intervencion = L_intervenciones->Buscar_por_pos(i);
		aux = fecha->CompararFecha(fecha, intervencion->getFecha());
		if (aux == true) { intervencion->Imprimir(); }
	}
}





void cHistoriaClinica::AgregarIntervencion(cIntervencion* nueva_intervencion)
{
	L_intervenciones->Agregar(nueva_intervencion);
}

void cHistoriaClinica::Imprimir() {

}


string cHistoriaClinica::to_string() {

	
}