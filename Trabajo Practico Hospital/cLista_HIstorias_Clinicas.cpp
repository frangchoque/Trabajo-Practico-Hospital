#include "cLista_HIstorias_Clinicas.h"

cLista_HIstorias_Clinicas::cLista_HIstorias_Clinicas(unsigned int tam):ListaT<cHistoriaClinica>(tam)
{
}
template<class historial_pacientes>
cHistoriaClinica* cLista_HIstorias_Clinicas::BuscarHistoriaClinica(cPaciente* paciente)
{
	historial_pacientes* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		aux = dynamic_cast<historial_pacientes*>(lista[i]->getPaciente())
			if (paciente->getDNI() == aux.getDNI) { return lista[i]; }
		
	}
}


