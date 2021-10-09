#include "cHistoriaClinica.h"
#include "cCirugia.h"
#include "cConsulta.h"
#include "cPractica.h"

unsigned int cHistoriaClinica::Contador = 1;
cHistoriaClinica::cHistoriaClinica(cPaciente* paciente, cIntervencion* intervencion,bool internacion):ID(std::to_string(Contador)) {
	
	m_paciente = paciente;
	m_cIntervencion = intervencion;
	Internado = internacion;
	L_intervenciones = new ListaT<cIntervencion>();
	Contador++;

}



cHistoriaClinica::~cHistoriaClinica() {
	delete L_intervenciones;
	delete m_paciente;//Porque queda ligado a la historia clinica
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
	cout << this->to_string() << endl;
}


string cHistoriaClinica::to_string() {
	string aux = m_paciente->to_string() + "\nID: " + ID;
	if (Internado)
		aux += "\nInternado";
	else
		aux += "\nNo internado";
	return aux;
}

cIntervencion* cHistoriaClinica::CrearIntervencion(cFecha FyH, cMedico* medico, unsigned int tipo)
{
	cIntervencion* aux = NULL;
	if (tipo == 0)
	{
		aux = new cPractica(&FyH, medico);
	}
	else if (tipo == 1)
	{
		aux = new cConsulta(&FyH, medico);
	}
	else if (tipo == 2)
	{
		aux = NULL;
		//aux = new cCirugia(&FyH, medico);//Problemas
	}

	return aux;
}
