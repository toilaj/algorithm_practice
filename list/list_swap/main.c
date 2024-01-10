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

node_t *swap_list(node_t *head) {
	node_t *dummy;
	node_t *current;
	node_t *p1;
	node_t *p2;
	node_t *p3;
	if(head == NULL) {
		error_handler();
	}
	dummy = malloc(sizeof(node_t));
	if(dummy == NULL) {
		error_handler();
	}
	dummy->next = head;
	current = dummy;
	while(current->next != NULL && current->next->next != NULL) {
		p1 = current->next;
		p2 = p1->next;
		p3 = p2->next; 

		current->next = p2;
		p2->next = p1;
		p1->next = p3;

		current = p1;
	}
	head = dummy->next;
	free(dummy);
	return head;
}

node_t *swap_list_v2(node_t *head) {
	node_t *dummy;
	node_t *current;
	node_t *temp;
	node_t *temp1;
	if(head == NULL) {
		error_handler();
	}
	dummy = malloc(sizeof(node_t));
	if(dummy == NULL) {
		error_handler();
	}
	dummy->next = head;
	current = dummy;
	while(current->next != NULL && current->next->next != NULL) {
		temp = current->next; // p1
		temp1 = current->next->next->next; // p3
		current->next = current->next->next;
		current->next->next = temp;
		current->next->next->next = temp1;
		current = current->next->next;
	}	
	head = dummy->next;
	free(dummy);
	return head;
}

int main(void) {
	node_t *head = construct_list(9);
	print_list(head);
	head = swap_list(head);
	print_list(head);
	head = swap_list_v2(head);
	print_list(head);
	return 0;
}
