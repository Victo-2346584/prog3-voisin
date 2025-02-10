#pragma once
#include "Instance.h"
class Liste
{
private:
	Noeud* m_premier{ nullptr };
	int m_donnees{ 0 };
public:
	/// <summary>
	/// ajouter la donn�es
	/// </summary>
	/// <param name=""> nombre a jouter dans la liste</param>
	void ajouterNoeud(Instance);
	Noeud* obtenirDonnees(float);
	Noeud* obtenirDonneesParFin(float);

};

