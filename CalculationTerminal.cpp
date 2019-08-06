#include "CalculationTerminal.h"
//Constructor:
CalculationTerminal::CalculationTerminal(QObject* parent)
	: QObject(parent)
{

}//end constructor 

//Destructor:
CalculationTerminal::~CalculationTerminal()
{

}//end destructor

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
		}//end if 
	}//end for 
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
	while (n > 1) 
	{
		result *= n--;
	}
	return result;
}

//Produce permutations:
std::vector<std::vector<float>> CalculationTerminal::permutations_produce(std::vector<float> inputFreq, int perm_num)
{
	std::vector<float> freq(inputFreq);
	std::sort(freq.begin(), freq.end());
	//int repeat = factorial(freq.size() - perm_num);
	std::vector<std::vector<float>> total;
	std::vector<float> p;
	int result = factorial(freq.size()) / factorial(freq.size() - perm_num);

	if (perm_num == 2) {
		for (int i = 0; i < freq.size(); i++) {
			for (int j = 0; j < freq.size(); j++) {
				if (!(j == i)) {
					p.push_back(freq[i]);
					std::cout << freq[i] << " ";
					p.push_back(freq[j]);
					std::cout << freq[j] << " ";

					std::cout << '\n';
					total.push_back(p);
					p.clear();
				}
			}
		}
	}

	if (perm_num == 3) {
		for (int i = 0; i < freq.size(); i++) {
			for (int j = 0; j < freq.size(); j++) {
				if (!(j == i)) {
					for (int n = 0; n < freq.size(); n++) {
						if (!(n == i)) {
							if (!(n == j)) {
								p.push_back(freq[i]);
								std::cout << freq[i] << " ";
								p.push_back(freq[j]);
								std::cout << freq[j] << " ";
								p.push_back(freq[n]);
								std::cout << freq[n] << " ";
								std::cout << '\n';
								total.push_back(p);
								p.clear();
							}
						}
					}
				}
			}
		}
	}

	return total;
}//end permutations_produce()

//Summation Calculation:
void CalculationTerminal::summation(int frequencies_used)
{
	float sum = 0; //sum for adding frequencies together 
	std::string equation;
	int order_sum = 0;
	std::ostringstream output_format;

	int test = result_vec.size();

	for (int i = 0; i < coefficient_vec.size(); i++)
	{
		for (int j = 0; j < frequency_combos_vec.size(); j++)
		{
			for (int k = 0; k < frequencies_used; k++)
			{
				sum += frequency_combos_vec[j][k] * coefficient_vec[i][k];

				//formatting of output in terminal: 
				float temp_holder; //temporary variable for holding numbers
				temp_holder = coefficient_vec[i][k]; //store value into float
				if (temp_holder < 0)
				{
					temp_holder = abs(temp_holder);
					if (k == 0)
					{
						equation += "- ";
					}
				}
				else
				{
					if (k == 0)
					{
						equation += "  ";
					}
				}
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
					if (coefficient_vec[i][k + 1] < 0)
					{
						equation += " - ";
					}//end if 
					else
					{
						equation += " + ";
					}
				}//end if 

			}//end for 
			int flag = 0;
			for (int l = 0; l < rxfrequency_vec.size(); l++)
			{
				if (sum <= (rxfrequency_vec[l] + (range_frequencies )))
				{
					if (sum >= (rxfrequency_vec[l] - (range_frequencies)))
					{
						if (flag == 0)
						{
							result_vec.push_back(sum);
							result_vec_2d.push_back(std::vector<float>());
							result_vec_2d[step].push_back(rxfrequency_vec[l]);
							equation_vec.push_back(equation);
							flag++;
							step++;
						}//end if
						else
						{
							std::cout << " , " << rxfrequency_vec[l];
							result_vec_2d[step - 1].push_back(rxfrequency_vec[l]);
						}//end else
					}//end if 
				}//end if 
			}//end for 
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
	int incrementer_one = 0; //integer to access the right sub vector of coefficient combinations 
	coefficient_produce(order_num, 2);
	if (order_num == 3)
	{
		frequency_combos_vec_2 = permutations_produce(frequency_vec, 2);
	}
	frequency_combos_vec = frequency_combos_vec_2;
	summation(2);
	//if it is third order, calculate 3 frequency combos:
	if (order_num == 3)
	{
		//if more than two frequencies:
		if (frequency_vec.size() >= 3)
		{
			coefficient_produce(order_num, 3);
			frequency_combos_vec_3 = permutations_produce(frequency_vec, 3);
			frequency_combos_vec = frequency_combos_vec_3;
			summation(3);
		}
	}//end if
} //end void calculate

//Run Function:
void CalculationTerminal::run(int order, float range, std::vector<float> rxFreq, std::vector<float> txFreq)
{
	result_vec.clear();
	result_size_vec.clear();
	equation_vec.clear();
	frequency_vec.clear();
	rxfrequency_vec.clear();
	frequency_combos_vec.clear();
	frequency_combos_vec_2.clear();
	frequency_combos_vec_3.clear();
	coefficient_possibilities_vec.clear();
	coefficient_vec.clear();
	result_vec_2d.clear();
	progress_total += (order - 3 ) / 2;
	progress_total *= 2;
	emit this->progressMax(progress_total);
	double input; //variable to reuse for inputs
	
		if (order % 2 == 1)
		{
			range_frequencies = range;
			range_frequencies /= 1000;
			frequency_vec = txFreq;
			rxfrequency_vec = rxFreq;
			for (int order_increment = 2; order_increment <= order; order_increment++)
			{
				if (order_increment % 2 == 1)
				{
					calculate(order_increment);
					progress_count++;
					emit this->progressSignal(progress_count);
					qDebug() << "calculate progress: " << progress_count;
				}//end if
			}//end for
		}//end if
}//end void run()