#include <stdio.h>


// OPGAVE BAGLENS
/*
void swap(int* x, int* y);

int main(void) {

	char s[] = "rambuk";

	printf("%s\n", s);
	for (int i = 0; i < strlen(s) / 2; i++)
	{
		printf("%s\n", s);

		swap(&s[i], &s[strlen(s)-1-i]);
	}
	printf("%s\n", s);

	return 0;
}


void swap(char* x, char* y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
*/



//OPGAVE SORTERING

/*
void swap(int* x, int* y);

int main(void) {

	int tosort[] = { 2,1,7,3,8,4,3,1,9,7 };

	int arraysize = sizeof(tosort) / sizeof(tosort[0]);

	//Print before result
	for (int i = 0; i < arraysize; i++) {
		printf("%d,", tosort[i]);
	}

	//new line
	printf("\n");

	int j = 1;
	while (j) {
		j = 0;

		for (int i = 0; i < arraysize-1; i++) {
			//If current number is bigger than the next one
			if (tosort[i] > tosort[i + 1]) {
				swap(&tosort[i], &tosort[i + 1]);
				//Go through loop again to make sure everything is in correct order
				j = 1;
			}
			
		}
	}

	//Print results
	for (int i = 0; i < arraysize; i++) {
		printf("%d,", tosort[i]);
	}
	return 0;
}

void swap(char* x, char* y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
*/



// OPGAVE  TÆL ORD

/*
int main(void) {

	char s[] = "Jens er sej";
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅabcdefghijklmnopqrstuvwxyzæøå";
	int count = 0;
	int isword = 0;


	for (int i = 0; i < strlen(s); i++) {
		//Check if the current char matches with the available words
		if (s[i] == 32) {
			isword = 0;
		}
		else {
			for (int j = 0; j < strlen(letters); j++) {
				if (s[i] == letters[j]) {
					//If it was not a word before, then add to counter
					if (isword == 0) {
						count++;
					}
					isword = 1;
					break;
				}
			}

		}

	}

	printf("There is %d words", count);

	return 0;
}
*/



//OPGAVE SORTER ORD

void swap(char** words, int index1, int index2) {
	char* temp = words[index1];
	words[index1] = words[index2];
	words[index2] = temp;
}


int compareWords(char* word1, char* word2) {
	char letters[] = "abcdefghijklmnopqrstuvwxyzæøå";
	int length = strlen(word1);

	//Change length to the smallest
	if (length > strlen(word2)) {
		length = strlen(word2);
	}
	//Loop through letters in each word
	for (int i = 0; i < length; i++) {
		int word1row = 0;
		int word2row = 0;

		//Find the row the letter is in
		for (int h = 0; h < strlen(letters); h++) {
			if (word1[i] == letters[h]) {
				word1row = h;
			}
			if (word2[i] == letters[h]) {
				word2row = h;
			}
		}

		if (word1row > word2row) {
			return 1;
		}
		else if (word1row < word2row) {
			return 0;
		}
	}
	return 0;

}

int main() {
	char* words[] = { "jens", "jeg", "jonatan", "alberte" };

	for (int i = 0; i < strlen(words) - 2; i++) {
		printf("%s \n", words[i]);
	}

	printf("\nAFTER\n\n");

	int arraychanged = 1;
	//Keep looping until no changes has been made to the words array
	while (arraychanged) {
		arraychanged = 0;

		for (int i = 0; i < strlen(words)-3; i++) {
			//Should swap
			if (compareWords(words[i], words[i + 1])) {
				arraychanged = 1;
				//Swap the two words in the words array
				swap(&words, i, i + 1);
			}
		}
	}

	//Print words
	for (int i = 0; i < strlen(words) - 2; i++) {
		printf("%s \n", words[i]);
	}
}
