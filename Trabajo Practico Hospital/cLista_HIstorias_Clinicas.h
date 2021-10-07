#pragma once
#include"cListaT.h"
#include "cHistoriaClinica.h"
class cLista_HIstorias_Clinicas:
	public ListaT<cHistoriaClinica>
{
public:
	cLista_HIstorias_Clinicas(unsigned int tam);
	~cLista_HIstorias_Clinicas();
	template <class tipoIntervencion>
	void ListarIntervenciones();//lista las intervenciones por grupo
	template<class historial_pacientes>
	cHistoriaClinica* BuscarHistoriaClinica(cPaciente*paciente);


};

