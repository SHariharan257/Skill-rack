#include<iostream>
#include<string>
using namespace std;
int main(){
	int n,q;
	cin>>n>>q;
	string s;
	int pos=n-1;
	cin>>s;
	while(q--){
		int q1,q2;
		cin>>q1>>q2;
		q2=q2%n;
		if(q1==1){
			pos=pos-q2;
			if(pos<0) pos+=n;
		}
		else{
			cout<<s[(pos+q2)%n]<<endl;
		}
	}
}
