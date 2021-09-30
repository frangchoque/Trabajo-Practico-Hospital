#pragma once
#include "cPersonal.h"
#include "cHistoriaClinica.h"
#include <string>
using namespace std;

class cSistema
{
	cPersonal* m_cPersonal;
	cHistoriaClinica* m_cHistoriaClinica;
public:
	cSistema();
	virtual ~cSistema();
	

	void AgregarHistoriaClinica(cPaciente* paciente);
	void AñadirPersonal(cPersonal* personal);
	cHistoriaClinica* Buscar_por_DNI(string dni);
	void CalcularFananciaTotal();
	void EliminarPersonal();
	void Imprimir();
	void ImprimirProcedimientos(cMedico* medico, cFecha fecha);
	string to_string();

};

