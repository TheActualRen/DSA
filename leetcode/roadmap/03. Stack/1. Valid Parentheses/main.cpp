#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> stack;
		unordered_map<char, char> map = {
			{'(', ')'},
			{'[', ']'}, 
			{'{', '}'}
		};

		for (char ch : s) {
			if (!stack.empty() && map[stack.top()] == ch) {
				stack.pop();
			} else {
				if (map.find(ch) != map.end()) {
					stack.push(ch);
				} else {
					return false;
				}
			}
		}

		return stack.empty();
    }
};
