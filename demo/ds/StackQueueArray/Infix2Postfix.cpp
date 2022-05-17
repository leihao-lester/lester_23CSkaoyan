using namespace std;
#include <iostream>
#include <stack>
#include <string>

int Prior(char a)
{
	if(a == '(') return 0;
	else if(a == '*' || a == '/') return 2;
	else return 1;
}

string Infix2Postfix(string s_in)
{
	stack<char> s;
	string s_out;
	for(int i = 0; i < s_in.size(); i++)
	{
		if((s_in[i] <= '9' && s_in[i] >= '0') || (s_in[i] <= 'z' && s_in[i] >= 'a') || (s_in[i] <= 'Z' && s_in[i] >= 'A')) s_out += s_in[i];
		else if(s_in[i] == '(') s.push(s_in[i]);
		else if(s_in[i] == ')')
		{
			while(s.top() != '(')
			{
				s_out += s.top();
				s.pop();
			}
			s.pop();
		}
		else
		{
			while(!s.empty() && Prior(s.top()) >= Prior(s_in[i]))
			{
				s_out += s.top();
				s.pop();
			}
			s.push(s_in[i]);
		}
		cout<<s_out<<endl;
	}
	while(!s.empty())
	{
		s_out += s.top();
		s.pop();
	}
	return s_out;
}

int main()
{
	string s_in;
	cin>>s_in;
	string s_out = Infix2Postfix(s_in);
	cout<<s_out;
}	
