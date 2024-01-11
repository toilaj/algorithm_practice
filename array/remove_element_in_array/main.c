#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_list(int *list, unsigned int length) {
	int i;
	for(i = 0; i < length; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

void print_list_with_point(int *list, unsigned int length, unsigned int slow, unsigned int fast) {
	int i;
	char *list_slow = malloc(length); 
	char *list_fast = malloc(length);
	memset(list_slow,' ', length);
	memset(list_fast,' ', length);
	if(slow < length) {
		list_slow[slow] = 'S';
	}
	if(fast < length) {
		list_fast[fast] = 'F';
	}
	printf("fast: %u, slow: %u:  \n", fast, slow);
	for(i = 0; i < length; i++) {
		printf("%c ", list_fast[i]);
	}
	printf("\n");

	for(i = 0; i < length; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	for(i = 0; i < length; i++) {
		printf("%c ", list_slow[i]);
	}
	printf("\n");
	printf("---------------------------------\n");
	free(list_slow);
	free(list_fast);
}

void remove_element(int *list, int target, unsigned int length) {
	unsigned int fast = 0;
	unsigned int slow = 0;
	for(fast = 0; fast < length; fast++) {
		unsigned int old_slow = slow;
		if(list[fast] != target) {
			list[slow] = list[fast];
			slow++;
		} 
		print_list_with_point(list, length, slow, fast);

	}
}

unsigned int remove_element_duplicated(int *list, unsigned int dup, unsigned int length) {
	unsigned int fast = 0;
	unsigned int slow = 0;
	while(fast < length)  {
		unsigned int old_slow = slow;
		printf("########## round: %u ##########\n", fast);
		print_list_with_point(list, length, slow, fast);
		if(slow < dup || list[slow - dup] != list[fast]) {
			/* KEY: fast 和 slow 之间是已经检查过的元素，由于是有序数列，所以隐含检查过的元素一定是相同的。
			 *也就意味着靠dup拉开的距离之间元素一定是相同的。
			 * 另一方面理解：设dup = 2, 比较[slow - 2]而不是[slow - 1], 是因为 slow - 1位置的元素是上一次fast位置换过去的
			 * 一旦本次fast位置的数跟上一次fast的数一样（连续两个一样数字），就会造成本次slow位置不填数，错过连续相同
			 * 的数字。
			 */
			list[slow] = list[fast];
			slow++;
			printf("slow changed: %u -> %u\n", old_slow, slow);
			print_list_with_point(list, length, slow, fast);
		}
		fast++;
		print_list_with_point(list, length, slow, fast);
		printf("===========================\n");
	}	
	return slow;

}

int main(void) {
	int list[] = {0, 10, 20, 5, 7, 9};
	unsigned int length = sizeof(list) / sizeof(int);
	int target = 5;
//	remove_element(list, target, length);

	int list_dup[] = {2,2,2,2,3,3,5,5,7,7,7,9};
	unsigned int length_dup = sizeof(list_dup) / sizeof(int);
	
	printf("start: ");
	print_list(list_dup, length_dup);

	unsigned int len = remove_element_duplicated(list_dup, 2, length_dup);

	printf("result: ");
	print_list(list_dup, len);
	return 0;
}
