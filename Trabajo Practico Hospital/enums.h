#pragma once
#include <string>
using namespace std;

enum class eObraSocial {DEF=0, CBA, HIG,OSDE}typedef ObraSocial;

enum class eProblema{Tos=0,Fiebre,DolorAbdominal,Problemas_de_Vision,COVID,DolorPecho}typedef Problema;

enum class eEspecialidad{MedicoGuardia=0,CirujanoGeneral,Anestesiologo,Interno,Oftalmologo,CirujanoCardioVascular}typedef Especialidad;

enum class eProcedimiento {Apendicectomia = 0, Transplante_de_Cornea,ProblermasRespiratorios,Bypass} typedef Procedimientos;

int FuncionRand(int max, int min) {

	return rand() % (max - min) - min;
};

string Especialidad_to_string(Especialidad esp);

string ObraSocial_to_string(ObraSocial obraSocial);

string Problema_to_string(eProblema prob);