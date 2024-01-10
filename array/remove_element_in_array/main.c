#include <stdio.h>

void remove_element(int *list, int target, unsigned int length) {
	unsigned int fast = 0;
	unsigned int slow = 0;
	for(fast = 0; fast < length; fast++) {
		if(list[fast] != target) {
			list[slow] = list[fast];
			slow++;
		} 

	}
}

int main(void) {
	int list[] = {0, 10, 20, 5, 7, 9};
	unsigned int length = sizeof(list) / sizeof(int);
	int target = 5;
	remove_element(list, target, length);
	int i;
	for(i = 0; i < length - 1; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}
