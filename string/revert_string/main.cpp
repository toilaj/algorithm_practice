#include <iostream>
#include <string>

using namespace std;

unsigned int  trim_space(string &s) {
	unsigned int fast = 0;
	unsigned int slow = 0;
	for(; fast < s.length(); fast++) {
		if(s[fast] != ' ') {
			s[slow] = s[fast];
			slow++;
		} else {
			if(slow == 0) {
				continue;
			}
			if(s[slow - 1] == ' ') {
				continue;
			} else {
				s[slow] = s[fast];
				slow++;
			}
		}
	}
	return  slow;
}

void revert_word(string &s , unsigned int start, unsigned int len) {
	unsigned int left = 0 + start;
	unsigned int right = len - 1 + start;
	char tmp;
	unsigned int mid = len / 2 + start;
	for(; left < mid; left++, right--) {
		tmp = s[left];
		s[left] = s[right];
		s[right] = tmp;
	}
}

void revert_sentence(string &s) {
	revert_word(s, 0, s.length());
}

void revert_words(string &s) {
	revert_sentence(s);
	s.resize(trim_space(s));
	unsigned int i;
	unsigned int start = 0;
	for(i = 0; i < s.length(); i++) {
		if(s[i] != ' ') {
			continue;
		} else {
			revert_word(s, start, i - start);
			i++;
			start = i;	
		}
	}
	revert_word(s, start, i - start);
}	

int main(void) {
	string s = " this is  a  example  ";
	revert_words(s);
	cout << s << endl;
	return 0;
}
