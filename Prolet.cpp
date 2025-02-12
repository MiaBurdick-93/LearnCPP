#include <iostream>

int get_int();
double calculate_per_capita_gdp_estimate(int quarters_from_epoch);
std::string format_money(double money);
std::string quarter_to_ordinal(int quarter);

/*The purpose of this function is to calculate the projected
* contribution to GDP per working-age person for the year and quarter
* of the user's choice
*/
int main() {
	//declare and define necessary constants
	const int CONST_quarters_per_year{ 4 };
	const int CONST_epoch_year{ 1977 };
	const int CONST_epoch_quarter{ 1 }; 

	//call function to get user input
	std::cout << "Please enter the year for the calculation: ";
	int user_year{ get_int() };
	std::cout << "Please enter the quarter for the calculation: ";
	int user_quarter{ get_int() };

	/*intermediate calculation to create input 
	* for the calculate_per_capita_gdp_estimate
	*/
	int epoch_in_quarters{ CONST_quarters_per_year * CONST_epoch_year };
	int user_year_conversion{ user_year * CONST_quarters_per_year };
	int user_quarter_conversion{ user_quarter - CONST_epoch_quarter };
	int chosen_date{ user_year_conversion + user_quarter_conversion };
	int quarters_between{ chosen_date - epoch_in_quarters };

	//call calculation function to get GDP estimate
	double gdp_estimate = calculate_per_capita_gdp_estimate(quarters_between); 

	//call quarter_to_ordinal function and format money
	std::string ordinal_output{ quarter_to_ordinal(user_quarter) };
	std::string formatted_money_output{ format_money(gdp_estimate) };


	//output to the user for the final calculation
	std::cout << "In the " << ordinal_output << " quarter of " << user_year 
		<< ", the projected contribution to GDP per working-age person is $" 
		<< formatted_money_output << ".\n";
	
	return 0;
}