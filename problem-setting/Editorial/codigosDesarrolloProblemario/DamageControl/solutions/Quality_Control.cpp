#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
//#define DBG(x) ;
//#define RAYA ;
//#define RAYAS ;
vector<int> a,b;
vector<long long int> auxa,auxb;
int n,k;
long long int solve(int ma, int mb){
	auxa.clear();auxb.clear();
	
	for(int i = 0; i<n; i++){
		if(ma%2==1){
			auxa.push_back(a[i]);
		}
		ma/=2;
	}

	for(int i = 0; i<n; i++){
		if(mb%2==1){
			auxb.push_back(b[i]);
		}
		mb/=2;
	}

	long long int res = 0;
	for(int i = 0; i<k; i++){
		res+=abs(auxa[i]-auxb[i]);
	}

	//assert(auxa.size()==k);
	//assert(auxb.size()==k);
	return res;
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int e;
	cin>>n>>k;

	while(n--){
		cin>>e;
		a.push_back(e);
	}
	n = a.size();


	while(n--){
		cin>>e;
		b.push_back(e);
	}
	n = b.size();

	int upp = pow(2,n);
	vector<int> mascaras;
	for(int i = 0; i<upp; i++){
		if(__builtin_popcount(i)==k){
			mascaras.push_back(i);
		}
	}
	//cout<<upp<<endl;
	//100
	long long int res = 100000000000LL;
	for(int ai: mascaras){
		for(int bi: mascaras){
			res = min(res,solve(ai,bi));
		}
	}
	cout<<res<<endl;
}
//--------------------EOSOLUTION---------------------------------