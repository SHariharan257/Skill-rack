#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class SegmentTree{
    vector<ll> tree;
public:
    SegmentTree(int n){
        tree.resize(4*n);
    }
    void build(const vector<ll>&a,int start,int end,int node){
        if(start==end){
            tree[node]=a[start];
            return;
        }
        int mid=(start+end)/2;
        build(a,start,mid,2*node);
        build(a,mid+1,end,2*node+1);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
    ll query(int start,int end,int node,int left,int right){
        if(end<left||start>right) return LLONG_MAX;
        if(left<=start&&end<=right) return tree[node];
        int mid=(start+end)/2;
        return min(query(start,mid,2*node,left,right),query(mid+1,end,2*node+1,left,right));
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<ll>a(n);
    for(ll&x:a) cin>>x;
    SegmentTree segmentTree(n);
    segmentTree.build(a,0,n-1,1);
    while(q--){
        int left,right;
        cin>>left>>right;
        cout<<segmentTree.query(0,n-1,1,left-1,right-1)<<'\n';
    }
    return 0;
}
