#include <iostream>
#include <vector>
#include <queue>

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

void print_vec2(vector<vector<int> > &v) {
	vector<vector<int> >::iterator it;
	vector<int>::iterator it1;
	for(it = v.begin(); v.end() != it; it++) {
		for(it1 = (*it).begin(); it1 != (*it).end(); it1++) {
			cout << *it1 << " ";
		}
		cout << endl;
	}
}

node_t *init_br() {

	node_t *node7 = new node_t(7, NULL, NULL);
	node_t *node4 = new node_t(7, NULL, NULL);

	node_t *node3 = new node_t(2, NULL, node7);
	node_t *node2 = new node_t(2, node4, NULL);

	node_t *node1 = new node_t(1, node2, node3);
	return node1;
}



void sequence_traversal(node_t *root, vector<vector<int> > &v) {
	queue<node_t*> q;
	int layer = 1;
	if(root == NULL) {
		return;
	}	
	q.push(root);
	while(!q.empty()){
		int size = q.size();
		vector<int> vi;
		while(size > 0) {
			size--;
			node_t *node = q.front();
			q.pop();
			vi.push_back(node->get_val());
			if(node->get_left() != NULL) {
				q.push(node->get_left());
			}
			if(node->get_right() != NULL) {
				q.push(node->get_right());
			}
		}
		v.push_back(vi);
	}	
	return;
}

bool compare_tree(node_t *left, node_t *right) {
	if(left == NULL && right == NULL) {
		return true;
	} else if(left == NULL && right != NULL) {
		return false;
	} else if(left != NULL && right == NULL) {
		return false;
	} else {
		if(left->get_val() != right->get_val()) {
			return false;
		} else {
			bool outside = compare_tree(left->get_left(), right->get_right());
			bool inside = compare_tree(left->get_right(), right->get_left());
			return outside && inside;
		}

	}
}

bool symmetry_tree(node_t *current) {
	node_t *tmp;
	if(current == NULL) {
		return false;
	}
	return compare_tree(current->get_left(), current->get_right());
}


int main(void) {
	vector<vector<int> > r;
	node_t *root = init_br();
	sequence_traversal(root,r);
	print_vec2(r);
	r.clear();
	cout.setf(ios_base::boolalpha);
	cout << "the tree is symmetry: " << symmetry_tree(root) << endl;
	return 0;
}
