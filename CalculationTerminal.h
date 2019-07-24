#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>

class CalculationTerminal
{
private:

	//functions:
	void coefficient_produce(int order_num, int frequencies_used);
	int factorial(int n);
	std::vector<std::vector<float>> permutations_produce(std::vector<float> inputFreq, int perm_num);
	void summation(int frequencies_used);
	void calculate(int order_num);

	//vectors::
	std::vector<std::vector<float> > frequency_combos_vec;
	std::vector<std::vector<float> > frequency_combos_vec_2;
	std::vector<std::vector<float> > frequency_combos_vec_3;
	std::vector<std::vector<float> >coefficient_vec;
	std::vector<float> coefficient_possibilities_vec;
	std::vector<float> frequency_vec; //vector that will hold all frequencies
	std::vector<float> rxfrequency_vec;
	std::vector<int> result_size_vec;

	//variables:
	int order = 0, range_frequencies, step = 0, n = 0, incrementer_one = 0;
	

public:

	//functions:
	CalculationTerminal(); //constructor
	~CalculationTerminal(); //destructor
	void run(); //run function

	//vectors:
	std::vector<std::string> equation_vec;
	std::vector<float> result_vec; //vector that will hold all results
	std::vector<std::vector<float> > result_vec_2d;
};