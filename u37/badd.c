#include <stdio.h>
#include <stdlib.h>

void printValue(int q){
	int qN;
	for (int c=63; c>=0; c--){
		qN = q >> c;
		if (qN & 1) {
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
}

long rippleAdder(long q_1, long q_2){
	int carry = 0;
	int q_1n;
	int q_2n;
	long newNumb = 0;

	for (int c=0; c<=63; c++){
		q_1n = (q_1 >> c) & 1;
		q_2n = (q_2 >> c) & 1;

		switch (q_1n + q_2n + carry)
		{
			case 3:
				//set c'th index and carry to 1
				newNumb = newNumb ^ (1 << c);
				carry = 1;
				break;

			case 2:
				//set c'th index to 0 and carry to 1
				carry = 1;
				break;

			case 1:
				//set c'th index to 1 and carry to 0
				newNumb = newNumb ^ (1 << c);
				carry = 0;
				break;

			default:
				//set c'th index to 0 and carry to 0
				carry = 0;
				break;

		} if ((c == 63) && carry == 1){
			printf("\n Overflowbit: %d", carry);
		}
	}
	return newNumb;
}

int main (int argc, char* argv[]){
	long a;
	long b;

	if (argc == 3){
		sscanf(argv[1], "%ld", &a);
		sscanf(argv[2], "%ld", &b);

		printf("The numbers are: %ld, %ld \n", a, b);
		printf("The rippleadded number is: %ld \n", rippleAdder(a, b));
		return EXIT_SUCCESS;
	}else {
		return EXIT_FAILURE;
	}
}