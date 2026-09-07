#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> cnt(m+1,0),psum(m+1,0);
    for(int ct=1;ct<=n;ct++){
        int curr;
        cin>>curr;
        cnt[curr]++;
    }
    for(int cl=1;cl<=m;cl++){
        psum[cl]=psum[cl-1]+cnt[cl];
    }
    vector<ll> ans(m+1,0);
    for(int cut=1;cut<=min(m,18);cut++){
        ll maxc=0;
        for(int x=1;x<=m;x++){
            ll currc=0;
            for(int mul=1;mul*x<=m;mul++){
                int lt=mul*x;
                int rt=lt+x-1;
                currc+=min(1LL*mul,(1LL<<cut)-1)
                    *(psum[min(rt,m)]-psum[lt-1]);
            }
            if((1LL<<cut)*x<=m){
                currc+=cnt[(1LL<<cut)*x];
            }
            maxc=max(maxc,currc);
        }
        ans[cut]=maxc;
    }
    for(int cut=1;cut<=m;cut++){
        cout<<ans[min(cut,18)]<<(cut==m?"\n":" ");
    }
}
int main(){
    int ct;
    cin>>ct;
    while(ct--){
        solve();
    }
}
