#include "cMedico.h"

cMedico::cMedico(string dni, cFecha fecha, string nom, string sexo,int matricula,eEspecialidad especialidad_e):cPersonal(dni, fecha, nom, sexo), Matricula(matricula) {
	especialidad = especialidad_e;
	Registro = NULL;
	Ocupado = false;//esta libre
}

cMedico::~cMedico() {

}

void cMedico::AgregarIntervencion() {
	//Practica: Problemas de vision, Covid
	//Cirugia: Dolor en el pecho
	//Consulta: Tos, fiebre, dolor abdominal
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


void cMedico::ModificarIndicaciones() {

}


string cMedico::to_string() {
	string aux = ((cPersonal*)this)->to_string();
	aux = aux + "\nEspecialidad: " + Especialidad_to_string(this->especialidad);
	return  aux;
}

bool cMedico::getOcupado()
{
	return Ocupado;
}

string cMedico::getEspecialidad()
{
	return Especialidad_to_string(especialidad);
}
