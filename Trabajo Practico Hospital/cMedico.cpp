#include "cMedico.h"

cMedico::cMedico(string dni, cFecha* fecha, string nom, string sexo,int matricula,eEspecialidad especialidad_e):cPersonal(dni, fecha, nom, sexo), Matricula(matricula) {
	especialidad = especialidad_e;
	Registro = NULL;
}

cMedico::~cMedico() {

}

void cMedico::AgregarIntervencion() {
	
}


void cMedico::DarAlta() {
	Registro->setAlta();
	
	Registro = NULL;

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