#include <iostream>
#include <vector> 
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<int> arr(n+1),psum(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>0){
			psum[max(1,i-arr[i]+1)]++;
			if(i+arr[i]<=n){
				psum[i+arr[i]]--;
			}
		}
	}
	for(int i=1;i<=n;i++) psum[i]+=psum[i-1];
	string ans="";
	for(int i=1;i<=n;i++){
		if(arr[i]!=-1){
			bool valid=false; //check cond
			if(i-arr[i]>=1 && psum[i-arr[i]]==0) valid=true;
			if(i+arr[i]<=n && psum[i+arr[i]]==0) valid=true;
			if(!valid){
				cout<<"-1"<<endl;
				return;
			}
		}
		char ch=(psum[i]==0?'1':'0');
		ans.push_back(ch);
	}
	cout<<ans<<endl;
	
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++) solve();
}
