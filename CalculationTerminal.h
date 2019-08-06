#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <QObject>
#include <QDebug>

/**
* @brief Calculation Code for Intermodulation Products
*
* This class contains all code relating to the calcualtion of intermodulation products for up nth order with m frequencies
*
* @author Larry Staecey & Raymond Bedry, RTP, E-Division, RCMP
*/
class CalculationTerminal : public QObject
{
	Q_OBJECT

signals:
	void progressSignal(int progress);
	void progressMax(int max);

private:

	//functions:
	void coefficient_produce(int order_num, int frequencies_used);///funtion that produces the coefficient combinations thats absolute value adds up to the current order
	int factorial(int n); ///function that calculates the factorial of the number passed to it
	/** @brief Function for producing all possible permutations of an array of numbers passed to it.
	*    
	*	Will produce all possiblie permutations of an array of numbers based off of the variables inputFreq and perm_num which are passed. perm_num will determine the size of the permutation
	*	while inputFreq will be a vector of frequencies passed that will make up the permutations. 
	*
	*	@param inputFreq A vector of input frequencies from the user that will be used in the calculation and production of all possible permutations
	*	@param perm_num An integer passed that will determine the size of the permutation. In this application, almost always 2 or 3. 
	*
	*	@return total A 2d vector of all possible permutations dependent on the paramaters passed to the function.
	*/
	std::vector<std::vector<float>> permutations_produce(std::vector<float> inputFreq, int perm_num); 
	/** @brief Function for calculating products and determining hits
	*
	*	Will step through all possible permutation and coefficient combinations and determine if they are within the range specified by the user for a hit.
	*
	*	@param frequencies_used An integer that will tell the summation how many frequencies are being used in the calculation and limit the iterations of the calculations.
	*
	*	@return nothing to return.
	*/
	void summation(int frequencies_used);
	/** @brief Function for that calls other functions to calculate hits properly dependent on the current order.
	*
	*	Will step through the other functions in this class and call the correct functions with the right paramaters dependent on what order and frequencies are being used. 
	*
	*	@param order_num An integer that will be passed that is representative of the current order number and will subsequently determine what other variables get passed to other functions 
	*
	*	@return nothing to return
	*/
	void calculate(int order_num);

	//vectors::
	std::vector<std::vector<float> > frequency_combos_vec; ///2D vector that holds all possible current frequency combinations.
	std::vector<std::vector<float> > frequency_combos_vec_2; ///2D vector that will hold all possible 2-frequency combinations. Stored as a temp to save on processing power so the function that generates this vector does not continually have to be recalled. 
	std::vector<std::vector<float> > frequency_combos_vec_3; ///2D vector that will hold all possible 3-frequency combinations. Stored as a temp to save on processing power so the function that generates this vector does not continually have to be recalled.
	std::vector<std::vector<float> >coefficient_vec; ///2D vector that will hold all possible coefficients combinations depending on the order for hits requested by the user.
	std::vector<float> coefficient_possibilities_vec; ///A vecotr that will hold all possible coefficients depending on the order for hits requested by the user. 
	std::vector<float> frequency_vec; ///Vector that will hold all transmitter frequencies input by user. 
	std::vector<float> rxfrequency_vec; ///Vector that will hold all receiver frequencies input by user. 


	//variables:
	int order = 0; ///Integer used to keep track of the current order.
	int step = 0; ///Integer used to keep track of stepping through for-loops.
	int n = 0;///Integer used to keep track of size of result vector.
	int incrementer_one = 0;///Integer used to step through frequencies in generating the result vector.
	float range_frequencies = 0; ///A float value input by the user that will determine the range that will necessitate a hit on the receiver frequencies.

public:

	//functions:
	/** @brief Constructor
	*	@return nothing to return
	*/
	CalculationTerminal(QObject* parent = Q_NULLPTR);
	/** @brief Destructor
	*	@return nothing to return
	*/
	~CalculationTerminal(); 
	/** @brief Function for that will call all other functions to calculate hits properly and take in all variables necessary for all other functions.
	*
	*	Will properly assign all variables from the GUI classes and assign them to their corresponding vectors and variables in this class. 

	*	@param order An integer that will be passed that is representative of the total order number desired to be calculated.
	*	@param range A float that will take in the range to be used for determining hits.
	*	@param rxFreq A vector of floats that will be representative of the users inputted receiver frequencies. 
	*	@param txFreq A vector of floats that will be representative of the users inputted transmitter frequencies. 
	*
	*	@return nothing to return
	*/
	void run(int order, float range, std::vector<float> rxFreq, std::vector<float> txFreq); 

	//variables:
	int progress_total = 2; ///Integer that will store the total number of calculations needed in order to display a progress bar
	int progress_count = 1; ///Integer tht will count through the calculations to display current status in progress bar. 

	//vectors:
	std::vector<std::string> equation_vec; ///2D vector that will hold the equation in a string that was representative of a hit.
	std::vector<float> result_vec; ///A vector that will hold the value of the hit.
	std::vector<std::vector<float> > result_vec_2d; ///A 2D vector that will hold the resulting receiver frequencies that were withing range of a hit.
	std::vector<int> result_size_vec; ///A vector that will hold the number of results per order as each elemnt to be able to properly iterate through when displaying output. 
};