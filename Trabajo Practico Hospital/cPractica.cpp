#include "cPractica.h"
#include "cPaciente.h"
#include "cMedico.h"
#include<sstream>

cPractica::cPractica(cFecha FyH, cMedico* medico1) :cIntervencion(FyH, medico1) {
	Autorizacion_Obra_social = false;
	Informe = " ";
}



cPractica::~cPractica() {

}


void cPractica::PedirAutorizacion(cPaciente* paciente) {
	int aux = rand() % 2;
	if (paciente->getObra() == eObraSocial::CBA || paciente->getObra() == eObraSocial::DEF)
	{
		if (aux == 0)
		{
			Autorizacion_Obra_social = true;
		}
		else
		{
			Autorizacion_Obra_social = false;
		}
	}

	else if (paciente->getObra() == eObraSocial::HIG || paciente->getObra() == eObraSocial::OSDE)
	{
		if (aux == 0)
		{
			Autorizacion_Obra_social = false;
		}
		else
		{
			Autorizacion_Obra_social = true;
		}
	}


}


void cPractica::RealizarIntervencion(cPaciente* paciente)
{
	if (paciente->getProblema() == eProblema::Problemas_de_Vision)
	{
		Informe = "\nAl Paciente: " + paciente->getDNI() + "se le diagnostico: " + paciente->getProblemaString() + "por el especialista:  " + std::to_string(Medico_Principal->getMatricula());
	}
	if (paciente->getProblema() == eProblema::COVID)
	{
		Informe = "Al Paciente: " + paciente->getDNI() + "Se le diagnostico: " + paciente->getProblemaString() + "por el especialista:  " + std::to_string(Medico_Principal->getMatricula());
	}
	Diagnostico = paciente->getProblemaString();
}