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
int mat[1010][1010];
int rows,cols;
struct celda{
    int r; int c; int h;
};
//Medio hacky el asunto
set<pair<int,int>> vis;
bool val(celda e){
    if(e.r<0 || e.c<0 || e.r>=rows || e.c>=cols) return false;
    return (vis.find({e.r,e.c})==vis.end()) && e.h<=3;
}
void bfs(celda curr){
    queue<celda> fringe; 
    fringe.push(curr);
    vis.insert({curr.r,curr.c});
    int movs[]={-1,1};
    celda aux;
    while(fringe.size()){
        curr = fringe.front(); fringe.pop();
        mat[curr.r][curr.c] = min(mat[curr.r][curr.c],curr.h);
        curr.h++;

        for(int d: movs){
            aux = curr; aux.r+=d;
            if(val(aux)){
                vis.insert({aux.r,aux.c});
                fringe.push(aux);
            }
            aux = curr; aux.c+=d;
            if(val(aux)){
                vis.insert({aux.r,aux.c});
                fringe.push(aux);
            }
        }
    }
}
bool comp(celda a, celda b){
    if(a.r == b.r){
        return a.c<b.c;
    }
    return a.r>b.r;
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin>>rows>>cols;
    for(int r = 0; r<rows; r++){
        for(int c = 0; c<cols; c++){
            mat[r][c]=4;
        }
    }
    celda a;
    int q,mv = 0;;
    cin>>q;
    while(q--){
        cin>>a.r>>a.c; a.h = 0;
        bfs(a);
        vis.clear();
    }
    
    for(int r = 0; r<rows; r++){
        for(int c = 0; c<cols; c++){
            mv = max(mat[r][c],mv);
        }
    }

    vector<celda> res;
    for(int r = 0; r<rows; r++){
        for(int c = 0; c<cols; c++){
            if(mv==mat[r][c]){
                a.r = r; a.c = c;
                res.push_back(a);
            }
        }
    }
    sort(res.begin(),res.end(),comp);
    if(mv == 0){
        cout<<-1<<endl;
    }else{
        cout<<res[0].r<<" "<<res[0].c<<endl;
    }
    
}
//--------------------EOSOLUTION---------------------------------