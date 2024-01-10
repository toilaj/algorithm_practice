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

node_t* construct_list_with_ring(unsigned int n, unsigned int m) {
	int i;
	node_t *p;
	node_t *dummy;
	node_t *current;
	node_t *ring_enter;
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
		if(i == m) {
			ring_enter = p;
		}	
		current =  current->next;
	}
	node_t *head = dummy->next;
	free(dummy);
	current->next = ring_enter;
	printf("ring enter node: %d\n", ring_enter->value);
	return head;
}

node_t *find_ring(node_t *head) {
	node_t *fast = head;
	node_t *slow = head;
	node_t *find = head;
	if(head == NULL) {
		error_handler();
	}
	while(fast != NULL && fast->next != NULL) { //fast point walks two step once, so judge fast->next.
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast) {
			// meet each other!
			//start to find enter
			while(slow != find) {
				slow = slow->next;
				find = find->next;
			}
			return find;
		}
	}
	// find nothing
	return NULL;
}

int main(void) {
	node_t *head = construct_list_with_ring(10, 6);
	node_t *enter = find_ring(head);
	printf("find the enter node: %d\n", enter->value);
	return 0;
}
