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

std::vector<float> frequency_vec; //vector that will hold all frequencies
std::vector<float> result_vec; //vector that will hold all results
std::vector<std::string> equation_vec;


//calculate intermodulation products
void calculate(int order_num)
{
	std::vector<std::vector<float> >coefficient_vec;
	std::vector<float> coefficient_possibilities_vec;
	std::vector<std::vector<float> > frequency_combos_vec;
	std::vector<float> temp; //temporary vector for storing intermediate vectors

	float sum = 0; //sum for adding frequencies together 
	std::string equation;
	int order_sum = 0;
	std::ostringstream output_format;

	//fill vector with possible coefficient values:
	for (int i = -(order_num - 1); i < (order_num + 1); i++)
	{
		if (i != 0)
		{
			coefficient_possibilities_vec.push_back(i);
		}
	}

	//if it is third order, calculate 2 frequency and then 3 frequency combos:
	if (order_num == 3)
	{
		//if only two frequencies:
		std::cout << "\nOrder " << std::fixed << std::setw(2) << order_num << " products: \n_______________________________\n\n";
		std::cout << "2 Frequency Results: \n\n";
		int incrementer_one = 0; //integer to access the right sub vector of coefficient combinations 

		for (int incrementer_store = 0; incrementer_store < coefficient_possibilities_vec.size(); incrementer_store++)
		{
			for (int incrementer_change = 0; incrementer_change < coefficient_possibilities_vec.size(); incrementer_change++)
			{	
				if ((abs(coefficient_possibilities_vec[incrementer_store]) + abs(coefficient_possibilities_vec[incrementer_change])) == order_num  )
				{	
					coefficient_vec.push_back(std::vector<float>());
					coefficient_vec[incrementer_one].push_back(coefficient_possibilities_vec[incrementer_store]);
					coefficient_vec[incrementer_one].push_back(coefficient_possibilities_vec[incrementer_change]);
					incrementer_one++;
				}//end if
			}//end for
		}//end for 

		//code to get permutations of frequencies for two frequencies:
		do
		{
			for (int i = 0; i < 2; i++)
			{
				temp.push_back(frequency_vec[i]);
			} //end for
			std::reverse(frequency_vec.begin() + 2, frequency_vec.end());
			frequency_combos_vec.push_back(temp);
			temp.clear();
		} while (std::next_permutation(frequency_vec.begin(), frequency_vec.end()));  //end do while
	
		//code to calculate for two frequencies: 
		for (int i = 0; i < coefficient_vec.size(); i++)
		{
			for (int j = 0; j < frequency_combos_vec.size(); j++)
			{
				for (int k = 0; k < 2; k++)
				{
					sum += frequency_combos_vec[j][k] * coefficient_vec[i][k];
					
					//add positive sign if the number is positive to assist in formatting
					if (coefficient_vec[i][k] >= 0)
					{
						equation += "+";
					}//end if 
					//formatting of output in terminal: 
					float temp_holder; //temporary variable for holding numbers

					temp_holder = coefficient_vec[i][k]; //store value into float
					output_format << std::fixed << std::setprecision(0) << temp_holder;//format float
					equation += output_format.str(); //add to string
					output_format.str(""); //clear output string stream

					equation += " * ";

					temp_holder = frequency_combos_vec[j][k];
					output_format << std::fixed << std::setprecision(2) << temp_holder;
					equation += output_format.str();
					output_format.str("");

					if (k < 1)
					{
						equation += " + ";
					}//end if 

					
				}//end for 
				if (sum < (frequency_combos_vec[j][0] + range_frequencies))
					{
						if (sum > (frequency_combos_vec[j][0] - range_frequencies))
						{
							//startup condition for if vector is empty
							if (result_vec.size() == 0)
							{
								result_vec.push_back(sum);
								std::cout << "\nResult " << std::setw(2) << result_vec.size() << " was: " << std::fixed << std::setprecision(2) << std::setw(7) << sum << "\tfor frequency combo: " << std::setw(20) << equation << std::endl;
								equation = "Hit:  " + std::to_string(sum) + " for frequency combo: " + equation;
								equation_vec.push_back(equation);
							}//end if

							for (int step_2 = 0; step_2 < result_vec.size(); step_2++)
							{
								if (sum == result_vec[step_2])
								{
									sum = 0; //if the sum already exists, set the sum to zero 
								}//end if 
							}//end for

							if (sum != 0) //if the sum has not been set to zero, push back sum value into resul vector
							{
								result_vec.push_back(sum);
								std::cout << "Result " << std::setw(2) << result_vec.size() << " was: " << std::fixed << std::setprecision(2) << std::setw(7) << sum << "\tfor frequency combo: " << std::setw(20) << equation << std::endl;
								equation = "Hit:  " + std::to_string(sum) + "for frequency combo: " + equation;
								equation_vec.push_back(equation);
							}//end if
						}//end if 
					}//end if 
				sum = 0;
				equation = "";
			}//end for 
		}//end for


		//if more than two frequencies:
		if (frequency_vec.size() >= 3)
		{
			std::cout << "\n\n3 Frequency Results: \n\n";
			//clear vectors and reset counter to make calculation easier;
			incrementer_one = 0;
			coefficient_vec.clear();
			frequency_combos_vec.clear();

			for (int incrementer_store = 0; incrementer_store < coefficient_possibilities_vec.size(); incrementer_store++)
			{
				for (int incrementer_change = 0; incrementer_change < coefficient_possibilities_vec.size(); incrementer_change++)
				{
					for (int incrementer_change_two = 0; incrementer_change_two < coefficient_possibilities_vec.size(); incrementer_change_two++)
					{
						if ((abs(coefficient_possibilities_vec[incrementer_store]) + abs(coefficient_possibilities_vec[incrementer_change]) + abs(coefficient_possibilities_vec[incrementer_change_two])) == order_num)
						{
							coefficient_vec.push_back(std::vector<float>());
							coefficient_vec[incrementer_one].push_back(coefficient_possibilities_vec[incrementer_store]);
							coefficient_vec[incrementer_one].push_back(coefficient_possibilities_vec[incrementer_change]);
							coefficient_vec[incrementer_one].push_back(coefficient_possibilities_vec[incrementer_change_two]);
							incrementer_one++;
						}//end if
					}
				}//end for
			}//end for 

			//code to get permutations of frequencies for three frequencies:
			do
			{
				for (int i = 0; i < 3; i++)
				{
					temp.push_back(frequency_vec[i]);
				}
				std::reverse(frequency_vec.begin() + 3, frequency_vec.end());
				frequency_combos_vec.push_back(temp);
				temp.clear();
			} while (std::next_permutation(frequency_vec.begin(), frequency_vec.end()));

			for (int i = 0; i < coefficient_vec.size(); i++)
			{
				for (int j = 0; j < frequency_combos_vec.size(); j++)
				{
					for (int k = 0; k < 3; k++)
					{
						sum += frequency_combos_vec[j][k] * coefficient_vec[i][k];

						//add positive sign if the number is positive to assist in formatting
						if (coefficient_vec[i][k] >= 0)
						{
							equation += "+";
						}//end if 
						//formatting of output in terminal: 
						float temp_holder; //temporary variable for holding numbers

						temp_holder = coefficient_vec[i][k]; //store value into float
						output_format << std::fixed << std::setprecision(0) << temp_holder;//format float
						equation += output_format.str(); //add to string
						output_format.str(""); //clear output string stream

						equation += " * ";

						temp_holder = frequency_combos_vec[j][k];
						output_format << std::fixed << std::setprecision(2) << temp_holder;
						equation += output_format.str();
						output_format.str("");

						if (k < 2)
						{
							equation += " + ";
						}//end if 


					}//end for 
					if (sum < (frequency_combos_vec[j][0] + range_frequencies))
					{
						if (sum > (frequency_combos_vec[j][0] - range_frequencies))
						{
							//startup condition for if vector is empty
							if (result_vec.size() == 0)
							{
								result_vec.push_back(sum);
								temp.push_back(sum);
								std::cout << "\nResult " << std::setw(2) << result_vec.size() << " was: " << std::fixed << std::setprecision(2) << std::setw(7) << sum << "\tfor frequency combo: " << std::setw(20) << equation << std::endl;
								equation = "Hit:  " + std::to_string(sum) + " for frequency combo: " + equation;
								equation_vec.push_back(equation);
							}//end if
							for (int step_2 = 0; step_2 < temp.size(); step_2++)
							{
								if (sum == result_vec[step_2])
								{
									sum = 0; //if the sum already exists, set the sum to zero 
								}//end if 
							}//end for

							if (sum != 0) //if the sum has not been set to zero, push back sum value into resul vector
							{
								temp.push_back(sum);
								result_vec.push_back(sum);
								std::cout << "Result " << std::setw(2) << result_vec.size() << " was: " << std::fixed << std::setprecision(2) << std::setw(7) << sum << "\tfor frequency combo: " << std::setw(20) << equation << std::endl;
								equation = "Hit:  " + std::to_string(sum) + "for frequency combo: " + equation;
								equation_vec.push_back(equation);
							}//end if
						}//end if 
					}//end if 
					sum = 0;
					equation = "";
				}//end for 
			}//end for

		}//end if


	}//end if


	//if it is anything but third order, calculate only 2 frequency combinations:
	else
	{ 
	    std::cout << "\nOrder " << std::fixed << std::setw(2) << order_num << " products: \n_______________________________\n\n";
		std::cout << "2 Frequency Results: \n\n";
		int incrementer_one = 0; //integer to access the right sub vector of coefficient combinations 

		for (int incrementer_store = 0; incrementer_store < coefficient_possibilities_vec.size(); incrementer_store++)
		{
			for (int incrementer_change = 0; incrementer_change < coefficient_possibilities_vec.size(); incrementer_change++)
			{
				if ((abs(coefficient_possibilities_vec[incrementer_store]) + abs(coefficient_possibilities_vec[incrementer_change])) == order_num)
				{
					coefficient_vec.push_back(std::vector<float>());
					coefficient_vec[incrementer_one].push_back(coefficient_possibilities_vec[incrementer_store]);
					coefficient_vec[incrementer_one].push_back(coefficient_possibilities_vec[incrementer_change]);
					incrementer_one++;
				}//end if
			}//end for
		}//end for 

		//code to get permutations of frequencies for two frequencies:
		do
		{
			for (int i = 0; i < 2; i++)
			{
				temp.push_back(frequency_vec[i]);
			} //end for
			std::reverse(frequency_vec.begin() + 2, frequency_vec.end());
			frequency_combos_vec.push_back(temp);
			temp.clear();
		} while (std::next_permutation(frequency_vec.begin(), frequency_vec.end()));  //end do while

		//code to calculate for two frequencies: 
		for (int i = 0; i < coefficient_vec.size(); i++)
		{
			for (int j = 0; j < frequency_combos_vec.size(); j++)
			{
				for (int k = 0; k < 2; k++)
				{
					sum += frequency_combos_vec[j][k] * coefficient_vec[i][k];

					//add positive sign if the number is positive to assist in formatting
					if (coefficient_vec[i][k] >= 0)
					{
						equation += "+";
					}//end if 
					//formatting of output in terminal: 
					float temp_holder; //temporary variable for holding numbers

					temp_holder = coefficient_vec[i][k]; //store value into float
					output_format << std::fixed << std::setprecision(0) << temp_holder;//format float
					equation += output_format.str(); //add to string
					output_format.str(""); //clear output string stream

					equation += " * ";

					temp_holder = frequency_combos_vec[j][k];
					output_format << std::fixed << std::setprecision(2) << temp_holder;
					equation += output_format.str();
					output_format.str("");

					if (k < 1)
					{
						equation += " + ";
					}//end if 


				}//end for 
				if (sum < (frequency_combos_vec[j][0] + range_frequencies))
				{
					if (sum > (frequency_combos_vec[j][0] - range_frequencies))
					{
						//startup condition for if vector is empty
						if (result_vec.size() == 0)
						{
							result_vec.push_back(sum);
							std::cout << "\nResult " << std::setw(2) << result_vec.size() << " was: " << std::fixed << std::setprecision(2) << std::setw(7) << sum << "\tfor frequency combo: " << std::setw(20) << equation << std::endl;
							equation = "Hit:  " + std::to_string(sum) + " for frequency combo: " + equation;
							equation_vec.push_back(equation);
						}//end if

						for (int step_2 = 0; step_2 < result_vec.size(); step_2++)
						{
							if (sum == result_vec[step_2])
							{
								sum = 0; //if the sum already exists, set the sum to zero 
							}//end if 
						}//end for

						if (sum != 0) //if the sum has not been set to zero, push back sum value into resul vector
						{
							result_vec.push_back(sum);
							std::cout << "Result " << std::setw(2) << result_vec.size() << " was: " << std::fixed << std::setprecision(2) << std::setw(7) << sum << "\tfor frequency combo: " << std::setw(20) << equation << std::endl;
							equation = "Hit:  " + std::to_string(sum) + "for frequency combo: " + equation;
							equation_vec.push_back(equation);
						}//end if
					}//end if 
				}//end if 
				sum = 0;
				equation = "";
			}//end for 
		}//end for


	}//end else
}//end void calculate()

int main()
{
	double input; //variable to reuse for inputs
	while (1)
	{
		std::cout << "Input order of calculation desired: " << std::endl;
		std::cin >> order;

		if (order % 2 == 1)
		{
			int num_frequencies;
			std::cout << "Input number of frequencies: " << std::endl;
			std::cin >> num_frequencies;
			std::cout << "Order chosen: " << order << "\nNumber of Frequencies: " << num_frequencies << std::endl;

			int unique_freq_orders = 1;
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

					//calculate intermodulation product:
					calculate(order_increment);
				}
			}
			frequency_vec.clear();
			result_vec.clear();
			equation_vec.clear();
			std::cout << "\n\nStart again. \n\n***********************************************\n\n";
		}
		else
		{
			std::cout << "Invalid order specified. Try again. \n\n ***********************************************\n\n";
		}

	}
}
