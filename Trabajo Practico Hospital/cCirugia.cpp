#include "cCirugia.h"
#include<sstream>

cCirugia::cCirugia(cFecha* FyH, cMedico* medico1,cFecha* alta,bool ambulatoria, cMedico* medicoadicional, cEnfermero* enfermero):cIntervencion(FyH,medico1) {
	Alta = alta;
	Fecha_Hora_inicio = new cFecha();
	Duracion = FuncionRand(1,6);
	Ambulatoria = ambulatoria;
	Nombre_Procedimiento = "NADA";
	MedicoAdicional = medicoadicional;
	Enfermero = enfermero;
	
}



cCirugia::~cCirugia() {

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
	if (ok == 3) { RealizarIntervencion(paciente); }
	else cout << "\n El paciente no puede ser intervenido hoy";

	//falta marcar la cirugia como cancelada en historial clinico y el monto tiene que ser 0 
}


void cCirugia::RealizarIntervencion(cPaciente* paciente) {
	eProblema problema = paciente->getProblema();    //Nos copiamos el problema del paciente a una variable Problema 
	if (Ambulatoria == false)
	{
		if (problema == eProblema::DolorPecho) {


			Nombre_Procedimiento = "Cirugia de bypass";
		   // Fecha_Hora_inicio->Actual()->tm_hour; //como funcionan las fechas
			//Alta = 
			Monto = 500.0;
			cout << m_cMedico->getMatricula() << " " << " esta atendiendo al paciente " << paciente->NumeroAfiliado() << " " << endl;
			m_cMedico->setOcupado(true);
			Enfermero->AdministrarMedicamento(medicamento);
		}
		else
		{
			Fecha_Hora_inicio = Alta;
			Ambulatoria = true;
			m_cMedico->ModificarIndicaciones();
			Monto = 50.0;

		}
		if (problema == eProblema::DolorAbdominal)
		{
			Nombre_Procedimiento = "Apendicectomia";
			//Fecha_Hora_inicio = Fecha_Hora_inicio->SetHoy();
			//Alta = Duracion - Fecha_Hora_inicio->getHora();
			Monto = 700.0;
			cout << m_cMedico->getMatricula() << " " << " esta atendiendo al paciente " << paciente->NumeroAfiliado() << " " << endl;
			m_cMedico->setOcupado(true);
			Enfermero->AdministrarMedicamento(medicamento);
		}
		else
		{
			Fecha_Hora_inicio = Alta;
			Ambulatoria = true;
			m_cMedico->ModificarIndicaciones();
			Monto = 50.0;
		}
		if (problema == eProblema::Problemas_de_Vision)
		{
			Nombre_Procedimiento = "Transplante de Cornea";
			//Fecha_Hora_inicio = Fecha_Hora_inicio->SetHoy();
			//Alta = Duracion - Fecha_Hora_inicio->getHora();
			Monto = 300.0;
			cout << m_cMedico->getMatricula() << " " << " esta atendiendo al paciente " << paciente->NumeroAfiliado() << " " << endl;
			Enfermero->AdministrarMedicamento(medicamento);
		}
		else
		{

			Fecha_Hora_inicio = Alta;
			Ambulatoria = true;
			m_cMedico->ModificarIndicaciones();
			Monto = 50.0;
		}
		if (problema == eProblema::COVID)
		{
			Nombre_Procedimiento = "tratamiento con fármacos antivirales ";
			//Fecha_Hora_inicio = Fecha_Hora_inicio->SetHoy();
			//Alta = Duracion - Fecha_Hora_inicio->getHora();
			Monto = 1000.0;
			cout << m_cMedico->getMatricula() << " " << " esta atendiendo al paciente " << paciente->NumeroAfiliado() << " " << endl;
			Enfermero->AdministrarMedicamento(medicamento);
		}
		else
		{
			Fecha_Hora_inicio = Alta;
			Ambulatoria = true;
			m_cMedico->ModificarIndicaciones();
			Monto = 50.0;
		}
	}

}


string cCirugia::to_string() {

	stringstream ss;

	ss << "Fecha de intervencion: " << FechayHora->tm_to_string_Fecha() << endl;
	ss << "Hora de intervenion: " << FechayHora->tm_to_string_Hora() << endl;
	ss << "Diagnostico: " << Diagnostico << endl;
	ss << "Procedimiento: " << Nombre_Procedimiento << endl;
	ss << "Fecha  inico: " << Fecha_Hora_inicio->tm_to_string_Fecha() << endl;
	ss << "Hora  inico: " << Fecha_Hora_inicio->tm_to_string_Hora() << endl;
	ss << "Duracion: " << Duracion << endl;
	ss << "Fecha de alta: "<<Alta->tm_to_string_Fecha() << endl;
	return ss.str();
}

void cCirugia::Imprimir() {
	string imprimir = to_string();
	cout << imprimir;
}