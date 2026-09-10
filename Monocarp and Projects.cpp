#include <iostream>
#define ll long long int
using namespace std;
void solve(){
	ll x,y,z;
	cin>>x>>y>>z;
	ll ans=0,rem=0,ct=0;
	for(int i=0;i<z;i++){
		rem=(y+ct)%(x+ct);
		ans+=rem;
		ct++;
		if(rem==(y+ct)-(x+ct)) break;
	}
	if(z>ct){
		ans+=(z-ct)*(y-x);
	}
	cout<<ans<<"\n";
}
int main(){
	int n;
	cin>>n;
	while(n--){
		solve();
	}
}
