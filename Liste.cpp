#include "Liste.h"
#include <stdexcept>
#include <algorithm>
using namespace std;
void Liste::ajouterNoeud(Instance donnees)
{
    Instance* donn = new Instance(donnees);
    Noeud* nouveau = new Noeud{ donn, nullptr };
    if (m_premier == nullptr) {
        m_premier = nouveau;
    }
    else {
        Noeud* iterateur = m_premier;
        while (iterateur->suivant != nullptr) {
            iterateur = iterateur->suivant;
        }
        iterateur->suivant = nouveau;
    }
    m_donnees++;
}

Noeud* Liste::obtenirDonnees(float k)
{
    if (k <= 0 || k > 1) {
        throw invalid_argument("La valeur de k doit être comprise entre 0 et 1.");
    }
    int nombreDonne = m_donnees * k;
    if (nombreDonne == 0) return nullptr;

    Noeud* premier = nullptr;
    Noeud* iterateurliste = nullptr;
    Noeud* iterateurDon = m_premier;

    for (int i = 0; i < nombreDonne; i++) {
        Noeud* nouveau = new Noeud{ iterateurDon->donnee, nullptr };
        if (i == 0) {
            premier = nouveau;
            iterateurliste = nouveau;
        }
        else {
            iterateurliste->suivant = nouveau;
            iterateurliste = nouveau;
        }
        iterateurDon = iterateurDon->suivant;
    }
    return premier;
}

Noeud* Liste::obtenirDonneesParFin(float k)
{
    if (k <= 0 || k > 1) {
        throw invalid_argument("La valeur de k doit être comprise entre 0 et 1.");
    }
    int nombreDonne = m_donnees * k;
    if (nombreDonne == 0) return nullptr;

    int indexDebut = m_donnees - nombreDonne;
    Noeud* premier = nullptr;
    Noeud* iterateurliste = nullptr;
    Noeud* iterateurDon = m_premier;

    for (int i = 0; i < indexDebut; i++) {
        iterateurDon = iterateurDon->suivant;
    }

    while (iterateurDon != nullptr) {
        Noeud* nouveau = new Noeud{ iterateurDon->donnee, nullptr };
        if (premier == nullptr) {
            premier = nouveau;
            iterateurliste = nouveau;
        }
        else {
            iterateurliste->suivant = nouveau;
            iterateurliste = nouveau;
        }
        iterateurDon = iterateurDon->suivant;
    }
    return premier;
}
