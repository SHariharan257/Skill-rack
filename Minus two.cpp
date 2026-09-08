#include <iostream>
using namespace std;
int solve(){
	int odd=0,eoq=0,eeq=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	int curr;
		cin>>curr;
		if(curr%2!=0) odd++;
		else{
			if((curr/2)%2==0) eeq++;
			else eoq++;
		}
	}
	cout<<max(odd,max(eoq,eeq));
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		solve();
		cout<<"\n";
	}

}
