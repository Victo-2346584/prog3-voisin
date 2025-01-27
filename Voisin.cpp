#include <iostream>
#include "Statistiques.h"

using namespace std;

int main()
{
    std::vector<float> valeurs = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    std::vector<float> point1 = { 1.0, 2.0, 3.0 };
    std::vector<float> point2 = { 4.0, 6.0, 8.0 };

    std::cout << "Moyenne : " << calculerMoyenne(valeurs) << std::endl;
    std::cout << "Mediane : " << calculerMediane(valeurs) << std::endl;
    std::cout << "Ecart type : " << calculerEcartType(valeurs) << std::endl;
    std::cout << "Distance Euclidienne : " << calculerDistanceEuclidienne(point1, point2) << std::endl;
    std::cout << "Distance Manhattan : " << calculerDistanceManhattan(point1, point2) << std::endl;

}
