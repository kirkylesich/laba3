#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>

#include "lib.h"

#define PRIME_SIZE 1000000
#define PRIME_BYTE_SIZE PRIME_SIZE / BYTE_SIZE + 1

void fill_prime(unsigned char *arr, int size);
bool get_bit(unsigned char *bytes, int size, char bit_order);
using namespace std;

int main() {
	unsigned char prime[PRIME_BYTE_SIZE];
	fill_prime(prime, PRIME_BYTE_SIZE);
	clear_bit<unsigned char>(&prime[0], 0);
	clear_bit<unsigned char>(&prime[0], 1);

	for (int i = 2; i <= PRIME_SIZE; ++i) {
		if (get_bit(prime, PRIME_BYTE_SIZE, i)) {
			if (i * 1ll * i <= PRIME_SIZE)
				for (int j = i * i; j <= PRIME_SIZE; j += i){
					clear_bit(&prime[j / BYTE_SIZE],
						  j % BYTE_SIZE);
				};
		};
	};

	for (int i = 0; i < 200; i++) {
		if (get_bit(prime, PRIME_BYTE_SIZE, i)) {
			printf("%d\n", i);
		}
	}

	return EXIT_SUCCESS;
}

bool get_bit(unsigned char *bytes, int size, char bit_order) {
	int index = bit_order / BYTE_SIZE;
	return show_bit<unsigned char>(&(bytes[index]), bit_order % BYTE_SIZE);
}

void fill_prime(unsigned char *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 255;
	}
}
