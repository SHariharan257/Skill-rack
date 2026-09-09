#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	ll amore=0,bmore=0;
	for(int i=0;i<n;i++){
		if(a[i]>b[i]) amore+=(a[i]-b[i]);
		if(b[i]>a[i]) bmore+=(b[i]-a[i]);
	}
	if(amore==0) {
	cout<<"No"<<endl;
	 return 0;
	 }
	ll anw=(bmore/amore)+2;
	vector<ll> ans;
	for(int i=0;i<n;i++){
		if(a[i]<=b[i]) ans.push_back(1);
		else ans.push_back(anw);
	}
	cout<<"Yes";
	for(ll wt:ans) cout<<wt<<" ";
	cout<<endl;
}
