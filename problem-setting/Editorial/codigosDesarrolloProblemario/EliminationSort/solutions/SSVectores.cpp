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
    int n,e;
    bool f = true;
    vector<int> arr;
    vector<int> res;
    cin>>n;

    while(n--){
        cin>>e;
        arr.push_back(e);
    }
    res.push_back(arr[0]);
    n = arr.size(); 

    for(int i = 1; i<n; i++){
        if(arr[i]>=res.back()){
            res.push_back(arr[i]);
        }
    }

    for(int el: res){
        if(f){
            f = false;
        }else{
            cout<<" ";
        }
        cout<<el;
    }
    cout<<endl;
}   
//--------------------EOSOLUTION---------------------------------