/* Intermod Calculation.cpp : This file contains the 'main' function. Program execution begins and ends there.
	Intermodulation Calculation Formula

*/
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <iomanip>
#include <sstream>

int order, range_frequencies;
float num_frequencies;

std::vector<float> frequency_vec; //vector that will hold all frequencies
std::vector<float> result_vec; //vector that will hold all results
std::vector<int> coefficient_produce; //vector that will have the possible coefficients 
std::vector<std::vector<float>> freq_k;

//find the absolute coeffiecient combinations for the order
void subsetSummation(std::vector<float> numbers, int target, std::vector<float> partial = {}) {
	//find absolute values of numbers then find sum
	std::vector<float> abs_numbers;
	for (int i = 0; i < partial.size(); i++) {
		abs_numbers.push_back(abs(partial[i]));
	}
	int sum = accumulate(abs_numbers.begin(), abs_numbers.end(), 0);

	//if sum equals target print and add vector of values to total
	if (sum == target) {
		std::cout << "[ ";
		for (int i = 0; i < partial.size(); i++) {
			std::cout << partial.at(i) << " ";
		}
		std::cout << "] = " << target << std::endl;
		freq_k.push_back(partial);
	}
	//break recursion on equal target or greater than target
	if (sum >= target) {
		return;
	}

	//iterate through range recursively 
	for (int i = 0; i < numbers.size(); i++) {
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
	std::cout << "calculation function.";

	std::vector<std::vector<float> >coefficient_vec;
	coefficient_vec = freq_k;

	float sum = 0; //sum for adding frequencies together 
	//int result_increment = 0; //variable to increment result as it is stepped through
	std::string equation;
	float temp_holder;
	std::ostringstream output_format;

	for (int l = 0; l < frequencies_num; l++) //l to know how many times to rotate the frequency order
	{
		for (int k = 0; k < coefficient_vec.size(); k++) //k to go through which coefficient combo
		{
			for (int i = 0, flag = 0; i < frequency_vec.size(); i++)
			{
				for (int i = 0, j = 0, time = 0; i < frequencies_num; i++, j++, time++) //i to go through frequency value, j to go through subarray of coefficient values.
				{
					sum += frequency_vec[i] * coefficient_vec[k][j];
				
					if (coefficient_vec[k][j] >= 0) //if a positive value, add a positive sign to assist in formatting
					{
						equation += "+";
					}
					
					temp_holder = coefficient_vec[k][j]; //store value into float
					
					output_format << std::fixed << std::setprecision(0) << temp_holder;//format float
					equation += output_format.str(); //add to string
					output_format.str(""); //clear output string stream
					equation += " * "; 
		
					temp_holder = frequency_vec[i]; 
					
					output_format << std::fixed << std::setprecision(2) << temp_holder;
					equation += output_format.str();
					output_format.str("");
					
					if (time < frequencies_num - 1) //add a plus sign for continuing equation
					{
						equation += " + ";
					}
				}
				if (sum < (range_frequencies + frequency_vec[i])) //if sum is within range
				{
					if (sum > (frequency_vec[i] - range_frequencies))
					{
						flag = 1;
					}
					if (flag == 1) 
					{
						if (result_vec.size() == 0)
						{
							result_vec.push_back(sum);
							std::cout << "\n\nRESULTS:\n________________________\n\nResult " << std::setw(2) << result_vec.size() << " was: "  << std::fixed << std::setprecision(2) << std::setw(7) << sum << "\tfor frequency combo: " << std::setw(20) << equation << std::endl;
						}
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
							std::cout << "Result " << std::setw(2) << result_vec.size() << " was: " << std::fixed << std::setprecision(2) << std::setw(7) << sum << "\tfor frequency combo: " << std::setw(20) << equation << std::endl;
						}
					}
				}
				flag = 0;
				sum = 0;
				equation.erase();
			}
		}
		std::rotate(frequency_vec.begin(), frequency_vec.end() - 1, frequency_vec.end());
	}
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

			//generate range based on order
			std::vector<float> coeffArray;
			for (int i = -order + 1; i < order; i++) 
			{
				coeffArray.push_back(i);
			}
			coeffArray.erase(coeffArray.begin() + order - 1);

			//generate list of coefficients for calculation
			std::cout << "Coefficient Combinations List:" << std::endl;
			subsetSummation(coeffArray, order);
			//calculate intermodulation product
			calculate(order, num_frequencies);

			std::cout << "\n\nStart again. \n\n***********************************************\n\n";
		}
		else
		{
			std::cout << "Invalid order specified. Try again. \n\n ***********************************************\n\n";
		}
	}
}

