using namespace std;
#include <iostream>
#include <stack>
#include <string>

bool BracketsMatch(string s)
{
	stack<char> t;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '(' || s[i] == '[') t.push(s[i]);
		else
		{
			if(t.empty() || (s[i] == ')' && t.top() == '[') || (s[i] == ']' && t.top() == '(')) return false;
			t.pop();
		}
	}
	if(!t.empty()) return false;
	return true;
}

int main()
{
	string s;
	cin>>s;
	if(BracketsMatch(s)) cout<<"match successful";
	else cout<<"match failed";
}

