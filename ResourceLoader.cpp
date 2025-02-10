#include "ResourceLoader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "Instance.h"
using namespace std;

void ResourceLoader::ajouterFichier(const string& filepath)
{
    ifstream file(filepath);
    if (!file.is_open())
    {
        throw runtime_error("Impossible d'ouvrir le fichier : " + filepath);
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string value;
        vector<float> values;

        while (getline(ss, value, ','))
        {
            try
            {
                values.push_back(stof(value)); // Convertit chaque valeur en float
            }
            catch (const exception& e)
            {
                throw runtime_error("Erreur de conversion dans la ligne : " + line);
            }
        }

        if (values.size() != 12)
        {
            throw runtime_error("Ligne mal formatée dans le fichier : " + line);
        }

        Instance instance = {
            values[0], values[1], values[2], values[3], values[4],
            values[5], values[6], values[7], values[8], values[9],
            values[10], static_cast<int>(values[11])
        };
        listeChaine->ajouterNoeud(instance);
        m_donnes.push_back(instance);
    }

    file.close();
}

ResourceLoader::ResourceLoader(const string& filepath)
{
    ajouterFichier(filepath);
}

vector<Instance> ResourceLoader::getTrainData(float k)
{
    if (k <= 0 || k > 1)
    {
        throw invalid_argument("La valeur de k doit être comprise entre 0 et 1.");
    }

    size_t trainSize = m_donnes.size() * k;
    return vector<Instance>(m_donnes.begin(), m_donnes.begin() + trainSize);
}

vector<Instance> ResourceLoader::getTestData(float k)
{
    if (k <= 0 || k > 1)
    {
        throw invalid_argument("La valeur de k doit être comprise entre 0 et 1.");
    }

    size_t trainSize = m_donnes.size() * (1-k);
    return vector<Instance>(m_donnes.begin() + trainSize, m_donnes.end());
}

void ResourceLoader::printData()
{
    for (const auto& instance : m_donnes)
    {
        cout << instance.acidite_fixe << ", "
            << instance.acide_volatile << ", "
            << instance.acide_citrique << ", "
            << instance.sucre_residuel << ", "
            << instance.chlorure_sodium << ", "
            << instance.dioxyde_soufre_libre << ", "
            << instance.dioxyde_soufre_total << ", "
            << instance.densite << ", "
            << instance.pH << ", "
            << instance.sulfate_potassium << ", "
            << instance.alcool << ", "
            << instance.bon << endl;
    }
}

Noeud* ResourceLoader::getTrainDataLinked(float k)
{
    return listeChaine->obtenirDonnees(k);
}

Noeud* ResourceLoader::getTestDataLinked(float k)
{
    return listeChaine->obtenirDonneesParFin(k);
}
