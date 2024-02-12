#include <stdio.h>

int getAction();

int main() {

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
	printf("\n");
	scanf("%d", &action);
	if (action < 1 || action > 6) {
		printf("Sorry Tony, I don't understand...\n");
		return getAction();
	}
	return action;
}
