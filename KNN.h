#pragma once
#include "Instance.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "ResourceLoader.h"
#include "Statistiques.h"
using namespace std;
class KNN
{
private:
	vector<Instance> m_donnees_train;
	vector<Instance> m_donnees_test;
	ResourceLoader* m_res;


public:
	KNN(string filePath);
	int classifier(Instance);
	map<string, int> tester();
};

