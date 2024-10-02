#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char** argv) {
	int length;
	int count; 
	char* characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%-_";
	int characterSetLen = strlen(characters) / sizeof(char);

	if (argc == 1) {
		printf("Error: %s takes 2 arguments\n", argv[0]);
		printf("Usage: %s <length> <count>\n", argv[0]);
		return 1;
	} else if (argc == 2) {
		length = atoi(argv[1]);
		if (length == 0) {
			printf("Error: unable to understand argument 1\n");
			return 1;
		}
		count = 1;
	} else {
		length = atoi(argv[1]);
		if (length == 0) {
			printf("Error: unable to understand argument 1\n");
			return 1;
		}

		count = atoi(argv[2]);
		if (count == 0) {
			printf("Error: unable to understand argument 2\n");
			return 1;
		}
	}

	printf("Generating %i password(s) of length %i\n", count, length);

	srand(time(NULL));
	int r = 0;
	char password[length + 1]; 
	password[length] = '\0';

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < length; j++) {
			r = rand() % characterSetLen;
			password[j] = characters[r];
		}
		printf("[%i] %s \n", i, password);
	}	

	return 0;
}
