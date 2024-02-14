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
long long int res;
long long int curr;
void solveb(int ind){
	if(ind==n){
		if(auxb.size() == k){
			curr = 0;
			for(int i = 0; i<k; i++){
				curr+=abs(auxa[i]-auxb[i]);
			}
			res = min(res,curr);
			return;
		}
		return;
	}
	if(auxb.size() == k){
		curr = 0;
		for(int i = 0; i<k; i++){
			curr+=abs(auxa[i]-auxb[i]);
		}
		res = min(res,curr);
		return;
	}
	auxb.push_back(b[ind]);
	solveb(ind+1);
	auxb.pop_back();
	solveb(ind+1);

	return;
}
void solvea(int ind){
	if(ind==n){
		if(auxa.size() == k){
			solveb(0);
			return;
		}
		return;
	}
	if(auxa.size() == k){
		solveb(0);
		return;
	}
	auxa.push_back(a[ind]);
	solvea(ind+1);
	auxa.pop_back();
	solvea(ind+1);

	return;
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int e;
	res = 100000000000LL;
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

	solvea(0);
	
	cout<<res<<endl;
}
//--------------------EOSOLUTION---------------------------------