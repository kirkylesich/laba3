#include <cstdio>
#include <iostream>

#include "lib.h"

#define CHAR_BUFF_SIZE 8
#define PRIME_SIZE 1000000
#define PRIME_BYTE_SIZE PRIME_SIZE / BYTE_SIZE + 1

void write_primes(unsigned char *primes, long size);
void fill_prime(unsigned char *arr, int size);
bool get_bit(unsigned char *bytes, int size, int bit_order);

using namespace std;

int main() {
	unsigned char prime[PRIME_BYTE_SIZE];
	fill_prime(prime, PRIME_BYTE_SIZE);

	clear_bit<unsigned char>(&prime[0], 0);
	clear_bit<unsigned char>(&prime[0], 1);

	for (int i = 2; i <= PRIME_SIZE; ++i) {
		if (get_bit(prime, PRIME_BYTE_SIZE, i)) {
			if (i * 1ll * i <= PRIME_SIZE) {
				for (int j = i * i; j <= PRIME_SIZE; j += i) {
					clear_bit(&prime[j / BYTE_SIZE],
						  j % BYTE_SIZE);
				};
			};
		};
	};

	write_primes(prime, PRIME_SIZE);

	return EXIT_SUCCESS;
}

void write_primes(unsigned char *primes, long size) {
	FILE *fp;
	char buf[CHAR_BUFF_SIZE];
	fp = fopen("primes.out", "w");
	int k = 1;
	for (long i = 0; i < size; i++) {
		if (get_bit(primes, PRIME_BYTE_SIZE, i)) {
			sprintf(buf, "%ld ", i);
			if(i/100 == k){
				sprintf(buf, "\n");
				k++;
			}
			fprintf(fp, buf);
		}
	}

	fclose(fp);
}

bool get_bit(unsigned char *bytes, int size, int bit_order) {
	int index = bit_order / BYTE_SIZE;
	return show_bit<unsigned char>(&(bytes[index]), bit_order % BYTE_SIZE);
}

void fill_prime(unsigned char *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 255;
	}
}

