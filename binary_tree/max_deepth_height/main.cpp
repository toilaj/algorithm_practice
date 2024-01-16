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

int max_deepth(node_t *cur) {
	int max;
	if(cur == NULL) {
		return 0;
	}
	int l = max_deepth(cur->get_left());
	int r = max_deepth(cur->get_right());
	if(l > r) {
		max = l + 1;
	} else {
		max = r + 1;
	}
	return max;
}

int main(void) {
	node_t *root = init_br();
	vector<vector<int> > r;
	cout << "sequence traversal:" << endl;
	sequence_traversal(root,r);
	print_vec2(r);	

	cout << "max deepth: " << max_deepth(root) << endl;


	return 0;
}
