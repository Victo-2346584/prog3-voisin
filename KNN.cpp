#include "KNN.h"

KNN::KNN(string filePath)
{
	 m_res = new ResourceLoader(filePath);
	m_donnees_test = m_res->getTestData(.5f);
	m_donnees_train = m_res->getTrainData(0.5f);
}

int KNN::classifier(Instance instance_test) {
    // Convertir l'instance en vecteur pour utiliser la fonction de distance
    vector<float> point_test = {
        instance_test.acidite_fixe,
        instance_test.acide_volatile,
        instance_test.acide_citrique,
        instance_test.sucre_residuel,
        instance_test.chlorure_sodium,
        instance_test.dioxyde_soufre_libre,
        instance_test.dioxyde_soufre_total,
        instance_test.densite,
        instance_test.pH,
        instance_test.sulfate_potassium,
        instance_test.alcool
    };

    // Vecteur pour stocker les distances avec tous les points d'entraînement
    vector<pair<float, int>> distances;

    // Calculer la distance avec chaque instance d'entraînement
    for (const auto& train_instance : m_donnees_train) {
        vector<float> point_train = {
            train_instance.acidite_fixe,
            train_instance.acide_volatile,
            train_instance.acide_citrique,
            train_instance.sucre_residuel,
            train_instance.chlorure_sodium,
            train_instance.dioxyde_soufre_libre,
            train_instance.dioxyde_soufre_total,
            train_instance.densite,
            train_instance.pH,
            train_instance.sulfate_potassium,
            train_instance.alcool
        };

        float distance = calculerDistanceEuclidienne(point_test, point_train);
        distances.push_back({ distance, train_instance.bon });
    }

    // Trier les distances
    sort(distances.begin(), distances.end());

    // Prendre les k plus proches voisins (ici k=5)
    const int k = 5;
    int count_0 = 0, count_1 = 0;
    for (int i = 0; i < k && i < distances.size(); i++) {
        if (distances[i].second == 0) count_0++;
        else count_1++;
    }

    // Retourner la classe majoritaire
    return (count_1 > count_0) ? 1 : 0;
}

map<string, int> KNN::tester() {
    map<string, int> resultats = {
        {"vraiPositif", 0},
        {"fauxPositif", 0},
        {"vraiNegatif", 0},
        {"fauxNegatif", 0}
    };

    for (const auto& instance : m_donnees_test) {
        int prediction = classifier(instance);
        int realite = instance.bon;

        if (prediction == 1 && realite == 1)
            resultats["vraiPositif"]++;
        else if (prediction == 1 && realite == 0)
            resultats["fauxPositif"]++;
        else if (prediction == 0 && realite == 0)
            resultats["vraiNegatif"]++;
        else if (prediction == 0 && realite == 1)
            resultats["fauxNegatif"]++;
    }

    return resultats;
}