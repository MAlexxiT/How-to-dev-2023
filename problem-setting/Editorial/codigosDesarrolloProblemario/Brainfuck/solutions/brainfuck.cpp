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

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string s;
    long long int tam;
    long long int pt = 0;
    map<long long int,int> arr;
    cin>>s>>tam;
    for(char l: s){
        if(arr[pt]==0){
            arr[pt] = 32;
        }
        if(l=='+'){
            arr[pt]++; 
            arr[pt]= (arr[pt]<=126?arr[pt]:32);
        }
        if(l=='-'){
            arr[pt]--; 
            arr[pt]= (arr[pt]>=32?arr[pt]:126);
        }
        if(l=='>'){
            pt++; pt%=tam;
        }
        if(l=='<'){
            pt+=tam; pt--; pt%=tam;
        }
        if(l=='.'){
            cout<<(char)arr[pt];
        }
    }
}