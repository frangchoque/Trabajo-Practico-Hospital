#include "cPaciente.h"

cPaciente::cPaciente(bool afiliado, string nombre, cFecha* nacimiento, eObraSocial obra_social, string dni, string sexo, eProblema problema) {
	Afiliado = afiliado;
	Nombre = nombre;
	Fecha_nacimiento = nacimiento;
	Obra_social = obra_social;
	DNI = dni;
	Sexo = sexo;
	Problema = problema;
	this->Numero_afiliado = 0;
}



cPaciente::~cPaciente() {

}





void cPaciente::Imprimir() {

}


string cPaciente::to_string() {

	return  NULL;
}