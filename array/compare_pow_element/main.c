#include <stdio.h>
/* get a new ordered array from an ordered array, in which the elements are to power of 2 for new array.*/

void make_array(int *list, unsigned int length, int *result) {
	int i = 0;
	int j = length - 1;
	int k = length - 1;
	while(i <= j) {
		int i2 = list[i] * list[i];
		int j2 = list[j] * list[j];
		if(i2 <= j2) {
			result[k] = j2;	
			j--;
		} else {
			result[k] = i2;
			i++;
		}
		k--;
	}
}


int main(void) {
	int list[5] = {-3, -2, 1, 5, 7};
	int result[5] = {0};
	unsigned length = sizeof(list) / sizeof(int);
	make_array(list, length, result);
	int i;
	for(i = 0; i < length; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}
