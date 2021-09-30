#include "cMedico.h"

cMedico::cMedico(string dni, cFecha* fecha, string nom, string sexo,int matricula,eEspecialidad especialidad_e):cPersonal(dni, fecha, nom, sexo), Matricula(matricula) {
	especialidad = especialidad_e;
	
}



cMedico::~cMedico() {

}





void cMedico::AgregarIntervencion() {

}


void cMedico::DarAlta() {

}


void cMedico::Imprimir() {

}


void cMedico::Internar_paciente() {

}


void cMedico::ModificarIndicaciones() {

}


string cMedico::to_string() {

	return  NULL;
}