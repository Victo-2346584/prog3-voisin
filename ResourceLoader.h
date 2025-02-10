#pragma once
#include "Liste.h"
#include <iostream>
#include <vector>
#include <string>
#include "Instance.h"
using namespace std;
/// <summary>
/// ResourceLoader sert prendre un fichier et le mettre en memoire
/// </summary>
class ResourceLoader
{
private:
    Liste* listeChaine = new Liste();
    vector<Instance> m_donnes;
    /// <summary>
    /// Ajouter les données du fichier dans la mémoires
    /// </summary>
    /// <param name="filepath">chemin du fichier a rentrer</param>
    void ajouterFichier(const std::string& filepath);

public:
    /// <summary>
    /// Constructeur permettant devoier les données
    /// </summary>
    /// <param name="filepath">chemin du fichier a rentrer</param>
    ResourceLoader(const std::string& filepath);
    /// <summary>
    /// obtenir les données du fichier pour entrainement
    /// </summary>
    /// <param name="k">pourcentage du total des donnes</param>
    /// <returns></returns>
    std::vector<Instance> getTrainData(float k);
    /// <summary>
    /// obtenir les données du fichier pour essaie
    /// </summary>
    /// <param name="k">1-le pourcentage des donnes</param>
    /// <returns></returns>
    std::vector<Instance> getTestData(float k);
    /// <summary>
    /// ecrit les donnes present dans la memoire dans la console
    /// </summary>
    void printData();
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    Noeud* getTrainDataLinked(float);
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    Noeud* getTestDataLinked(float);
};
