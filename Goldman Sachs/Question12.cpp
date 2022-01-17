#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
		long long int ChessboardSquares(int n)
		{
			long long int count = (n*(n+1)*((2*n)+1))/6;
			return count;
		}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		cout<<ob.ChessboardSquares(n)<<endl;
	}
	return 0;
}
