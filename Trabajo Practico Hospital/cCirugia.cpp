#include "cCirugia.h"
#include<sstream>
#include "cMedico.h"
#include "cEnfermero.h"

cCirugia::cCirugia(cMedico* medico1, cMedico* medicoadicional, cEnfermero* enfermero, cFecha FyH, bool ambulatoria) :cIntervencion(FyH, medico1) {
	cFecha* Hoy = new cFecha();
	Fecha_Hora_inicio = *Hoy;
	Fecha_Alta = *Hoy;
	Duracion = FuncionRand(600, 60);
	Ambulatoria = ambulatoria;
	Nombre_Procedimiento = " ";
	MedicoAdicional = medicoadicional;
	Enfermero = enfermero;
	Inventario = enfermero->getInventario();
}

cCirugia::~cCirugia() {

}

void cCirugia::Prequirurgico(cPaciente* paciente) {
	//Si llega hasta el final, puede ser intervenido

	cout << "\nEl paciente esta en ayunas de 8 horas?" << endl;
	if (paciente->getAyuno() == true) {
		cout << "\nSi";
	}
	else {
		cout << "\nNo";
		throw new exception("\nNo puede realizar la operacion");
	}

	cout << "\nCual es el valor de hematocrito del paciente? " << endl;
	if (paciente->getSexo() == "F") {
		if (paciente->getValor_Hematocrito() >= 38 || paciente->getValor_Hematocrito() <= 42) {
			cout << "\nSi";
		}
		else
		{
			cout << "\nNo";
			throw new exception("\nNo puede realizar la operacion");
		}
	}
	else if (paciente->getValor_Hematocrito() >= 40 || paciente->getValor_Hematocrito() <= 45) {
		cout << "\nSi";
	}
	else
	{
		cout << "\nNo";
		throw new exception("\nNo puede realizar la operacion");
	}

	cout << "\nCual es la saturacion del paciente? " << endl;
	if (paciente->getEdad() > 25 && paciente->getSaturacion() >= 95) {
		cout << "\nSi";
	}
	else if (paciente->getEdad() <= 25 && paciente->getSaturacion() >= 97) {
		cout << "\nSi";
	}
	else
	{
		cout << "\nNo";
		throw new exception("\nNo puede realizar la operacion");
	}

}


void cCirugia::RealizarIntervencion(cPaciente* paciente) {
	eProblema problema = paciente->getProblema();    //Nos copiamos el problema del paciente a una variable Problema 
	try
	{
		this->Prequirurgico(paciente);
	}
	catch (exception* error)
	{
		cout << "\nEl paciente no puede ser intervenido hoy" << endl;
		Monto = 0;
		delete error;//Controlo la excepcion y salgo
		return;
	}

	//Solo atiende los dolores de pecho y abdominales

	if (Ambulatoria)
	{
		Medico_Principal->setAlta();//Hacer que le pase el paciente
	}

	Medico_Principal->setInternado();

	//Dependiendo del problema del paciente se le realizara un procedimiento quirurgico
	if (problema == eProblema::DolorPecho) {
		//La fecha de alta se dicta despues
		Nombre_Procedimiento = "Cirugia de bypass";
		Fecha_Hora_inicio.SetHoy();

		Monto = FuncionRand(50000, 1000);
		cout << "\nEl/La doctor/a " << Medico_Principal->getNombre() << " " << "esta atendiendo al paciente " << paciente->getNombre() << endl;
		Medico_Principal->setOcupado(true);

		for (int i = 0; i < Inventario->getCA(); i++)
		{
			try {
				Enfermero->AdministrarMedicamento((*Inventario)[i]);
			}
			catch (exception* error)
			{
				delete error;//Que siga hasta encontrar un medicamento adecuado
			}
		}


	}

	if (problema == eProblema::DolorAbdominal)
	{
		Nombre_Procedimiento = "Apendicectomia";
		Fecha_Hora_inicio.SetHoy();
		Monto = FuncionRand(50000, 5000);
		cout << "\n" << Medico_Principal->getMatricula() << " " << " esta atendiendo al paciente " << paciente->NumeroAfiliado() << " " << endl;
		Medico_Principal->setOcupado(true);
		for (int i = 0; i < Inventario->getCA(); i++)
		{
			Enfermero->AdministrarMedicamento((*Inventario)[i]);
		}

	}

	Medico_Principal->setAlta();//Hacer que le pase el paciente
	cFecha* Hoy = new cFecha();
	Fecha_Alta = *Hoy;//Seteo la fecha de alta en el momento
	if (!Ambulatoria)//Si no es ambulatoria
	{
		if (Fecha_Alta.getMes() < 12)
		{
			Fecha_Alta.setFecha(Hoy->getDia(), Hoy->getMes() + 1, Hoy->getAnio());
		}
		else
		{
			Fecha_Alta.setFecha(Hoy->getDia(), 1, Hoy->getAnio());
		}
	}
}


string cCirugia::to_string() {

	stringstream ss;

	ss << "\nFecha de intervencion: " << FechayHora.tm_to_string_Fecha() << endl;
	ss << "\nHora de intervencion: " << FechayHora.tm_to_string_Hora() << endl;
	ss << "\nDiagnostico: " << Diagnostico << endl;
	ss << "\nProcedimiento: " << Nombre_Procedimiento << endl;
	ss << "\nFecha inicio: " << Fecha_Hora_inicio.tm_to_string_Fecha() << endl;
	ss << "\nHora inicio: " << Fecha_Hora_inicio.tm_to_string_Hora() << endl;
	ss << "\nDuracion: " << Duracion << endl;
	return ss.str();
}

void cCirugia::Imprimir() {
	string imprimir = to_string();
	cout << imprimir << endl;
}