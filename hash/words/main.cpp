#include <iostream>
#include <string>

using namespace std;

bool judge_words(string &a, string &b) {
	int hash[26] = {0};
	string::iterator it;
	for(it = a.begin(); it != a.end(); it++) {
		hash[*it - 'a']++;
	}
	for(it = b.begin(); it != b.end(); it++) {
		hash[*it - 'a']--;
	}
	for(int i = 0; i < 26; i++) {
		if(hash[i] != 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	string a = "abccd";
	string b = "cbdca";
	bool result = false;
	result = judge_words(a, b);	
	cout.setf(ios_base::boolalpha);
	cout << "result = " << result << endl;
	return 0;
}
