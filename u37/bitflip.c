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

int main (int argc, char* argv[]){
	long value;
	int index;
	long newNumb;
	if (argc == 3){
		sscanf(argv[1], "%ld", &value);
		sscanf(argv[2], "%d", &index);

		printf("value:             ");
		printValue(value);

		newNumb = value ^ (1 << index);
		printf("bitflipped value:  ");
		printValue(newNumb);
		
		return EXIT_SUCCESS;
	}else{
		printf("bitflip takes two arguments: ./bitflip value index");
		return EXIT_FAILURE;
	}
}
