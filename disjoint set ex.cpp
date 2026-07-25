#include<iostream>
#include<vector>
#include<map>
#include<set>
#define ll long long int
using namespace std;
int find(vector<int>& rel,int node){
	if(rel[node]!=node){
		rel[node]=find(rel,rel[node]);
	}
	return rel[node];
}
int join(vector<int>& rel,int lt,int rt){
	int rellt=find(rel,lt);
	int relrt=find(rel,rt);
	rel[relrt]=rellt;
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> rel(n+1);
	for(int i=0;i<n;i++) rel[i]=i;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		join(rel,a,b);
	}
	set<int> s;
	for(int i=1;i<=n;i++){
		s.insert(find(rel,rel[i]));
	}
	cout<<s.size();
}
