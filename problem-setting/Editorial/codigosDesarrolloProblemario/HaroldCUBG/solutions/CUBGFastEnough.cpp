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

int sim(unsigned long long int n,unsigned long long int meta){
	int res = 0;
    while(n!=meta &&n!=1){
        if(n%2LL==0LL){
            n/=2LL;
        }else{
            n*=3LL;
            n++;
        }
        res++;
    }
    return (n==meta?res:-1);
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    unsigned long long int n,ant,e;
    vector<unsigned long long int> arr;
    int res,curr,d;
    cin>>n>>ant;
    while(n--){
        cin>>e;
        arr.push_back(e);
    }
    n = arr.size();
    d = 0;
    while(true){
        res = d;
        for(unsigned long long int  el: arr){
            curr = sim(el,ant);
            res= max(res,curr);
            if(curr<0){
                res = -10;
                break;
            }
        }

        if(res>=0 || ant==1){
            break;
        }
        if(ant%2LL==0LL){
            ant/=2LL;
        }else{
            ant*=3LL;
            ant++;
        }
        d++;
    }
    cout<<"Harold must reach node "<<ant<<" and wait "<<res-d<<" second(s) for his friend(s) to arrive"<<endl;
}
//--------------------EOSOLUTION---------------------------------