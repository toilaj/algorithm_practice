#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool judge_bracket(string &s) {
	stack<char> t;
	int i;
	for(i = 0; i < s.length(); i++) {
		switch(s[i]) {
			case '(':
				t.push(')');
				break;
			case '[':
				t.push(']');
				break;
			case '{':
				t.push('}');
			default:
				if(t.empty() == true) {
		       			continue;
				}	       
				if(s[i] == ')' || s[i] == '}' || s[i] == ']')  {
					if(t.top() != s[i]) {
						return false;
					} else {
						t.pop();
					}
				}
				break;
		}
		
	}
	return t.empty();
}

int main(void) {
	string s = "1 + (2 + 3) * {5 + 6 / [12 + (4 - 5)]}";
	bool r = judge_bracket(s);
	cout << "bracket is " << (r == true ? "matched" : "not matched") << endl;
	return 0;
}
	
