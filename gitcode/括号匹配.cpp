#include <bits/stdc++.h>
using namespace std;
stack <char> st;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i ++) {
		if (s[i] == '(')
			st.push(s[i]);

		if (s[i] == '[')
			st.push(s[i]);

//		cout << st.top() << " " << s[i] << " " << i << "\n";

		if (s[i] == ')') {
			char ch = st.top();


			if (ch != '(') {
				cout << "NO";
				return 0;
			}

			st.pop();
		}

		if (s[i] == ']') {
			char ch = st.top();

			if (ch != '[') {
				cout << "NO";
				return 0;
			}

			st.pop();
		}
	}

	if (st.empty()) cout << "YES";
	else cout << "NO";
}
