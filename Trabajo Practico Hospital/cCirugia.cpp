#include "cCirugia.h"

cCirugia::cCirugia(cFecha* FyH, cMedico* medico1,cFecha* alta, cFecha* FyHinicio, unsigned int duracion, bool ambulatoria, cMedico* medicoadicional, cEnfermero* enfermero):cIntervencion(FyH,medico1) {
	Alta = alta;
	Fecha_Hora_inicio = FyHinicio;
	Duracion = duracion;
	Ambulatoria = ambulatoria;
	Procedimiento = "NADA";
	MedicoAdicional = medicoadicional;
	Enfermero = enfermero;
	
}



cCirugia::~cCirugia() {

}





void cCirugia::Imprimir() {

}


void cCirugia::Prequirurgico(cPaciente* paciente) {
	
	int ok = 0;//si es =3 cumple los 3 requisitos para la cirugia
	
	cout << "El paciente está en ayunas de 8 horas?"<<endl;
	if (paciente->getAyuno() == true) {
	cout << "si";
	ok++;
	}
	else { cout << "No"; }
	
	cout << "Cuál es el valor de hematocrito del paciente? " << endl;
	if (paciente->getSexo() == 'F' ) {
		if (paciente->getValor_Hematocrito() >= 38 || paciente->getValor_Hematocrito() <= 42) {
			cout << "si";
			ok++;
		}
	}
	else if (paciente->getValor_Hematocrito() >= 40 || paciente->getValor_Hematocrito() <= 45) {
		cout << "si";
		ok++;
	}
	
	cout << "Cual es la saturación del paciente? " << endl;
	if (paciente->getEdad() > 25 && paciente->getSaturacion() >= 95) {
		cout << "si";
		ok++;
	
	}
	else if (paciente->getEdad() <= 25 && paciente->getSaturacion() >= 97) {
		cout << "si";
		ok++;
	}
	if (ok == 3) RealizarIntervencion(paciente){/*interna al paciente y actualiza el monto*/ };
	else cout << "\n El paciente no puede ser intervenido hoy";

	//falta marcar la cirugia como cancelada en historial clinico y el monto tiene que ser 0 
}


void cCirugia::RealizarIntervencion(cPaciente* paciente) {

}


string cCirugia::to_string() {

	return  NULL;
}