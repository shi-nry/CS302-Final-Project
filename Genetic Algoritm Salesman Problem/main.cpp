// Genetic Algoritm Salesman Problem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tour.h"
#include "City.h"
#include "GeneticAlgorithm.h"
#include "Population.h"


int main()
{

    Tour t; // <-- not sure what to do with this
    GeneticAlgorithm *ga = GeneticAlgorithm::getInst();
    TourManager *tm = TourManager::getInst();

    //Add Cities 
    City *city1 = new City(x, y); // <-- are we using a class function to do this?
    TourManager.addCity(*city1); // I couldn't find one so I just went with the website method

    City *city2 = new City(x, y);
    TourManager.addCity(*city2);

    City *city3 = new City(x, y);
    TourManager.addCity(*city3);

    City *city4 = new City(x, y);
    TourManager.addCity(*city4);

    City *city5 = new City(x, y);
    TourManager.addCity(*city5);

    //Initialize pop
    Population *pop = new Population(50, true);
    std::cout << "Initial distance: " << pop->getFittestElement().getN() << endl;

    //Evolve pop for 100 gens
    *pop = ga.evolve(pop);
    for(int i = 0; i < 100; i++) {
        *pop = ga.evolve(pop);
    }

    //Print results
    std::cout << "Final distance: " << pop->getFittestElement().getDistance() << endl;
    std::cout << "Best solution: " << pop->getFittestElement() << endl;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
