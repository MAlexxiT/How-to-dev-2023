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

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n,e,ogn,mv = 0;
    set<int> arr;
    cin>>n; ogn=n;
    while(n--){cin>>e; arr.insert(e); mv = max(e,mv);}
    
    cout<<((arr.size()==ogn&& mv==ogn)?"YES":"NO")<<endl;
    

}
//--------------------EOSOLUTION---------------------------------