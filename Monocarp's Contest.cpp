#include <iostream>
#include <vector>
using namespace std;
int solve(){
	int n;
		cin>>n;
		vector<int> a(n);
		int o=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]) o++;
		}
		int z=n-o;
		if(z<2){
			cout<<"-1\n";
			return 0;
		}
		int ans=0;
		if(a[0]) ans++;
		if(a[n-1]) ans++;
		cout<<ans<<"\n";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
