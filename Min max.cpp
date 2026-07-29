#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
int main()
{
	int n;
	vector<int> a(n+1,0);
	cin>>n;
	int same=0,exch=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(i==a[i]) same++;
		else if(i==a[a[i]]) exch++;
		} 
		int ans=exch/2+(1LL*same*(same-1))/2;
	cout<<ans<<endl;
	}
	
	
