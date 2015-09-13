#include<iostream>
#include<sstream>
using namespace std;
int main()
{
	string str, line;
	while(getline(cin, line))
	{
		istringstream stream(line);
		int a = 0;
		stream >> a;
		cout<<a<<endl;
//		while(stream>>str)
//			cout<<str.c_str()<<endl;
	}	
	return 0;
}
