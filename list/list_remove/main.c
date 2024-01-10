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

node_t *remove_node_n_from_tail(node_t *head, unsigned int n) {
	node_t *fast = NULL;
	node_t *slow = head;
	node_t *dummy;
	node_t *remove;
	unsigned i = 0;
	if(head == NULL) {
		error_handler();
	}
	dummy = malloc(sizeof(node_t));
	if(dummy == NULL){
		error_handler();
	}
	fast = dummy;
	slow = dummy;
	dummy->next = head;
	while(i < n + 1) { //find the previous node for linked list to remove the target.
		fast = fast->next;
		i++;
	}
	while(fast != NULL && fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	// now find the previous node for the n node (slow points it).
	remove = slow->next;
	slow->next = slow->next->next;
	free(remove);
	head = dummy->next;
	free(dummy);
	return head;
}

int main(void) {
	node_t *head = construct_list(10);
	print_list(head);
	head = remove_node_n_from_tail(head, 10);
	print_list(head);
	return 0;
}
