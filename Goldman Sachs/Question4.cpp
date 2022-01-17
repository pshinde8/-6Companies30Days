// Run Length Encoding

#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string ans="";
  //src+='#';
  int count=0;
  for(int i=1; i<=src.length(); i++)
  {
      if(src[i-1]!=src[i])
      {
          count++;
          ans += src[i-1];
          ans += to_string(count);
          count=0;
      }
      else
      {
          count++;
      }
      
  }
  return ans;
} 
