#include <iostream>
#include <vector>
using namespace std;
int solve(){
int n,m;
cin>>n>>m;
vector<int> cnt(m+1,0);
for( int ct=1;ct<=n;ct++){
	int curr;cin>>curr;
	cnt[curr]++;
}
vector<int> psum(m+1,0);
for(int i=1;i<=m;i++){
	psum[i]=psum[i-1]+cnt[i];
}
int ans=0;
for(int x=1;x<=m;x++){
	int carrotcnt=psum[m]-psum[x-1];
	if(2*x<=m){
		carrotcnt+=cnt[2*x];
	}
	ans=max(ans,carrotcnt);
}
cout<<ans<<endl;
}
int main(){
	int f;
	for(int i=0;i<f;i++) solve();
}
