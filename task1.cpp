#include <iostream>
#include "lib.h"

using namespace std;

int main() {
	short number = 0;

	printf("Enter number:\n");
	scanf("%hd", &number);

	char choice;
	int arg = 0;
	while (true) {
		printf(">>> ");
		scanf("%c %d", &choice, &arg);
		switch (choice) {
			case 's':
				if (set_bit(&number, arg) == EXIT_FAILURE) {
					printf("ERROR: bit order overflowed\n");
				} else {
					printf("Success\n");
				};
				break;
			case 'c':
				if (clear_bit(&number, arg) == EXIT_FAILURE) {
					printf("ERROR: bit order overflowed\n");
				} else {
					printf("Success\n");
				};
				break;
			case 't':
				if (toggle_bit(&number, arg) == EXIT_FAILURE) {
					printf("ERROR: bit order overflowed\n");
				} else {
					printf("Success\n");
				};
				break;
			case 'p':
				switch (arg) {
					case 2:
						print_binary_code<short>(number);
						break;
					case 10:
						printf("%d\n", number);
						break;
				};
				break;
			case 'q':
				return EXIT_SUCCESS;
		};
	}
	return EXIT_SUCCESS;
}

