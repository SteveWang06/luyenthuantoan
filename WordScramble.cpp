


#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;
int main(){

  string s;

  while(getline(cin,s)){

    istringstream sin(s);
    int pd=0;

    while(sin>>s){

    	reverse(s.begin(),s.end());

      if(pd++) cout << " ";

      cout << s;
    }
		cout << endl;
	}
  return 0;
}