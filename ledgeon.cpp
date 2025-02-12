#include <iostream>

int main() {
	/*The purpose of this program is to allow the user to quickly calculate the charity charges of a hospital 
	and compare patient volumes between two years*/
	
	// create variables for all inputs needed by the user
	int first_year{};
	int first_year_num_of_patients{};
	int second_year{};
	int second_year_num_of_patients{};
	const double CONST_region_average{ 1375.61 };

	//ask user for the input and ensure there response is stored within the correct variable
	std::cout << "Enter the first year: ";
	std::cin >> first_year;

	std::cout << "Enter the number of patients we saw that year: ";
	std::cin >> first_year_num_of_patients;

	std::cout << "Enter the second year: ";
	std::cin >> second_year;

	std::cout << "Enter the number of patients we saw that year: ";
	std::cin >> second_year_num_of_patients;
	

	// create variables that will store the calculations of inputs
	int patient_diff{ second_year_num_of_patients - first_year_num_of_patients };
	double patient_increase{ static_cast<double>(patient_diff) / (first_year_num_of_patients) };
	double change_percentage{ patient_increase * 100 };
	double charity_charges_year_one{ first_year_num_of_patients * CONST_region_average };
	double charity_charges_year_two{ second_year_num_of_patients * CONST_region_average };


	// create output that provide final metrics for the user
	std::cout << "In year " << first_year << ", our hospital issued " << charity_charges_year_one 
		<< " dollars of charity charges.\n";
	std::cout << "In year " << second_year << ", our hospital issued " << charity_charges_year_two 
		<< " dollars of charity charges.\n";
	std::cout << "Between " << first_year << " and " << second_year << ", there was a " 
		<< change_percentage << "% increase in patients seen at our hospital.";
	std::cout << std::endl;
	return 0;
}

