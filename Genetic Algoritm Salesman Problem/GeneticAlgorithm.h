#ifndef __GENETIC_ALGORITHM__
#define __GENETIC_ALGORITHM__

#include "Population.h"
#include "Tour.h"
#include <cstdlib>

#define mutation_rate 0.01
#define tournament_size 4
#define using_elites true

class GeneticAlgorithm {

private:
	static GeneticAlgorithm* inst;
	GeneticAlgorithm();

public:
	static GeneticAlgorithm* getInst();
	Tour* selection(Population& pop);
	Population* evolve();
	Tour* crossover(Tour& t1, Tour& t2);
	void mutate(Tour& r);
};

float value() {
	return (rand() % 1000) / (float) 1000;
}

GeneticAlgorithm::GeneticAlgorithm() {

}

GeneticAlgorithm* GeneticAlgorithm::inst = 0;

GeneticAlgorithm* GeneticAlgorithm::getInst() {
	if (inst == 0) {
		inst = new GeneticAlgorithm();
	}

	return inst;
}

Tour* GeneticAlgorithm::selection(Population& pop) {

	Population tournament(tournament_size, false);
	int size = tournament.getN();


	for (int i = 0; i < tournament_size; i++) {
		//tournament.setElement(i, *pop.getElement(indices[i]));
	}

	return tournament.getFittestElement();
}

Tour* GeneticAlgorithm::crossover(Tour& t1, Tour& t2) {
	
	Tour* offspring = new Tour();


	
	return NULL;
}




#endif // !__GENETIC_ALGORITHM__
