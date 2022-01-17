#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<char> st;
        string temp1="";
        string temp2="";
        string num="";
        string ans="";
        for (int i = 0; i < s.length(); i++) 
        {
            if (s[i] == ']') 
            {
                while (!st.empty() && st.top() != '[') 
                {
                    temp1 = st.top() + temp1;
                    st.pop();
                }
                st.pop();
                while (!st.empty() && isdigit(st.top())) 
                {
                    num = st.top() + num;
                    st.pop();
                }
                int number = stoi(num);
                for (int j = 0; j < number; j++)
                    temp2 += temp1;
                for (int i=0; i<temp2.length(); i++)
                    st.push(temp2[i]);
            }
            else
                st.push(s[i]);
                
            temp1="";
            temp2="";
            num="";
        }
        while (!st.empty()) 
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
} 
