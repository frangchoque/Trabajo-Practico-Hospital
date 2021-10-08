#include "cPractica.h"
#include<sstream>

cPractica::cPractica(cFecha* FyH, cMedico* medico1):cIntervencion(FyH,medico1) {
	Autorizacion_Obra_social = false;
	Informe = "NADA";
}



cPractica::~cPractica() {

}


void cPractica::PedirAutorizacion(cPaciente* paciente) {
	int aux = rand % 1;
	if (paciente->getObra() == eObraSocial::CBA)
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
	else if (paciente->getObra() == eObraSocial::DEF)
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
	else if (paciente->getObra() == eObraSocial::HIG)
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
	else if (paciente->getObra() == eObraSocial::OSDE)
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

}


void cPractica::RealizarIntervencion(cPaciente* paciente) {
	if (paciente->getProblema() == eProblema::DolorPecho)
	{
		FechayHora->tm_to_string_Fecha();
		FechayHora->tm_to_string_Hora();
		Informe = "Al Paciente: " << paciente->getDNI() << "Se le diagnostico: " << paciente->getProblemaString() << "por el especialista:  " <<m_cMedico->getMatricula()<< endl;

	}
	if (paciente->getProblema() == eProblema::DolorAbdominal)
	{
		FechayHora->tm_to_string_Fecha();
		FechayHora->tm_to_string_Hora();
		Informe = "Al Paciente: " << paciente->getDNI() << "Se le diagnostico: " << paciente->getProblemaString() << "por el especialista:  " << m_cMedico->getMatricula() << endl;

	if (paciente->getProblema() == eProblema::Problemas_de_Vision)
	{
		FechayHora->tm_to_string_Fecha();
		FechayHora->tm_to_string_Hora();
		Informe = "Al Paciente: " << paciente->getDNI() << "Se le diagnostico: " << paciente->getProblemaString() << "por el especialista:  " << m_cMedico->getMatricula() << endl;
	}
	if (paciente->getProblema() == eProblema::COVID)
	{
		FechayHora->tm_to_string_Fecha();
		FechayHora->tm_to_string_Hora();
		Informe = "Al Paciente: " << paciente->getDNI() << "Se le diagnostico: " << paciente->getProblemaString() << "por el especialista:  " << m_cMedico->getMatricula() << endl;
}


}