#include <iostream>
#include "lib.h"

using namespace std;

int main(){
	double double_var = 32.324;	
	float float_var = 12.12;	
	long double long_double_var = 32.324;	

	print_var_dump<float>(&float_var);
	printf("\n");
	print_var_dump<double>(&double_var);
	printf("\n");
	print_var_dump<long double>(&long_double_var);
	
	return EXIT_SUCCESS;
}
