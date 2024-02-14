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
map<unsigned long long int, int> ocurr;
//retorna el tamaño del recorrido 
int simular(unsigned long long int n, unsigned long long int meta){
    int res = 0;
    while(n!=meta){
        ocurr[n]++;
        if(n%2LL==0LL){
            n/=2LL;
        }else{
            n*=3LL;
            n++;
        }
        res++;
    }
    ocurr[meta]++;
    return res;
}
int prim(unsigned long long int n, unsigned long long int meta){
    while(ocurr[n]!=meta){
        if(n%2LL==0LL){
            n/=2LL;
        }else{
            n*=3LL;
            n++;
        }
    }
    return n;
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    unsigned long long int n,sx,e;
    int dsx,dse;
    pair<unsigned long long int, int> mv; mv.first = 0; mv.second = 0;

    cin>>n>>sx;
    dsx = simular(sx,1);
    mv.second = dsx;
    for(int i = 0; i<n; i++){
        cin>>e;
        dse = simular(e,1);
        if(dse > mv.second){
            mv.first = e;mv.second = dse;
        }
    }
    cout<<"Harold must reach node "<<prim(sx,n+1)<<" and wait "<<mv.second - dsx<<" second(s) for his friend(s) to arrive"<<endl;




}
//--------------------EOSOLUTION---------------------------------