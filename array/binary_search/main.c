#include <stdio.h>

/* Find a value in list, which is equal to target, and return its index.
 * The index belongs to [left, right] */
int binary_search_1(int *list, unsigned int left, unsigned int right, int target) {
	unsigned int middle;
	while(left <= right) { // left can be equal to right due to [left, right]. ex. [1,1] is legal.
		middle = (left + right) / 2;
		if(list[middle] > target) {
			// target is at left of middle, so update right.
			// list[middle] has been greater than target, so make right = middle - 1 rather than right = middle.
			right = middle - 1;
		} else if(list[middle] < target) {
			// let left = middle + 1, the reason is similar above situation.
			left = middle + 1;
		} else {
			// find it.
			return middle;
		}
	}	
	// not found
	return -1;
}

/* Find a value in list, which is equal to target, and return its index.
 * The index belongs to [left, right) */
int binary_search_2(int *list, unsigned int left, unsigned int right, int target) {
	unsigned int middle;
	while(left < right) { // left cannot be equal to right due to [left, right). ex. [1, 1) is illegal.
		middle = (left + right) / 2;
		if(list[middle] > target) {
			//target is left of middle, so update right.
			//list[middle] has been greater than target, but the right is out of range due to [lfet, right).
			//So make right = middle rather than right = middle - 1;
			right = middle;
		} else if(list[middle] < target) {
			left = middle + 1; // due to [left, right)
		} else {
			// found it
			return middle;
		}
	}
	// not found
	return -1;
}

int main(void) {
	// need an ordered array.
	int list[] = {1, 3, 5, 7, 9, 12, 20, 38};
	unsigned int len = sizeof(list) / sizeof(int);
	int target = 38;
	unsigned right = len - 1;
	unsigned left = 0;

	int result = binary_search_1(list, left, right, target);
	printf("result1 = %d\n", result);

	right = len - 2;
	left = 1;
	target = 20;
	result = binary_search_2(list, left, right, target);	
	printf("result2 = %d\n", result);

	return 0;
}
