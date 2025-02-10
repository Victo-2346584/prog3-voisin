#pragma once
struct Instance
{
    float acidite_fixe;
    float acide_volatile;
    float acide_citrique;
    float sucre_residuel;
    float chlorure_sodium;
    float dioxyde_soufre_libre;
    float dioxyde_soufre_total;
    float densite;
    float pH;
    float sulfate_potassium;
    float alcool;
    int bon;
};

struct Noeud {

    Instance* donnee;
    Noeud* suivant;

};