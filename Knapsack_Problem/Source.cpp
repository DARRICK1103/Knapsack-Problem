/*
#include <iostream>

using namespace std;

const int gene = 10;
const int pop_size = 30;
const int capacity = 495;
const int weight[gene] = { 23, 31, 29, 44, 53, 38, 63, 85, 89,82 };
const int value[gene] = { 92, 57, 49, 68, 60, 43, 67, 84, 87, 92 };

double Fitness[pop_size];

int chromosome[pop_size][gene];

int parents[2][gene];

void initializePopulation()
{
	for (int i = 0; i < pop_size; i++)
	{
		int total = 0;
		for (int j = 0; j < gene; j++)
		{
			chromosome[i][j] = rand() % 6;
			
			
		
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
		//1.1 set totalWeight to 0 and set totalValue to 0   
		int totalWeight = 0, totalValue = 0;

		//1.2 for every genes, g in chromosome c  
		for (int j = 0; j < gene; j++)
		{
			//1.2.1 Implement the multiplication and addition process 
			totalWeight += weight[j] * chromosome[i][j];
			totalValue += value[j] * chromosome[i][j];
		}
		//1.3 Calculate the fitness value of c 
		double fitness = 0;
		//Calculate sum of values
		double SV = 0;
		for (int num = 0; num < gene; num++)
		{
			SV += value[num];
		}
		if (totalWeight > 495)
		{
			fitness = (totalValue / SV) * 0.5;
		}
		else
		{
			fitness = totalValue / SV;
		}
		//1.4 Print totalWeight, totalValue and fitness value of c 
		cout << "\nChromosome " << i << endl;
		cout << "Total Weight: " << totalWeight << "\tTotal Value: " << totalValue << "\tFitness: " << fitness << endl << endl;
		Fitness[i] = fitness;
	}
}

//declare parent’s data structure
void parentSelection() {
	//declare necessary variables
	int player1=0, player2=0;
	int indexParents[2]={};
	//1. For both parents
	for (int p = 0; p < 2; p++)
	{
		//1.1 Pick a random number to be the index for player 1
		player1 = rand() % pop_size;
		//1.2 Pick another random number to be the index for player 2
		do {
			player2 = rand() % pop_size;
		} while (player2 == player1);
			//1.3 Compare fitness between player 1 and 2, pick the best one to be parent 1
			if (Fitness[player1] >= Fitness[player2])
				indexParents[p] = player1;
			else
				indexParents[p] = player2;

			cout << "\n\n\t Player's index: " << player1 << " vs " << player2;
			cout << "\n\t Fitness: " << Fitness[player1] << " vs " << Fitness[player2];
			cout << "\n\t Winner " << p + 1 << ": " << indexParents[p];
		
	}
	cout << endl;
	//2. Repeat (1) for parent 2
		//3. Copy selected parents to array parents
		//4. Print parent 1 and 2
	for (int p = 0; p < 2; p++)
	{
		cout << "\n\tParent " << p + 1 << "\t";
		for (int g = 0; g < gene; g++)
		{
			parents[p][g] = chromosome[indexParents[p]][g];
			cout << parents[p][g] << " ";
		}
		cout << endl;
	}
	//NOTE: After you are done, improve your code to avoid the same number picked for
	//player 1 and player 2, and also avoid the same chromosome picked for parent 1
	//and 2
	
}

int main() 
{
	initializePopulation();
	printChromosome();
	evaluateChromosome();
	parentSelection();
	return 0;
}
*/