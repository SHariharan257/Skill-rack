#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> loc(n,0);
	vector<ll> no_vil(n+1,0LL);
	for(int i=0;i<n;i++) cin>>loc[i];
	for(int i=1;i<=n;i++){
		int curr;
		cin>>curr;
		no_vil[i]=no_vil[i-1]+curr;
	}
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int lt=lower_bound(loc.begin(),loc.end(),a)-loc.begin();
		int rt=upper_bound(loc.begin(),loc.end(),b)-loc.begin();
		cout<<no_vil[rt]-no_vil[lt];		
	}
}
