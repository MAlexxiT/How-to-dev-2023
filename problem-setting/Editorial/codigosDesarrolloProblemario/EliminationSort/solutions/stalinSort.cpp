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
	//ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    //freopen("ai.txt", "r", stdin);
    //freopen("ei.txt", "w",stdout);
    int n, e,mv;
    cin>>n;
    n--;
    cin>>e;
    mv = e;
    cout<<e;
    while(n--){
        cin>>e;
        if(e>=mv){
            cout<<" "<<e;
        }
        mv = max(mv,e);
    }
    cout<<endl;
}
//--------------------EOSOLUTION---------------------------------