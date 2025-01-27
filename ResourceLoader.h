#pragma once
#include <iostream>
#include <vector>
using namespace std;
class ResourceLoader
{
private:
	struct Instance
	{
		float m_acidite_fixe;
		float m_acide_volatile;
		float m_acide_citrique;
		float m_sucre_residuel;
		float m_chlorure_sodium;
		float m_dioxyde_soufre_libre;
		float m_dioxyde_soufre_total;
		float m_densite;
		float m_pH;
		float m_sulfate_potassium;
		float m_alcool;
		int m_bon;
	};
	ResourceLoader(string);
	vector<Instance> getTrainData();
	vector<Instance> getTestData();
    vector<Instance> m_donnes;
};
}