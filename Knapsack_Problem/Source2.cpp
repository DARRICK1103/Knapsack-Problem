/*
#include <iostream>
using namespace std;

// define population size = 10
const int pop_size = 10;
// 10 gene in a chromosome
const int gene = 10;

int chromosome[pop_size][gene];

// Competency Level
int competency[gene] = {5, 6, 4, 7, 8, 9, 3, 4, 7, 8};

// Rate per hour
int rate[gene] = { 200, 250, 200, 400, 450, 600, 150, 150, 350, 500 };

// Fitness of each chromosome
double Fitness[pop_size];

void initializeChromosome()
{
	srand(time(NULL));
	for (int i = 0; i < pop_size; i++)
	{
		for (int j = 0; j < gene; j++)
		{
			// initialize the chromosome
			chromosome[i][j] = rand() % 2;
		}
	}
}

void printChromosome()
{
	for (int i = 0; i < pop_size; i++)
	{
		cout << "\n Chromosome " << i + 1 << endl;
		for (int j = 0; j < gene; j++)
		{
			cout << "\t" << chromosome[i][j];
		}
		cout << endl;
	}
}

void evaluateChromosome()
{
	//1. For every chromosome, c
	for (int i = 0; i < pop_size; i++)
	{
		//1.1 set totalCompetency to 0 and set totalRate to 0
		int totalCompetency = 0, totalRate = 0;

		//1.2 for every genes, g in chromosome c
		for (int j = 0; j < gene; j++)
		{
			//1.2.1 Implement the multiplication and addition process
			totalRate += rate[j] * chromosome[i][j];
			totalCompetency += competency[j] * chromosome[i][j];
		}
		//1.3 Calculate the fitness value of c
		double fitness = 0;
		//Calculate sum of rate
		double SumRate = 0;
		for (int num = 0; num < gene; num++)
		{
			SumRate += competency[num];
		}
		if (totalRate > 1500)
		{
			fitness = (totalCompetency / SumRate) * 0.5;
		}
		else
		{
			fitness = totalCompetency / SumRate;
		}
		//1.4 Print totalWeight, totalValue and fitness value of c
		cout << "\nChromosome " << i + 1 << endl;
		cout << "Total Competency: " << totalCompetency << "\tTotal Rate per hour: " << totalRate << "\tFitness: " << fitness << endl << endl;
		
		Fitness[i] = fitness;
	}
}

int main()
{
	cout << "\n  Initialize Chromosome\n\n";
	initializeChromosome();
	printChromosome();
	cout << "\n\n  Evaluate Chromosome\n\n";
	evaluateChromosome();
	
	
	double fittest = 0;
	int num = 0;
	for (int i = 0; i < pop_size; i++)
	{
		if (Fitness[i] > fittest)
		{
			fittest = Fitness[i];
			num = i;
		}
	}

	cout << "\n  The fittest chromosome is chromosome " << fittest + 1 << " with fitness value " << Fitness[num] << endl;
	cout << "\n  Fittest chromosome: " << endl;
	for (int i = 0; i < gene; i++)
	{
		cout << "  " << chromosome[num][i];
	}
	


	return 0;
}
*/