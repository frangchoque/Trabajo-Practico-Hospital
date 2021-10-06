#include "cPaciente.h"



cPaciente::cPaciente(bool afiliado, string nombre, cFecha* nacimiento, eObraSocial obra_social, string dni, char sexo, eProblema problema,bool ayunas) {
	Afiliado = afiliado;
	Nombre = nombre;
	Fecha_nacimiento = nacimiento;
	Obra_social = obra_social;
	DNI = dni;
	Sexo = sexo;
	Problema = problema;
	this->Numero_afiliado = NumeroAfiliado();
	Ayunas = ayunas;
	GenerarValores_HematocritoySaturacion();
	Edad = CalcularEdad(nacimiento);
}



cPaciente::~cPaciente() {

}

unsigned int cPaciente::NumeroAfiliado()
{
	unsigned int random;
	if (Afiliado)
	{
		random = FuncionRand(1000, 1);
	}
	return 0;
}





void cPaciente::Imprimir() {

}


string cPaciente::to_string() {

	return  NULL;
}

void cPaciente::GenerarValores_HematocritoySaturacion()
{
	if (Sexo == 'F') { 
		valor_hematocrito = FuncionRand(45,30);//valores entre 30 y 45 (es mas que los valores normales para que haya pacientes que tenga valores anormales)
	}
	else { valor_hematocrito = FuncionRand(50, 35); }//valores entere 50 y 35
	if (Edad <= 25) { Saturacion = FuncionRand(100, 97); }
	else { Saturacion = FuncionRand(100, 95);}
}

int cPaciente::getEdad()
{
	return Edad;
}

char cPaciente::getSexo()
{
	return Sexo;
}

int cPaciente::getSaturacion()
{
	return Saturacion;
}

int cPaciente::getValor_Hematocrito()
{
	return valor_hematocrito;
}

bool cPaciente::getAyuno()
{
	return Ayunas;
}

int cPaciente::CalcularEdad(cFecha* nacimiento)
{
	int dif = 0;
	int anio = (nacimiento->getAnio());
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo el anio actual
	if (nacimiento->getMes() < aux->tm_mon)
	{
		dif = (aux->tm_year) - anio;
		return dif;
	}
	else {
		dif = (aux->tm_year) - anio;
		return dif - 1;//todavia no cumplio anios
	}
	if (anio > aux->tm_year) { return -1; }
}

