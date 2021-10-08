#include "enums.h"

string Especialidad_to_string(Especialidad esp)
{
	switch (esp)
	{
	case Especialidad::MedicoGuardia:
		return "Medico de guardia";
		break;
	case Especialidad::Anestesiologo:
		return "Anestesiologo";
		break;
	case Especialidad::CirujanoCardioVascular:
		return "Cirujano Cardiovascular";
		break;
	case Especialidad::CirujanoGeneral:
		return "Cirujano General";
		break;
	case Especialidad::Interno:
		return "Interno";
		break;
	case Especialidad::Oftalmologo:
		return "Oftalmologo";
		break;
	}
}

string ObraSocial_to_string(ObraSocial obraSocial)
{
	switch (obraSocial)
	{
	case ObraSocial::CBA:
		return "CBA";
	case ObraSocial::DEF:
		return "DEF";
	case ObraSocial::HIG:
		return "HIG";
	case ObraSocial::OSDE:
		return "OSDE";
	}
}

string Problema_to_string(eProblema prob)
{
	switch (prob)
	{
	case eProblema::COVID:
		return "COVID";
	case eProblema::DolorAbdominal:
		return "DolorAbdominal";
	case eProblema::DolorPecho:
		return "DolorPecho";
	case eProblema::Fiebre:
		return "Fiebre";
	case eProblema::Problemas_de_Vision:
		return "Problemas_de_Vision";
	case eProblema::Tos:
		return "Tos";

	default:
		break;
	}
}
