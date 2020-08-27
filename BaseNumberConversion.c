#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int *arr, size_t size, int spacing) {

	char *letters[6];

        letters[0] = "A";
	letters[1] = "B";
	letters[2] = "C";
	letters[3] = "D";				
	letters[4] = "E";
	letters[5] = "F";

	for (int i = 0; i < size; i++) {
		if (i % spacing == 0 && i != 0) {
			printf(" ");
		}
	
		// Hexa-decimal
		if (*(arr + i) > 9) {
			for (int j = 0; j < 6; j++) {
				if (*(arr + i) - 10 == j) {
					printf("%s", *(letters + j));
				}
			}
		} else {
			printf("%d", *(arr + i));
		}
	}
}

int * reverseArray(int *arr, size_t size) {
	int *res = malloc(32 * sizeof(int));
	
	int j = 0;
	for (int i = size - 1; i >= 0; i--) {
		*(res + j) = *(arr + i);
		j++;
	}
	return res;
}

void getAsBinary(int num) {
	int *binaryArr = malloc(32 * sizeof(num));

	int i = 0;
	size_t size = 0;

	while (num > 0) {
		int remainder = num % 2;
		num /= 2;
		*(binaryArr + i) = remainder;
		
		i++;
		size++;
	}

	int *newArr = reverseArray(binaryArr, size);
	printArr(newArr, size, 4);

	free(binaryArr);
	free(newArr);
}

void convertToHexaDecimal(int num) {
	int *hexadecimalArr = malloc(32 * sizeof(num));

	size_t size = 0;
	int i = 0;

	while (num > 0) {
		int remainder = num % 16;
		num /= 16;
	
		*(hexadecimalArr + i) = remainder;

		size++;
		i++;
	}
	
	int *newArr = reverseArray(hexadecimalArr, size);
	printArr(newArr, size, 2);
}

int convertToAnyBase(int num, int base) {

	if (base == 16) {
		convertToHexaDecimal(num);
		return 1;
	} else if (base == 2) {
		getAsBinary(num);
		return 1;
	} else if (base <= 1) {
		printf("Please select a base higher than 1\n");
		return 0;
	}


	int *anyBase = malloc (64 * sizeof(num));

	size_t size = 0;
	int i = 0;

	while (num > 0) {

		int remainder = num % base;
		num /= base;

		*(anyBase + i) = remainder;

		i++;
		size++;
	}

	int *newArr = reverseArray(anyBase, size);
	printArr(newArr, size, 4);
	return 0;
}
	
void showMenu() {
	printf("\n-----MENU-----\n");
	printf("0. Exit\n");
	printf("1. Decimal -> Binary\n");
	printf("2. Decimal -> Hexadecimal\n");
	printf("3. Decimal -> Any base number\n");
	printf("Enter an option\n");
	printf("--------------\n");

	int userInput = -1;
	scanf("%d", &userInput);

	switch(userInput) {
		case 0:
			printf("Exiting...\n");
			exit(0);
			break;
		case 1:
			printf("Enter your number (No floating-points): ");
			int num = -1;
			scanf("%d", &num);
			
			if (num == 0) {
				printf("0 is the binary of 0\n");
				showMenu();
			}
			if (num < 0) {
				num = abs(num);
				printf("-");
			}

			getAsBinary(num);
			printf(" is the binary of %d\n", num);
			showMenu();
			break;
		case 2:
			printf("Enter your number (No floating-points): ");
			int num1 = -1;
			scanf("%d", &num1);

			if (num1 == 0) {
				printf("0 is the Hexadecimal of 0\n");
				showMenu();
			}

			if (num1 < 0) {
				num1 = abs(num1);
				printf("-");
			}

			convertToHexaDecimal(num1);
			printf(" is the Hexa-Decimal of %d\n", num1);
			showMenu();
			break;
		case 3: 
			printf("Enter your number (No floating-point): ");

			int num2 = -1;
			scanf("%d", &num2);

			printf("Enter the base that you want to convert to: ");
			int base = -1;
			scanf("%d", &base);


			if (convertToAnyBase(num2, base) != 0) {
			
				if (num2 < 0) {
					printf("-");
				}
				printf(" is base %d of %d\n", base, num2);
			}
			showMenu();
			break;
		default:
			printf("Not a valid choice\n");
			showMenu();
			break;
	}

}


int main() {	
	showMenu();
}
