/* Intermod Calculation.cpp : This file contains the 'main' function. Program execution begins and ends there.
	Intermodulation Calculation Formula

*/
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>

int order, range_frequencies;
float num_frequencies;
int unique_freq_orders;

std::vector<float> frequency_vec; //vector that will hold all frequencies
std::vector<float> result_vec; //vector that will hold all results
std::vector<int> coefficient_produce; //vector that will have the possible coefficients 
std::vector<std::vector<float>> freq_k;
std::vector<std::string> equation_vec;
std::vector<std::vector<float>> total;

//find the absolute coeffiecient combinations for the order
void subsetSummation(std::vector<float> numbers, int target, std::vector<float> partial = {}) {
	
	//find absolute values of numbers then find sum
	std::vector<float> abs_numbers;
	for (int i = 0; i < partial.size(); i++) 
	{
		abs_numbers.push_back(abs(partial[i]));
		while (partial.size() < 2)
		{
			partial.push_back(0);
		}
	}
	int sum = accumulate(abs_numbers.begin(), abs_numbers.end(), 0);

	//if sum equals target print and add vector of values to total
	if (sum == target) 
	{
		freq_k.push_back(partial);
	}
	//break recursion on equal target or greater than target
	if (sum >= target) {
		//hi
		return;
	}

	//iterate through range recursively 
	for (int i = 0; i < numbers.size(); i++) 
	{
		int n = numbers[i];
		std::vector<float> remaining(numbers.begin() + i + 1, numbers.end());

		std::vector<float> p(partial);
		p.push_back(n);
		subsetSummation(remaining, target, p);
	}
}


//calculate intermodulation products
void calculate(int order_num, int frequencies_num)
{
	std::vector<std::vector<float> >coefficient_vec;
	coefficient_vec = freq_k;

	float sum = 0; //sum for adding frequencies together 
	std::string equation;
	int order_sum = 0;
	std::ostringstream output_format;

	//function to get all permutations of frequencies: 
	std::vector<float> p;

	int permute_counter = 2; //only for 2 and 3 frequency combos
	//this is where the problem is:
	do
	{
		do
		{
			for (int i = 0; i < permute_counter; i++)
			{
				std::cout << frequency_vec[i] << " ";
				p.push_back(frequency_vec[i]);

			}
			std::cout << std::endl;
			std::reverse(frequency_vec.begin() + permute_counter, frequency_vec.end());
			total.push_back(p);
			p.clear();

		} while (std::next_permutation(frequency_vec.begin(), frequency_vec.end()));
		permute_counter++;
	} while (permute_counter < 3);
	//end function to get permutations

	std::cout << "\nOrder " << std::fixed << std::setw(2) << order_num << " products: \n_______________________________\n\n";

	for (int l = 0; l < total.size(); l++) //l to rotate through all frequency permutations
	{
		for (int k = 0; k < coefficient_vec.size(); k++) //k to go through which coefficient combo
		{
			for (int i = 0, flag = 0; i < total[l].size(); i++)
			{
				for (int j = 0, time = 0; j < total[l].size() ; j++, time++) //i to go through frequency value, j to go through subarray of coefficient values.
				{
					if (l >= (num_frequencies * (num_frequencies - 1)))
					{
						return;
					}
						sum += total[l][j] * coefficient_vec[k][j];
						order_sum += coefficient_vec[k][j];

						if (coefficient_vec[k][j] >= 0) //if a positive value, add a positive sign to assist in formatting
						{
							equation += "+";
						}

						float temp_holder; //temporary variable for holding numbers
						temp_holder = coefficient_vec[k][j]; //store value into float
						output_format << std::fixed << std::setprecision(0) << temp_holder;//format float
						equation += output_format.str(); //add to string
						output_format.str(""); //clear output string stream
						equation += " * ";
						temp_holder = total[l][j];
						output_format << std::fixed << std::setprecision(2) << temp_holder;
						equation += output_format.str();
						output_format.str("");	
						if (time < total[l].size() - 1) //add a plus sign for continuing equation
						{
							equation += " + ";
						}
				}
				if (sum < (range_frequencies + total[l][i])) //if sum is within range
				{
					if (sum > (total[l][i] - range_frequencies))
					{
						flag = 1;
					}
					if (sum < 0)
					{
						flag = 0;
					}
					if (order_sum > order_num)
					{
						flag = 0;
					}
					if (flag == 1)
					{
						//startup condition for if vector is empty
						if (result_vec.size() == 0)
						{
							result_vec.push_back(sum);
							std::cout << "\nResult " << std::setw(2) << result_vec.size() << " was: " << std::fixed << std::setprecision(2) << std::setw(7) << sum << "\tfor frequency combo: " << std::setw(20) << equation << std::endl;
							equation = "Hit:  " + std::to_string(sum) + " for frequency combo: " + equation;
							equation_vec.push_back(equation);
						}
						for (int step_2 = 0; step_2 < result_vec.size(); step_2++)
						{
							if (sum == result_vec[step_2])
							{
								sum = 0; //if the sum already exists, set the sum to zero 
							}
						}
						if (sum != 0) //if the sum has not been set to zero, push back sum value into resul vector
						{
							result_vec.push_back(sum);
							std::cout << "Result " << std::setw(2) << result_vec.size() << " was: " << std::fixed << std::setprecision(2) << std::setw(7) << sum << "\tfor frequency combo: " << std::setw(20) << equation << std::endl;
							equation = "Hit:  " + std::to_string(sum) + "for frequency combo: " + equation;
							equation_vec.push_back(equation);
						}
					}
				}
				flag = 0;
				sum = 0;
				equation.erase();
				order_sum = 0;
			}
		}
	}
	result_vec.clear();
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
			
			unique_freq_orders = 1;
			int temp_num_frequencies = num_frequencies;
			while (temp_num_frequencies != 0)
			{
				unique_freq_orders *= temp_num_frequencies;
				temp_num_frequencies--;
			}
		
			std::cout << "Input Range (in MHz) for hits desired: " << std::endl;
			std::cin >> range_frequencies;

			std::cout << "Input frequencies (in MHz). \n";

			//take in frequencies in a for loop
			for (int i = 1; i <= num_frequencies; i++)
			{
				std::cout << "Input Frequncies. \nFrequnecy " << i << ": ";
				std::cin >> input;
				frequency_vec.push_back(input);
			}
			std::cout << "\nRESULTS:\n_______________________________\n\n" << std::endl;


			for (int order_increment = 2; order_increment <= order; order_increment++)
			{
				if (order_increment % 2 == 1)
				{
					//generate range based on order
					std::vector<float> coeffArray;
					for (int i = -order_increment + 1; i < order_increment; i++)
					{
						coeffArray.push_back(i);
					}
					coeffArray.erase(coeffArray.begin() + order_increment - 1);

					//generate list of coefficients for calculation
					//std::cout << "Coefficient Combinations List:" << std::endl;
					//freq_k.clear();
					subsetSummation(coeffArray, order_increment);

					//calculate intermodulation product:
					calculate(order_increment, num_frequencies);
					//permute_counter++;
				}
			}

			std::cout << "\n\nStart again. \n\n***********************************************\n\n";
		}
		else
		{
			std::cout << "Invalid order specified. Try again. \n\n ***********************************************\n\n";
		}
				
	}
}

/*
if it is third order, loop through 2 and 3 frequency combos.
If it is fifth order and up, loop through only 2 frequency combos. 


*/