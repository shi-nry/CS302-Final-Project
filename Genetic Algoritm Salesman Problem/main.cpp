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
    // ^ are we using a class function to do this?
    // I couldn't find one so I just went with the website method

    const int city_count = 5;
    std::string city_names[5];
    float city_coords[5 * city_count];

    city_names[0] = "Reno";
    city_coords[0] = 205;
    city_coords[1] = 856;

    city_names[1] = "San Francisco";
    city_coords[2] = 0;
    city_coords[3] = 1037;

    city_names[2] = "Salt Lake City";
    city_coords[4] = 817;
    city_coords[5] = 736;

    city_names[3] = "Seattle";
    city_coords[6] = 0;
    city_coords[7] = 0;

    city_names[4] = "Las Vegas";
    city_coords[8] = 560; 
    city_coords[9] = 1190;


    City *city1 = new City(city_coords[0], city_coords[1]); // <-- need to add coordinates
    tm->addCity(*city1); 

    City *city2 = new City(city_coords[2], city_coords[3]);
    tm->addCity(*city2); 

    City *city3 = new City(city_coords[4], city_coords[5]);
    tm->addCity(*city3);

    City *city4 = new City(city_coords[6], city_coords[7]);
    tm->addCity(*city4);

    City *city5 = new City(city_coords[8], city_coords[9]);
    tm->addCity(*city5);

    //Initialize pop
    Population* pop = new Population(50, true);
    Tour init = *pop->getFittestElement();
    std::cout << "Initial distance: " << init.getDistance() << std::endl;
    std::cout << "Initial Recommendation: " << init.getChromosomeAsCSV() << std::endl;

    //Evolve pop for 100 gens
    pop = ga->evolve(*pop);
    for(int i = 0; i < 100; i++) {
        pop = ga->evolve(*pop);
    }

    //Print results
    std::cout << "Final distance: " << pop->getFittestElement()->getDistance() << std::endl;

    Tour* best = pop->getFittestElement();
    std::cout << "Best solution: " << "Travel to ";
    std::cout << best->getChromosomeAsCSV();
    std::cout << std::endl;

    return 0;
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
