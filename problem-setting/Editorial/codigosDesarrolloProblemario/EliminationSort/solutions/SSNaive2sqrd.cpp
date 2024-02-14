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
vector<int> eliminar(vector<int>arr,int pos){
    vector<int> aux;
    for(int i = 0; i<arr.size(); i++){
        if(i==pos){
            continue;
        }
        aux.push_back(arr[i]);
    }
    return aux;
}
//--------------------SOLBEGIN---------------------------------
int main() {
    int n,e;
    bool f = true;
    bool ord;
    vector<int> arr;
    cin>>n;

    while(n--){
        cin>>e;
        arr.push_back(e);
    }
    n = arr.size(); 
    
    ord = false;
    while(!ord){
        for(int i = 1; i<arr.size(); i++){
            if(arr[i]<arr[i-1]){
                arr = eliminar(arr,i);
                i--;
            }
        }
        ord = true;
        for(int i = 1; i<arr.size(); i++){
            if(arr[i]<arr[i-1]){
                ord = false;
                break;
            }
        }
    }


    for(int el: arr){
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