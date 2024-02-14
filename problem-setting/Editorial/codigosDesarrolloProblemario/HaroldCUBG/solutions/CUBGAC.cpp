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
vector<unsigned long long int>*arr;
void sim(unsigned long long int n, unsigned long long int meta,int ind){
	while(n!=meta){
		arr[ind].push_back(n);
        if(n%2LL==0LL){
            n/=2LL;
        }else{
            n*=3LL;
            n++;
        }
    }
    arr[ind].push_back(1);
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	vector<unsigned long long int> cam;
	unsigned long long int n,sa,e,x;
    int ogLen,ml = 0;
	cin>>n>>sa;
	arr = new vector<unsigned long long int>[n+1]();
    sim(sa,1,n);
    
	
    for(int i = 0; i<n; i++){
        cin>>e;
        sim(e,1,i);
    }

    bool allSame = true;
    while(allSame){
        x = arr[0].back();
        for(int i = 0; i<=n; i++){
            arr[i].pop_back();
        }


        for(int i = 0; i<=n; i++){
            if(arr[i].size()==0){
                allSame = false;
                break;
            }
            if(i>0){
                if(arr[i].back()!=arr[i-1].back()){
                    allSame = false;
                    break;
                }
            }            
        }
    }

    ogLen = arr[n].size();
    
    for(int i = 0; i<=n; i++){
        ml = max(ml,(int)arr[i].size());
    }
    cout<<"Harold must reach node "<<x<<" and wait "<<ml-ogLen<<" second(s) for his friend(s) to arrive"<<endl;
}
//--------------------EOSOLUTION---------------------------------