#include <bitset>
#include <iostream>

#include "lib.h"

template <typename T>
void print_binary_info(T *number);

template <typename T>
T get_reverse_code(T number);

template <typename T>
T get_additional_code(T number);

template <typename T>
void print_primary_code(T number);

using namespace std;

int main() {
	char byte_1 = -100;
	short byte_2 = 100;
	int byte_4 = -200;
	long long byte_8 = -12;

	print_binary_info<char>(&byte_1);
	print_binary_info<short>(&byte_2);
	print_binary_info<int>(&byte_4);
	print_binary_info<long long>(&byte_8);
}

template <typename T>
void print_binary_info(T *number) {
	printf("Number: %d Type size: %lu\n", *number, sizeof(T));
	printf("Primary code: ");
	print_primary_code<T>(*number);
	printf("Reverse code: ");
	print_binary_code<T>(get_reverse_code<T>(*number));
	printf("Additional code: ");
	print_binary_code<T>(get_additional_code<T>(*number));
	printf("Mem dump: \n");
	print_var_dump<T>(number);
	printf("\n");
}

template <typename T>
T get_reverse_code(T number) {
	if (number < 0) {
		return ~(number * (-1));
	}
	return number;
}

template <typename T>
T get_additional_code(T number) {
	return (number < 0) ? get_reverse_code<T>(number) + 1 : number;
}

template <typename T>
void print_primary_code(T number) {
	if (number > 0) {
		print_binary_code<T>(number);
	} else {
		T num = number * (-1);
		set_bit(&num, 0);
		print_binary_code<T>(num);
	}
}
