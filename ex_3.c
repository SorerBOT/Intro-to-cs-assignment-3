#include <stdio.h>

int getAction();
int runProgram();
int firstAction();
int secondAction();
int thirdAction();
int fourthAction();
int fifthAction();
int sixthAction();
void fillArray(int array[], int currentIdx, int size);
void fillTwoArrays(int array1[], int array2[], int currentIdx, int size);
void printArray(int array[], int arrayLength);
void mergePrint(int a1[], int a2[], int start1, int start2, int end1, int end2);
int paliDistance(char str[], int start, int end);
int checkBalance(char* str, int n);
int checkBalanceHelper(char str[], int length, int idx);
int escapingTime(int n);
int heistOpt(int maxW, int optVal, int w[], int v[], int start, int len);

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
		return runProgram();
	}
	if (action == 2) {
		secondAction();
		return runProgram();
	}
	if (action == 3) {
		thirdAction();
		return runProgram();
	}
	if (action == 4) {
		fourthAction();
		return runProgram();
	}
	if (action == 5) {
		fifthAction();
		return runProgram();
	}
	if (action == 6) {
		sixthAction();
		return 1;
	}
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
int thirdAction() {
	int gCount; // the amount of gangsters
	char string[31]; // 30 chars + \0
	
	printf("Enter the number of gang members:\n");
	scanf("%d", &gCount);
	printf("Enter the gang associations:\n");
	scanf("%30s", string);
	checkBalance(string, gCount);

	return 0;
}
int fourthAction() {
	int currentRoom;

	printf("What room are you in boss?\n");
	scanf("%d", &currentRoom);
	printf("Your escaping time is: %d\n", escapingTime(currentRoom));

	return 0;
}
int fifthAction() {
	int numOfObjects, maxWeight;
	int values[30], weights[30];

	printf("Enter the number of objects and the maximum weight:\n");
	scanf("%d", &numOfObjects);
	scanf("%d", &maxWeight);
	printf("Now enter the objects' values and weights:\n");

	fillTwoArrays(values, weights, 0, numOfObjects);
	printf("The optimal heist income value is %d\n", heistOpt(maxWeight, 0, weights, values, 0, numOfObjects));
	return 0;
}
int sixthAction() {
	printf("goodbye boss!\n");
	return 0;
}
void fillArray(int array[], int currentIdx, int size) {
	if (currentIdx >= size) return;
	scanf("%d", &array[currentIdx]);
	fillArray(array, currentIdx+1, size);
}
void fillTwoArrays(int array1[], int array2[], int currentIdx, int size) {
	if (currentIdx >= size) return;
	scanf("%d", &array1[currentIdx]);
	scanf("%d", &array2[currentIdx]);
	fillTwoArrays(array1, array2, currentIdx+1, size);
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
int checkBalance(char* str, int n) {
	printf(
		!checkBalanceHelper(str, n, 0)
			? "The army is balanced.\n"
			: "The army is not balanced.\n"
	);

	return 0;
}
int checkBalanceHelper(char str[], int length, int idx) {
	if (idx >= length) return 0;
	// if its a, increase by 1, if its b, decrease by 1. If the armies are balanced--we should end up with 0
	return (str[idx] == 'a' ? 1 : -1) + checkBalanceHelper(str, length, idx + 1);
}
int escapingTime(int n) {
	if (n == 1) return 0;
	int canDiv2 = !(n % 2);
	int canDiv3 = !(n % 3);
	
	int leastSteps = 1 + escapingTime(n - 1);
	if (canDiv2) {
		int div2Steps = 1 + escapingTime(n / 2);
		if (div2Steps < leastSteps) leastSteps = div2Steps;
	}
	if (canDiv3) {
		int div3Steps = 1 + escapingTime(n / 3);
		if (div3Steps < leastSteps) leastSteps = div3Steps;
	}

	return leastSteps;
}
int heistOpt(int maxW, int optVal, int w[], int v[], int start, int len) {
	int withCurrent, withoutCurrent;
	if (start >= len) return optVal;
	if (maxW < w[start]) return heistOpt(maxW, optVal, w, v, start + 1, len);
	
	withCurrent = heistOpt(maxW - w[start], optVal + v[start], w, v, start + 1, len);
	withoutCurrent = heistOpt(maxW, optVal, w, v, start + 1, len);

	return (withCurrent > withoutCurrent) ? withCurrent : withoutCurrent;
}
