#include <iostream>
#define BYTE_SIZE 8

template <typename T>
void print_var_dump(T *number);
template <typename T>
void print_binary_code(T number);
template <typename T>
bool show_bit(T *number, char bit_order);
void binary_print(short *number);

template <typename T>
int set_bit(short *number, short bit_order);
template <typename T>
int clear_bit(short *number, short bit_order);
template <typename T>
int toggle_bit(short *number, short bit_order);

using namespace std;

template <typename T>
int set_bit(T *number, short bit_order) {
	if (bit_order < 0 || bit_order > 16) {
		return EXIT_FAILURE;
	};

	*number |= 1 << ((sizeof(T) * BYTE_SIZE - 1) - bit_order);
	return EXIT_SUCCESS;
}

template <typename T>
int clear_bit(T *number, short bit_order) {
	if (bit_order < 0 || bit_order > 16) {
		return EXIT_FAILURE;
	};

	*number &= ~(1 << ((sizeof(T) * BYTE_SIZE - 1) - bit_order));
	return EXIT_SUCCESS;
}

template <typename T>
int toggle_bit(T *number, short bit_order) {
	if (bit_order < 0 || bit_order > 16) {
		return EXIT_FAILURE;
	};
	*number ^= 1 << ((sizeof(T) * BYTE_SIZE - 1) - bit_order);
	return EXIT_SUCCESS;
}

template <typename T>
bool show_bit(T *number, char bit_order) {
	return (*number >> ((sizeof(T) * BYTE_SIZE - 1) - bit_order)) & 1;
}

template <typename T>
void print_binary_code(T number) {
	for (char i = 0; i < (sizeof(T) * BYTE_SIZE); i++) {
		printf("%d", show_bit<T>(&number, i));
	};
	printf("\n");
}

template <typename T>
void print_var_dump(T *number) {
	char *pointer = (char *)number;

	for (char i = 0; i < sizeof(T); i++) {
		printf("%p: ", pointer);
		print_binary_code<char>(*pointer++);
	}
}
