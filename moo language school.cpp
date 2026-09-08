#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve(){
	int n,k;
	cout<<"\n";
	cin>>n>>k;
	string s;
	cin>>s;
	cout<<"\n";
	int f=n/k; //f->farm
	vector<bool> own(f,false);
	for(unsigned int i=0;i<s.size();i++){
		if(s[i]=='0'){
			int farmindx=i/k;
			own[farmindx]=true;
		}
	}
	int count=0;
	for(int i=0;i<f;i++){
		if(!own[i]) count++;
	}
	cout<<count;
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
}
