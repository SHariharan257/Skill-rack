#include<iostream>
using namespace std;
void solve(){
    int x,y; cin>>x>>y;
    int sum=x+y,rx=0,ry=0;
    for(int sh=30;sh>=0;sh--){
        if(sum&(1<<sh)){
            if((rx | (1<<sh))<=x){rx|=(1<<sh);}
            else{ry|=(1<<sh);}
        }
    }
    cout<<sum<<" "<<x-rx<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
