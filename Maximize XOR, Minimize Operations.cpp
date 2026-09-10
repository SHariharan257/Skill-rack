#include <iostream>
using namespace std;
void solve(){
	int x,y;
	cin>>x>>y;
	if(x==0){
		cout<<y<<" "<<x<<"\n";
		return;
	}
	int prev,curr=0,ct=0;
	while(x!=0){
		x-=1;
		y+=1;
		prev=curr;
		curr=x^y;
		if(prev>curr){
			cout<<prev<<" "<<ct<<"\n";
			break;
		}
		ct++;
	}
	cout<<curr<<" "<<ct<<"\n";
}
int main(){
	int n;
	cin>>n;
	while(n--){
		solve();
	}
}
