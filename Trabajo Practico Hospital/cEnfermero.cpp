#include "cEnfermero.h"

cEnfermero::cEnfermero(bool turno, string dni, cFecha fecha, string nom, string sexo):Matricula(GenerarMatricula()):cPersonal(dni, fecha, nom, sexo) {
	Turno = turno;

}



cEnfermero::~cEnfermero() {

}

string cEnfermero::GenerarMatricula()
{
	int aux1, aux2, aux3;
	srand(time(NULL));
	 aux1 = (rand() % 4) + 1;
	 aux2 = (rand() % 4);
	 aux3 = (rand() % 5) + 1;
	 return "AMS" + aux1 + aux2 + aux3;
}





void cEnfermero::AdministrarMedicamento() {

}


void cEnfermero::Imprimir() {

}


string cEnfermero::to_string() {

	return  NULL;
}


void cEnfermero::Verificar_vencimiento(cMedicamento* medicamento) {

}