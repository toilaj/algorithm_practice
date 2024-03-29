#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;
struct node {
	int value;
	node_t *next;
};

void error_handler() {
	printf("cannot malloc \n");
	exit(1);
}

void print_list(node_t *head) {
	node_t *p = head;
	if(p == NULL) {
		printf("head == NULL\n");
		return;
	}
	while(p->next != NULL) {
		printf("%d ", p->value);
		p = p->next;
	}
	printf("%d ", p->value); //PS: cannot be omitted the last node.
	printf("\n");
}

node_t* construct_list(unsigned int n) {
	int i;
	node_t *p;
	node_t *dummy;
	node_t *current;
	dummy = malloc(sizeof(node_t));
	if(dummy == NULL) {
		error_handler();
	}
	current = dummy;
	for(i = 0; i < n; i++) {
		p = malloc(sizeof(node_t));
		if(p == NULL) {
			error_handler();	
		}
		p->value = i;
		current->next = p;
		current =  current->next;
	}
	node_t *head = dummy->next;
	free(dummy);
	return head;
}

node_t *revert_list(node_t *head) {
	node_t *previous = NULL;
	node_t *current = head;
	node_t *temp;
	if(head == NULL) {
		error_handler();
	}
	while(current != NULL) {
		temp = current->next;
		current->next = previous;
		previous = current;
		current = temp;
	}
	return previous;
}

int main(void) {
	node_t *head = construct_list(10);
	print_list(head);
	head = revert_list(head);
	print_list(head);
	return 0;
}
