#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		void largest(int arr[], int n)
		{
			vector <int> v;
			priority_queue <int> pq;
			for(int i=0; i<n; i++)
			{
				pq.push(arr[i]);
			}
			for(int i=0; i<10; i++)
			{
				v.push_back(pq.top());
				pq.pop();
			}
			for(int i=0; i<v.size(); i++)
			{
				cout<<v[i]<<" ";
			}
			cout<<endl;
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
		int arr[n];
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		Solution ob;
		ob.largest(arr, n);
		cout<<endl;
	}
}
