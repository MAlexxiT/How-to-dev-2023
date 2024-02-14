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
bool solve(char x){
    string s ="KODEMANIAkodemania2023";
    for(char l: s){ if(l==x) return true;}
    return false;
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	char l;
	cin>>l;
	cout<<(solve(l)?"YES":"NO")<<endl;

}
//--------------------EOSOLUTION---------------------------------