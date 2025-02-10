#include <iostream>
#include "Statistiques.h"
#include "ResourceLoader.h"

using namespace std;

int main()
{
	vector<float> valeurs = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	vector<float> point1 = { 1.0, 2.0, 3.0 };
	vector<float> point2 = { 4.0, 6.0, 8.0 };

	cout << "Moyenne : " << calculerMoyenne(valeurs) << endl;
	cout << "Mediane : " << calculerMediane(valeurs) << endl;
	cout << "Ecart type : " << calculerEcartType(valeurs) << endl;
	cout << "Distance Euclidienne : " << calculerDistanceEuclidienne(point1, point2) << endl;
	cout << "Distance Manhattan : " << calculerDistanceManhattan(point1, point2) << endl;
	const string& filePath{ "C:\\Users\\hugon\\Downloads\\binary-winequality-white.csv" };
	ResourceLoader test = ResourceLoader(filePath);
	vector<Instance> train = test.getTrainData(0.003f);
	for(int i = 0; i < train.size(); i++)
	{
		cout << train[i].acide_citrique << endl;

	}
	vector<Instance> voir = test.getTestData(0.003f);
	for (int i = 0; i < voir.size(); i++)
	{
		cout << voir[i].acide_citrique << endl;

	}
	cout << "premier" << endl;
	Noeud* listeTrain = test.getTrainDataLinked(0.003f);
	Noeud* iterateurTrain = listeTrain;
	while (iterateurTrain->suivant != nullptr)
	{
		cout << iterateurTrain->donnee->acide_citrique << endl;
		iterateurTrain = iterateurTrain->suivant;
	}
	cout << "deuxieme" << endl;
	Noeud* listeData = test.getTestDataLinked(0.003f);
	Noeud* iterateurData = listeData;
	while (iterateurData->suivant != nullptr)
	{
		cout << iterateurData->donnee->acide_citrique << endl;
		iterateurData = iterateurData->suivant;
	}
}