#include <iostream>
#include <vector>
using namespace std;
int hcf(int a,int b){
	return b==0?a:hcf(b,a%b);
}
int solve(){
		int n;
		cin>>n;
		vector<int> val(n);
		for(int i=0;i<n;i++) cin>>val[i];
		cout<<hcf(val[0],val[n-1])<<"\n";
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
}
