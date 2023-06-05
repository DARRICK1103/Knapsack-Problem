#include <iostream>
#include <fstream>
using namespace std;

const int gene = 10;
const int pop_size = 15;
const int capacity = 165;
const int weight[gene] = { 23, 31, 29, 44, 53, 38, 63, 85, 89,82 };
const int value[gene] = { 92, 57, 49, 68, 60, 43, 67, 84, 87, 92 };
int parents[2][gene];

double Fitness[pop_size];
int chromosome[pop_size][gene];

//declare CROSSOVER_PROBABILITY as a constant
const double crossover_probability = 0.9;
//declare children data structure
int children[2][gene];
// A temporary variable to store the new chromosome data structure
int new_chromosome[pop_size][gene];

//declare MUTATION_PROBABILITY as a constant
const double mutation_probability = 0.9;

int num_of_times = 1;

// number of generation
const int num_of_generation = 10;

// output file
ofstream averageFitnessFile;
ofstream bestFitnessFile;
ofstream bestChromosmeFile;

void initializePopulation()
{
	for (int i = 0; i < pop_size; i++)
	{
		for (int j = 0; j < gene; j++)
		{
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
		if (totalWeight > 165)
		{
			fitness = (totalValue / SV) * 0.5;
		}
		else
		{
			fitness = totalValue / SV;
		}
		//1.4 Print totalWeight, totalValue and fitness value of c
		cout << "\nChromosome " << i+1 << endl;
		cout << "Total Weight: " << totalWeight << "\tTotal Value: " << totalValue << "\tFitness: " << fitness << endl << endl;
		Fitness[i] = fitness;
	}
}

//declare parent’s data structure
void parentSelection() {
	//declare necessary variables
	int player1 = 0, player2 = 0;
	int indexParents[2] = {};
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

void crossover() {
	int cross_point;
	//1. Copy both parent’s chromosome to children chromosomes
	cout << "\n Children before crossover \n\n";
	for (int i = 0; i < 2; i++)
	{
		cout << " Children " << i + 1 << " : ";
		for (int j = 0; j < gene; j++)
		{
			children[i][j] = parents[i][j];
			cout << children[i][j] << "  ";
		}
		cout << endl;
	}
	//2. Generate a random number from 0-1. Make sure it is real value data type
	srand(time(NULL));
	double randomNum = (rand() % 11)/ 10.0;
	cout << "\n Random Number: " << randomNum << endl;
	//3. If (2) less than crossover probability
	if (randomNum <= crossover_probability)
	{
		cout << "\n Crossover happened at point ";
		//2.1 generate a random crossover point
		cross_point = (rand() % gene);
		cout << cross_point;
		//2.2 Crossover parent 1 and parent 2 to produce the children
		for (int i = cross_point; i < gene; i++)
		{
			children[0][i] = parents[1][i];
			children[1][i] = parents[0][i];
		}
		cout << "\n After crossover\n";
		//4. Print children 1 & 2
		for (int i = 0; i < 2; i++)
		{
			cout << "\n Children " << i + 1 << " : ";
			for (int j = 0; j < gene; j++)
			{
				cout << children[i][j] << "  ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "\n Crossover does not occur !" << endl;
	}


}

void mutation() {
	srand(time(NULL));
	//1. Declare necessary variables
	double randomNum;
	//2. Declare mutation bit
	int mutation_bit;
	//3. For both children
	for (int i = 0; i < 2; i++)
	{
	//3.1. Generate number from 0-1 (real values)

		randomNum = (rand() % 11) / 10.0;
		cout << " -------------------------------------------" << endl;
		cout << "\n Random number for " << "children " << i + 1 << " : " << randomNum << endl;
	//3.2. If 3.1 less than mutation probability
		if (randomNum <= mutation_probability)
		{

			cout << "\n Original Children " << i + 1 << " : ";
			for (int j = 0; j < gene; j++)
			{
				cout << children[i][j] << "  ";
			}
			cout << endl;

			//3.2.1. generate a mutation bit
			mutation_bit = rand() % gene;
			//3.2.2. Print the mutation bit
			cout << "\n Mutation bit: " << mutation_bit << endl;
			//3.2.3. Flip the mutation bit (if condition)
			children[i][mutation_bit] = (children[i][mutation_bit] == 0) ? 1 : 0;
			cout << "\n Children " << i + 1 << " : ";
			for (int j = 0; j < gene; j++)
			{
				cout << children[i][j] << "  ";
			}
			cout << endl;

		}
		else
			cout << " Mutation does not happened" << endl;

	//End if
	//End for
	}


}

//2. A counter for counting how many new chromosomes there are so far (array counter)
void survivalSelection_1() {
	//1. For each chromosome
	for (int i = 0; i < 2; i++)
	{
		//1.2. For each gene
		for (int g = 0; g < gene; g++)
		{
			//1.3 Copy children to the survival chromosome array
			new_chromosome[num_of_times][g] = children[i][g];
		}
		num_of_times++;
	}
	//2. Update array counter
	//3. Print chromosomes in the new population so far
	cout << "\n New Chromosome so far:\n ";
	for (int j = 0; j < pop_size; j++)
	{
		cout << "\n\t\t(" << j + 1 << ")\t:  ";
		for(int i = 0; i <gene;i++ )
		cout << new_chromosome[j][i] << "  ";
	}
}

//copy chromosome to the original data structure
void copyChromosome() {
	//1. For each chromosome
	for (int i = 0; i < pop_size; i++)
	{
		//1.2. For each gene
		for (int j = 0; j < gene; j++)
		{
			//1.3 Copy new chromosome to chromosome
			chromosome[i][j] = new_chromosome[i][j];
		}
	
	}
	
}

void calculateAverageFitness() {
	//1. Declare a variable for totalFitness, initialize to 0
	double totalFitness = 0;
	double avgFitness = 0;
	//2. For every chromosome
	for (int i = 0; i < pop_size; i++)
	{
		//2.1 Accumulate the fitness into totalFitness
		totalFitness += Fitness[i];
	}
	
	//3. Divide the totalFitness with population size
	avgFitness = totalFitness/pop_size;
	//4. Print out the average to the screen
	cout << "\n Average fitness = " << avgFitness << endl;;
	//5. Print out the average to an output file that keep average fitness
	averageFitnessFile << avgFitness << endl;
}

//1. Declare the bestChromosome data structure
int bestChromosome[gene] = {};
float bestFitness = -1;

void recordBestFitness() {
	
	//2. For each chromosome
	for (int i = 0; i < pop_size; i++)
	{
		//2.1. if (fitness current chromosome better than bestFitness)
		if (Fitness[i] > bestFitness)
		{
			//2.1.1. bestFitness = position of the best fitness for the current chromosome
			bestFitness = Fitness[i];
			//2.1.2. copy the chromosome to bestChromosome
			for (int j = 0; j < gene; j++)
			{
				bestChromosome[j] = chromosome[i][j];
			}
		}
	}
	//3. Print the bestFitness and bestChromosome to the screen
	cout << "\n Best Fitness: " << bestFitness;
	cout << "\n Best Chromosome: ";
	for (int i = 0; i < gene; i++)
	{
		cout << bestChromosome[i] << "  ";
		bestChromosmeFile << bestChromosome[i];
	}
	bestChromosmeFile << endl;
	//4. Print the bestFitness and bestChromosome to two separate files
	bestFitnessFile << bestFitness << endl;

}



int main()
{
	averageFitnessFile.open("AverageFitness.txt");
	bestChromosmeFile.open("BestChromosome.txt");
	bestFitnessFile.open("BestFitness.txt");
	int num = 0;
	cout << "\nINITIALIZE POPULATION\n";
	initializePopulation();
	do {
		cout << "\nGeneration " << num + 1 << endl;
		printChromosome();
		cout << "\nEVALUATE CHROMOSOME\n";
		evaluateChromosome();
		calculateAverageFitness();
		recordBestFitness();
		for (int i = 0; i < (pop_size / 2); i++)
		{
			num_of_times = i * 2;
			cout << "\nPARENT SELECTION\n";
			parentSelection();
			cout << "\nCROSSOVER\n";
			crossover();
			cout << "\nMUTATION\n";
			mutation();
			cout << "\nSurvival Selection\n";
			survivalSelection_1();
		}
		num_of_times = 0;
		copyChromosome();
		num++;
	} while (num != num_of_generation);
	averageFitnessFile.close();
	bestChromosmeFile.close();
	bestFitnessFile.close();
	return 0;
}