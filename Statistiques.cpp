#include "Statistiques.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;
/// <summary>
/// Fait la moyenne tu vector de float donnée en arguments
/// </summary>
/// <param name="tablePop">Ensemble de donnée pour faire la moyenne</param>
/// <returns>retourne la moyenne</returns>
float calculerMoyenne(vector<float> tablePop)
{
	if (tablePop.empty()) return 0.0;
	float total{0};
	total = accumulate(tablePop.begin(), tablePop.end(), 0.0) / tablePop.size();
	return total;
}
/// <summary>
/// Fait la mediane
/// </summary>
/// <param name="tablePop">Ensemble de donnée pour faire la mediane</param>
/// <returns>retourne la mediane</returns>
float calculerMediane(vector<float> tablePop)
{
	if (tablePop.empty()) return 0.0;
	std::sort(tablePop.begin(), tablePop.end());
	size_t longeur = tablePop.size();
	if (longeur % 2 == 0) {
		return (tablePop[longeur / 2 - 1] + tablePop[longeur / 2]) / 2.0;
	}
	else {
		return tablePop[longeur / 2];
	}
}

float calculerEcartType(vector<float> tablePop)
{
	if (tablePop.size() < 2) return 0.0;
	float moyenne = calculerMoyenne(tablePop);
	float somme = 0.0;
	for (float nombre : tablePop) {
		somme += (nombre - moyenne) * (nombre - moyenne);
	}
	return sqrt(somme / (tablePop.size() - 1));
}

float calculerDistanceEuclidienne(vector<float> point1, vector<float> point2)
{
	if (point1.size() != point2.size()) throw invalid_argument("Les points doivent avoir les mêmes dimensions.");
	float somme = 0.0;
	for (size_t i = 0; i < point1.size(); ++i) {
		somme += (point1[i] - point2[i]) * (point1[i] - point2[i]);
	}
	return sqrt(somme);
}

float calculerDistanceManhattan(vector<float> point1, vector<float> point2)
{
	if (point1.size() != point2.size()) throw invalid_argument("Les points doivent avoir les mêmes dimensions.");
	double somme = 0.0;
	for (size_t i = 0; i < point1.size(); ++i) {
		somme += std::abs(point1[i] - point2[i]);
	}
	return somme;
}
