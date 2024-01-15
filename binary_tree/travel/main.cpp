#include <iostream>
#include <vector>

using namespace std;

typedef struct br_node node_t;

struct br_node {
public:
	br_node(int val, node_t *left, node_t *right):m_val(val), m_left(left), m_right(right){};
	void set_left(node_t *left) {
		m_left = left;
	}
	void set_right(node_t *right) {
		m_right = right;
	}
	void set_val(int val) {
		m_val = val;
	}
	int get_val() {
		return m_val;
	}
	node_t *get_left() {
		return m_left;
	}
	node_t *get_right() {
		return m_right;
	}
private:
	int m_val;
	node_t *m_left;
	node_t *m_right;
};

void print_vec(vector<int> &v) {
	vector<int>::iterator it;
	for(it = v.begin(); v.end() != it; it++) {
		cout << *it << " ";
	}
	cout << endl;
}
node_t *init_br() {
	node_t *node15 = new node_t(15, NULL, NULL);
	node_t *node14 = new node_t(14, NULL, NULL);
	node_t *node13 = new node_t(13, NULL, NULL);
	node_t *node12 = new node_t(12, NULL, NULL);
	node_t *node11 = new node_t(11, NULL, NULL);
	node_t *node10 = new node_t(10, NULL, NULL);
	node_t *node9 = new node_t(9, NULL, NULL);
	node_t *node8 = new node_t(8, NULL, NULL);

	node_t *node7 = new node_t(7, node14, node15);
	node_t *node6 = new node_t(6, node12, node13);
	node_t *node5 = new node_t(5, node10, node11);
	node_t *node4 = new node_t(4, node8, node9);

	node_t *node3 = new node_t(3, node6, node7);
	node_t *node2 = new node_t(2, node4, node5);

	node_t *node1 = new node_t(1, node2, node3);
	return node1;
}


void preorder_traversal(node_t *current, vector<int> &r) {
	if(current == NULL) {
		return;
	}
	r.push_back(current->get_val());
	preorder_traversal(current->get_left(), r);
	preorder_traversal(current->get_right(), r);
	return;
}

void postorder_traversal(node_t *current, vector<int> &r) {
	if(current == NULL) {
		return;
	}
	postorder_traversal(current->get_left(), r);
	postorder_traversal(current->get_right(), r);
	r.push_back(current->get_val());
	return;
}

void inorder_traversal(node_t *current, vector<int> &r) {
	if(current == NULL) {
		return;
	}
	inorder_traversal(current->get_left(), r);
	r.push_back(current->get_val());
	inorder_traversal(current->get_right(), r);
	return;
}


int main(void) {
	vector<int> result;	
	node_t *root = init_br();

	preorder_traversal(root, result);
	print_vec(result);
	result.clear();

	inorder_traversal(root, result);
	print_vec(result);
	result.clear();

	postorder_traversal(root, result);
	print_vec(result);
	result.clear();

	return 0;
}
