#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next; //PS: cannot use node_t*
} node_t;

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
	printf("\n");
}

node_t* construct_list(unsigned int n) {
	int i;
	node_t *head = NULL;
	node_t *pre;
	node_t *p;
	for(i = 0; i < n; i++) {
		p = malloc(sizeof(node_t));
		if(p == NULL) {
			error_handler();	
		}
		if(head == NULL) {
			head = p;
			pre = p;
		}
		p->value = i;
		pre->next = p;
	        pre = pre->next;	
	}
	return head;
}

node_t *remove_target(node_t *head, int target) {
	node_t *p = NULL;
	node_t *dummy = NULL;
	if(head == NULL) {
		error_handler();
	}
	dummy = malloc(sizeof(node_t));
	if(dummy == NULL) {
		error_handler();
	}	
	dummy->next = head;
	p = dummy; 
	while(p->next != NULL) {
		node_t *pre = p;
		p = p->next;
		if(p->value == target) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
	}
	head = dummy->next;
	free(dummy);
	return head;
}

int main(void) {
	node_t *head = construct_list(10);
	print_list(head);
	head = remove_target(head, 4);
	print_list(head);
	return 0;
}	
