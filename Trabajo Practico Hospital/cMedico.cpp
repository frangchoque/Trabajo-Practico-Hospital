#include "cMedico.h"

cMedico::cMedico(string dni, cFecha fecha, string nom, string sexo,int matricula,eEspecialidad especialidad_e):cPersonal(dni, fecha, nom, sexo), Matricula(matricula) {
	especialidad = especialidad_e;
	Registro = NULL;
	Ocupado = false;//esta libre
}

cMedico::~cMedico() {

}

void cMedico::AgregarIntervencion() {
	if (Registro->getPaciente()->getProblema() == Problema::Problemas_de_Vision || Registro->getPaciente()->getProblema() == Problema::COVID)
	{

	}
	if (Registro->getPaciente()->getProblema() == Problema::DolorPecho || Registro->getPaciente()->getProblema() == Problema::DolorAbdominal)
	{

	}
	if (Registro->getPaciente()->getProblema() == Problema::Tos || Registro->getPaciente()->getProblema() == Problema::Fiebre)
	{

	}
	//Practica: Problemas de vision, Covid
	//Cirugia: Dolor en el pecho, dolor abdominal
	//Consulta: Tos, fiebre
}


void cMedico::DarAlta() {
	Registro->setAlta();
	
	Registro = NULL;//El medico deja de estar a cargo del paciente

}


void cMedico::Imprimir() {
	cout << this->to_string() << endl;
}


void cMedico::Internar_paciente() {
	Registro->setInternado();
}


string cMedico::ModificarIndicaciones() {
	if (Registro->getPaciente()->getProblema() == Problema::Tos)//Despues cambiarlo a return
	{
		if (FuncionRand(2, 0) == 0)
		{
			return "\nTomese un descanso y llame si surgen problemas";
		}
		if (FuncionRand(2, 0) == 1)
		{
			return "\nCompre un antigripal, tome 1 dosis cada 8 horas y tomese la temperatura cada 12";
		}
		if (FuncionRand(2, 0) == 2)
		{
			return "\nPongase en cuarentena e informe sobre la evolucion de la enfermedad.";
		}
	}
	if (Registro->getPaciente()->getProblema() == Problema::Fiebre)
	{
		if (FuncionRand(2, 0) == 0)
		{
			return "\nDuerma y tome agua";
		}
		if (FuncionRand(2, 0) == 1)
		{
			return "\nTomese un ibuprofeno 400mg";
		}
		if (FuncionRand(2, 0) == 2)
		{
			return "\nSientese y espere, le vamos a inyectar un tranquilizante";
		}
	}


}


string cMedico::to_string() {
	string aux = ((cPersonal*)this)->to_string();
	aux = aux + "\nEspecialidad: " + Especialidad_to_string(this->especialidad);
	return  aux;
}