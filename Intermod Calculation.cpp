/* Intermod Calculation.cpp : This file contains the 'main' function. Program execution begins and ends there.
	Intermodulation Calculation Formula

*/

#include <iostream>
#include <vector>

int order;
int num_frequencies;


std::vector<double> frequency_vec; //vector that will hold all frequencies
std::vector<double> result_vec; //vector that will hold all results
std::vector<int> coefficient_produce; //vector that will have the possible coefficients 

//calculate intermodulation products
void calculate(int order_num, int frequencies_num, std::vector<double> fv)
{
	coefficient_produce = { -2,-1,1,2 };

	std::cout << "calculation function.";

	std::vector<std::vector<int> >coefficient_vec;

	//testing purposes:
	frequency_vec = { 400000000, 405000000 };

	//filling coefficient vector:
	for (int i = 0; i <= frequencies_num /*order number?*/; i++)
	{
		coefficient_vec.push_back(std::vector<int>());
		for (int j = 0; j <= frequencies_num; j++)
		{
			coefficient_vec[i].push_back(coefficient_produce[j]);
		}
	}
	   
	int sum = 0; //sum for adding frequencies together 

	for (int l = 0; l < frequencies_num; l++) //l to know how many times to rotate the frequency order
	{
		for (int k = 0; k <= coefficient_vec.size(); k++) //k to go through which coefficient combo
		{
			for (int i = 0, j = 0; i < frequencies_num; i++, j++) //i to go through frequency value, j to go through subarray of coefficient values.
			{
				sum += frequency_vec[i] * coefficient_vec[k][j];
			}
			//startup condition
			if (result_vec.size() == 0)
			{
				result_vec.push_back(sum);
				sum = 0;
			}
			//check for sum to be already present
			for (int i = 0; i < result_vec.size(); i++)
			{
				if (sum == result_vec[i])
				{
					sum = 0; //if the sum already exists, set the sum to zero 
				}
			}
			if (sum != 0) //if the sum has not been set to zero, push back sum value into resul vector
			{
				result_vec.push_back(sum);
				sum = 0;
			}
		}
		std::rotate(frequency_vec.begin(), frequency_vec.end() - 1, frequency_vec.end());
	}
		
	//std::vector<std::vector<int> > vec2(frequencies_num, vec);
}

int main()
{
	double input; //variable to reuse for inputs
	while (1)
	{
		std::cout << "Input order of calculation desired: " << std::endl;
		std::cin >> order;

		if (order % 2 == 1)
		{
			std::cout << "Input number of frequencies: " << std::endl;
			std::cin >> num_frequencies;
			std::cout << "Order chosen: " << order << "\nNumber of Frequencies: " << num_frequencies << std::endl;
			std::cout << "Input frequencies. \n";

			//take in frequencies in a for loop
			for (int i = 1; i <= num_frequencies; i++)
			{
				std::cout << "Input Frequncies. \nFrequnecy " << i << ": ";
				std::cin >> input;
				frequency_vec.push_back(input);
			}

			calculate(order, num_frequencies, frequency_vec);

			std::cout << "\n\nStart again. \n\n***********************************************\n\n";
		}
		else
		{
			std::cout << "Invalid order specified. Try again. \n\n ***********************************************\n\n";
		}
	}
}

