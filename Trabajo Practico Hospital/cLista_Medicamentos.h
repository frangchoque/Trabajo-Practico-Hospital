#pragma once
#include "cListaT.h"
#include "cMedicamento.h"
class cLista_Medicamentos:
	public ListaT<cMedicamento>
{
	cLista_Medicamentos(unsigned int tam);
	void AgregarMedicamento(cMedicamento*remedio);
	
};

