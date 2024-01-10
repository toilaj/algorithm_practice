#include <stdio.h>

int get_min_length_window(int *list, unsigned int length, int target) {
	int start = 0;
	int end = 0;
	int result = length;
	int sum = 0;
	for(end = 0; end < length; end++) {
		sum += list[end];
		while(sum > target) {
			result =  (end - start + 1) > result ? result : (end - start + 1);
			sum -= list[start];
			start++;
		}
	}
	return result;
}

int main(void) {
	int list[] = {1, 1, 2, 2, 3, 5, 7, 0, 10};
	unsigned int length = sizeof(list) / sizeof(int);
	int target = 9;
	unsigned int result = get_min_length_window(list, length, target);
	printf("result = %u \n", result);
	return 0;
}
