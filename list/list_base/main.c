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

node_t *insert_head_target(node_t *head, int target, int value) {
	node_t *current;
	node_t *new;
	node_t *dummy;
	if(head == NULL) {
		error_handler();
	}
	dummy = malloc(sizeof(node_t));
	if(dummy == NULL) {
		error_handler();
	}
	dummy->next = head;
	current = dummy;
	while(current->next != NULL){
		if(current->next->value == target) {
			new = malloc(sizeof(node_t));
			if(new == NULL) {
				error_handler();
			}
			new->value = value;
			new->next = current->next;
			current->next = new;
			break;
		}
		current = current->next;
	}
	head = dummy->next;
	free(dummy);
	return head;
}

node_t *insert_tail(node_t *head, int value) {
	node_t *current;
	node_t *new;
	if(head == NULL) {
		error_handler();
	}
	current = head;
	while(current->next != NULL) {
		current = current->next;
	}
	new = malloc(sizeof(node_t));
	if(new == NULL) {
		error_handler();
	}
	new->value = value;
	new->next = NULL;
	current->next = new;
	return head;
}

node_t *insert_head_target_n(node_t *head, unsigned int n, int value) {
	node_t *current;
	node_t *dummy;
	node_t *new;
	if(head == NULL) {
		error_handler();
	}
	dummy =  malloc(sizeof(node_t));
	if(dummy == NULL) {
		error_handler();
	}
	dummy->next = head;
	current = dummy; // the node n is always current->next. current->next = head, n = 0.
	while(n != 0 && current != NULL) {
		current = current->next;
		n-- ;
	}
	new = malloc(sizeof(node_t));
	if(new == NULL) {
		error_handler();
	}
	new->value = value;
	new->next =current->next;
	current->next = new;
	head = dummy->next;
	free(dummy);
	return head;
}

node_t *remove_target_n(node_t *head, unsigned int n) {
	node_t *current;
	node_t *dummy;
	node_t *remove;
	if(head == NULL) {
		error_handler();
	}
	dummy = malloc(sizeof(node_t));
	if(dummy == NULL){
		error_handler();
	}
	dummy->next = head;
	current = dummy;
	while(n != 0 && current != NULL) {
		current = current->next;
		n--;
	}
	remove =  current->next;
	current->next = current->next->next;
	free(remove);
	head = dummy->next;
	free(dummy);
	return head;
}



int main(void) {
	node_t *head = construct_list(10);
	print_list(head);
	head = remove_target(head, 4);
	print_list(head);
	head = insert_head_target(head, 5, 100);
	print_list(head);
	head = insert_tail(head, 200);
	print_list(head);
	head = insert_head_target_n(head, 3, 300);
	print_list(head);
	head = remove_target_n(head, 2);
	print_list(head);
	return 0;
}	
