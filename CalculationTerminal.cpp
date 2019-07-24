#include "CalculationTerminal.h"
//Constructor:
CalculationTerminal::CalculationTerminal(void)
{

}

//Destructor:
CalculationTerminal::~CalculationTerminal()
{

}

//Coefficient production function:
void CalculationTerminal::coefficient_produce(int order_num, int frequencies_used)
{
	coefficient_vec.clear();
	coefficient_possibilities_vec.clear();
	incrementer_one = 0;
	//fill vector with possible coefficient values:
	for (int i = -(order_num - 1); i < (order_num + 1); i++)
	{
		if (i != 0)
		{
			coefficient_possibilities_vec.push_back(i);
		}
	}
	//create coefficient_vec
	if (frequencies_used == 2)
	{
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
	}//end if
	else if (frequencies_used == 3)
	{
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
	} //end if 
}

//Factorial equation to produce the correct number of permutations for the entered number of frequencies:
int CalculationTerminal::factorial(int n)
{
	int result = 1;
	while (n > 1) {
		result *= n--;
	}
	return result;
}

//Produce permutations:
std::vector<std::vector<float>> CalculationTerminal::permutations_produce(std::vector<float> inputFreq, int perm_num)
{
	std::vector<float> freq(inputFreq);
	std::sort(freq.begin(), freq.end());
	freq.erase(unique(freq.begin(), freq.end()), freq.end());
	int repeat = factorial(freq.size() - perm_num);
	std::vector<std::vector<float>> total;
	std::vector<float> p;
	int result = factorial(freq.size()) / factorial(freq.size() - perm_num);
	do
	{
		for (int i = 0; i < perm_num; i++)
		{
			p.push_back(freq[i]);
		}//end for
		std::cout << std::endl;
		for (int i = 1; i != repeat; i++)
		{
			std::next_permutation(freq.begin(), freq.end());
		} //end for
		total.push_back(p);
		p.clear();
	} while (std::next_permutation(freq.begin(), freq.end())); //end do while
	//std::cout << '\n' << "# of perms: " << total.size() << '\n';
	return total;
}//end permutations_produce()

//Summation Calculation:
void CalculationTerminal::summation(int frequencies_used)
{
	float sum = 0; //sum for adding frequencies together 
	std::string equation;
	int order_sum = 0;
	std::ostringstream output_format;
	for (int i = 0; i < coefficient_vec.size(); i++)
	{
		for (int j = 0; j < frequency_combos_vec.size(); j++)
		{
			for (int k = 0; k < frequencies_used; k++)
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

				if (k < (frequencies_used - 1))
				{
					equation += " + ";
				}//end if 

			}//end for 
			int flag = 0;
			for (int l = 0; l < rxfrequency_vec.size(); l++)
			{
				if (sum <= (rxfrequency_vec[l] + range_frequencies))
				{
					if (sum >= (rxfrequency_vec[l] - range_frequencies))
					{
						if (flag == 0)
						{
							result_vec.push_back(sum);
							result_vec_2d.push_back(std::vector<float>());
							std::cout << "\nHit " << std::setw(2) << result_vec.size() << " was: " << std::fixed << std::setprecision(2) << std::setw(7) << sum << "\tfor frequency combo: " << std::setw(20) << equation;
							equation = "Hit:  " + std::to_string(sum) + " for frequency combo: " + equation;
							result_vec_2d[step].push_back(rxfrequency_vec[l]);
							std::cout << " at Receiver Frequencies: " << rxfrequency_vec[l];
							equation_vec.push_back(equation);
							flag++;
							step++;
						}//end if
						else
						{
							std::cout << " , " << rxfrequency_vec[l];
							result_vec_2d[step - 1].push_back(rxfrequency_vec[l]);
							equation += std::to_string(rxfrequency_vec[l]);
						}//end else
					}//end if 
				}//end if 
			}//end for 
			//std::cout << std::endl;
			sum = 0;
			equation = "";
		}//end for 
	}//end for
	result_size_vec.push_back(result_vec.size() - n);
	n = result_vec.size();
} //end void summation()

//Calculate Function:
void CalculationTerminal::calculate(int order_num)
{
	std::cout << "\n\nOrder " << std::fixed << std::setw(2) << order_num << " products: \n_______________________________\n\n";
	std::cout << "2 Frequency Results: \n\n";
	int incrementer_one = 0; //integer to access the right sub vector of coefficient combinations 
	coefficient_produce(order_num, 2);
	if (order_num == 3)
	{
		frequency_combos_vec_2 = permutations_produce(frequency_vec, 2);
	}//end if
	frequency_combos_vec = frequency_combos_vec_2;
	summation(2);

	//if it is third order, calculate 3 frequency combos:
	if (order_num == 3)
	{
		//if more than two frequencies:
		if (frequency_vec.size() >= 3)
		{
			std::cout << "\n\n3 Frequency Results: \n";
			coefficient_produce(order_num, 3);
			frequency_combos_vec_3 = permutations_produce(frequency_vec, 3);
			frequency_combos_vec = frequency_combos_vec_3;
			summation(3);
		}//end if
	}//end if
} //end void calculate

//Run Function:
void CalculationTerminal::run()
{
	CalculationTerminal calcinst; //instantiate class
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

			std::cout << "Input Range (in MHz) for hits desired: " << std::endl;
			std::cin >> range_frequencies;
			std::cout << "Input frequencies (in MHz). \n";

			//take in frequencies in a for loop
			for (int i = 1; i <= num_frequencies; i++)
			{
				std::cout << "Input Frequncies. \nTransmit Frequnecy " << i << ": ";
				std::cin >> input;
				frequency_vec.push_back(input);
				std::cout << "\nReceive Frequency " << i << ": ";
				std::cin >> input;
				rxfrequency_vec.push_back(input);
				//frequency_vec.push_back(input);
			}//end for
			std::cout << "\nRESULTS:\n_______________________________\n\n" << std::endl;
			for (int order_increment = 2; order_increment <= order; order_increment++)
			{
				if (order_increment % 2 == 1)
				{
					//calculate intermodulation product:
					calcinst.calculate(order_increment);
				}//end if
			}//end for
			int counter = 0;
			frequency_vec.clear();
			result_vec.clear();
			result_vec_2d.clear();
			step = 0;
			result_size_vec.clear();
			equation_vec.clear();
			std::cout << "\n\nStart again. \n\n***********************************************\n\n";
		}//end if
		else
		{
			std::cout << "Invalid order specified. Try again. \n\n ***********************************************\n\n";
		}//end else
	}//end while
}//end void run()