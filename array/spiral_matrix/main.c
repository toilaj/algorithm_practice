#include <stdio.h>

#define N 7

void print_matrix(unsigned int n, int list[][N]) {
	int i,j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("%02d ", list[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void make_matrix(unsigned int n, int list[][N]) {
	unsigned int turn = n / 2;
	unsigned int x = 0;
	unsigned int y = 0;
	unsigned int x_start_off = 0;
	unsigned int y_start_off = 0;
	unsigned int x_end_off = 1;
	unsigned int y_end_off = 1;
	int count = 1;	
	while(turn--) {
		for(x = x_start_off, y = y_start_off; x < n - x_end_off; x++) {
			list[y][x] = count;	
			count++;
		}
		for(y = y_start_off; y < n - y_end_off; y++) {
			list[y][x] = count;
			count++;
		}
		for(; x > x_start_off; x--) {
			list[y][x] = count;
			count++;
		}
		for(; y > y_start_off; y--) {
			list[y][x] = count;
			count++;
		}
		x_start_off++;
		y_start_off++;
		x_end_off++;
		y_end_off++;
		print_matrix(n, list);		
	}
	if(n & 0x1) {
		x++;
		y++;
		list[y][x] = count;
		print_matrix(n, list);
	}
}


int main(void) {
	int list[N][N] = {0};
	make_matrix(N, list);
	return 0;
}
