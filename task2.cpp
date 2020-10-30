#include <iostream>

#include "lib.h"

template <typename T>
void print_binary_info(T *number);

template <typename T>
T get_reverse_code(T number);

template <typename T>
T get_additional_code(T number);

using namespace std;

int main() {
	char byte_1 = 51;
	short byte_2 = 100;
	int byte_4 = -10230;
	long long byte_8 = 200;

	print_binary_info<char>(&byte_1);
	print_binary_info<short>(&byte_2);
	print_binary_info<int>(&byte_4);
	print_binary_info<long long>(&byte_8);
}

template <typename T>
void print_binary_info(T *number) {
	printf("Primary code: ");
	print_binary_code<T>(*number);
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
	return ~number;
}

template <typename T>
T get_additional_code(T number) {
	return get_reverse_code<T>(number) + 1;
}
