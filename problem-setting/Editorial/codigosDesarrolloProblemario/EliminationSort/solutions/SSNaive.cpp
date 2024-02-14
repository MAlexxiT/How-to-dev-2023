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
    int n,e;
    bool f = true;
    bool suitable = true;
    vector<int> arr;
    vector<int> res;
    cin>>n;

    while(n--){
        cin>>e;
        arr.push_back(e);
    }
    n = arr.size(); 
    res.push_back(arr[0]);
    
    for(int i = 1; i<n; i++){
        suitable = true;
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n;k++){
                if(k<res.size()){
                    if(arr[j]==res[k]){
                        suitable = (suitable && (arr[j] <= arr[i]));
                    }
                }
                
            }
        }
        if(suitable){
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