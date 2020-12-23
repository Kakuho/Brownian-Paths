#include <random>
#include <iostream>
#include <fstream>

int main()
{
	// What do we need for a simulation of Brownian motion?
	int  n = 1000.0;					// Time steps - a partition up to T.
	double stepSize;				 	// Size of each steps
	double t = 20.0;					// end of the partition

	stepSize = t/(n-1);
	
	// Need to generate the time steps for x axis.
	double x[n];						// X axis
	x[0] = 0.0;
	for (int i = 1; i < n ; i++)
		{
		x[i] = x[i-1] + stepSize;
		}

	// Implementing Stationary independent Increments
	std::default_random_engine generator;
	int paths = 5;
	double bm[n][paths];

	for(int l = 0 ; l < paths ; l++)					//Begin each paths at 0
		bm[0][l] = 0.0;

	for(int k = 0 ; k < paths ; k++)
	{
		for(int j = 1; j < n ; j++)
		{
			std::normal_distribution<> d(0, x[j] - x[j-1]);
			bm[j][k] = bm[j-1][k] + d(generator);

		}
	}

	// reading data
	for(int i = 0; i < n ; i++)
	{
		std::cout << "x[i] = " << x[i] 
			  << "| bm[i][0] = " <<  bm[i][0] << " |bm[i][1] = " << bm[i][1] 
			  << " | bm[i][2] = " << bm[i][2] << " |bm[i][3] = " << bm[i][3] << "\n";
	}

	// Read Data into Csv
	std::ofstream myfile;
	myfile.open("bmdata.csv");
	for(int i = 0; i < n ; i++)
	{

		myfile  << x[i] << ", " << bm[i][0] << "," << bm[i][1] << "," << bm[i][2] 
				<< ","  << bm[i][3] << "\n";
	}
	myfile.close();
	
}
