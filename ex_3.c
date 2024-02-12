#include <stdio.h>

int getAction();
int runProgram();
int firstAction();
int secondAction();
void fillArray(int array[], int currentIdx, int size);
void printArray(int array[], int arrayLength);
void mergePrint(int a1[], int a2[], int start1, int start2, int end1, int end2);
int paliDistance(char str[], int start, int end);

int main() {
	runProgram();
	return 0;
}

int getAction() {
	int action;
	printf("What is your desired task boss?\n");
	printf("1. merge order incomes\n");
	printf("2. find distance from symmetry\n");
	printf("3. check if the gangs are balanced\n");
	printf("4. find optimal time for escaping\n");
	printf("5. check workers efficiency\n");
	printf("6. exit\n");
	scanf("%d", &action);
	if (action < 1 || action > 6) {
		printf("Sorry Tony, I don't understand...\n");
		return getAction();
	}
	return action;
}

int runProgram() {
	int action = getAction();
	
	if (action == 1) {
		firstAction();
		return 0 + runProgram();
	}
	if (action == 2) {
		secondAction();
		return 0 + runProgram();
	}
	else if (action == 6) return 1;
	else return 0;
}

int firstAction() {
	int firstArrayLength, secondArrayLength;
	int firstArray[30], secondArray[30];

	printf("Enter the length of the first worker array:\n");
	scanf("%d", &firstArrayLength);
	printf("Now enter the first array's elements:\n");
	fillArray(firstArray, 0, firstArrayLength);
	
	printf("Enter the length of the second worker array:\n");
	scanf("%d", &secondArrayLength);
	printf("Now enter the second array's elements:\n");
	fillArray(secondArray, 0, secondArrayLength);

	printf("start ");
	mergePrint(
		firstArray,
		secondArray,
		0,
		0,
		firstArrayLength - 1,
		secondArrayLength - 1
	);
	printf("end\n");
	return 0;
}
int secondAction() {
	int stringLength;
	char string[31]; // 30 chars + \0
	
	printf("Enter the length of the string:\n");
	scanf("%d", &stringLength);
	printf("Now enter the string:\n");
	scanf("%30s", string);
	printf("The palindrome distance is %d.\n", paliDistance(string, 0, stringLength - 1));
	return 0;
}
void fillArray(int array[], int currentIdx, int size) {
	if (currentIdx >= size) return;
	scanf("%d", &array[currentIdx]);
	fillArray(array, currentIdx+1, size);
}
void printArray(int array[], int arrayLength) {
	printf("[");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d", array[i]);
		if (i < arrayLength - 1) printf(",");
	}
	printf("]\n");
}
void mergePrint(int a1[], int a2[], int start1, int start2, int end1, int end2) {
	int isValidIndex1 = start1 <= end1;
	int isValidIndex2 = start2 <= end2;
	if (!isValidIndex1 && !isValidIndex2) return;
	if (!isValidIndex1 && isValidIndex2) {
		printf("%d ", a2[start2]);
		return mergePrint(a1, a2, start1, start2 + 1, end1, end2);
	}
	if (isValidIndex1 && !isValidIndex2) {
		printf("%d ", a1[start1]);
		return mergePrint(a1, a2, start1 + 1, start2, end1, end2);
	}
	int is1Smaller = a1[start1] < a2[start2];
	printf("%d ", is1Smaller ? a1[start1] : a2[start2]);
	mergePrint(a1, a2, start1 + is1Smaller, start2 + !is1Smaller, end1, end2);
}
int paliDistance(char str[], int start, int end) {
	if (end <= start) return 0;
	return (str[start] != str[end]) + paliDistance(str, start + 1, end - 1);
}
