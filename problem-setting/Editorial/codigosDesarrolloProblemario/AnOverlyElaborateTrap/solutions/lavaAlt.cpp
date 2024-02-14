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
int rows,cols;
int movs[] = {-1,0,1};
int** grid;
bool isVal(int r,int c){
    return r>=0 && r<rows && c>=0 && c<cols; 
}
void dfs(int r, int c,int t){
    if(t==4){
        return;
    }
    grid[r][c] = min(grid[r][c],t);
    t++;
    for(int dr : movs){
        for(int dc: movs){
            if(dr!=0 && dc!=0){
                continue;
            }
            if(isVal(r+dr,c+dc)){
                if(grid[r+dr][c+dc]>t){
                    dfs(r+dr,c+dc,t);
                }
            }
        }
    }
}
bool comp(const pair<int,int> a, const pair<int,int> b){
    if(a.first == b.first){
        return a.second<b.second;
    }
    return a.first > b.first;
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>rows>>cols;
    grid = new int*[rows];
    for(int r = 0; r<rows; r++){
        grid[r] = new int[cols];
        for(int c = 0; c<cols; c++){
            grid[r][c] = 4;
        }
    }

    int g,r,c;
    cin>>g;
    while(g--){
        cin>>r>>c;
        dfs(r,c,0);
    }   

    int mv = 0;
    for(int r = 0; r<rows; r++){
        for(int c = 0; c<cols; c++){
            mv = max(mv,grid[r][c]);
        }
    }

    if(mv==0){
        cout<<-1<<endl;
    }else{
        vector<pair<int,int>> arr;
        for(int r = 0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                if(grid[r][c] == mv){
                    arr.push_back(make_pair(r,c));
                }
            }
        }
        /*cout<<mv<<endl;
        for(pair<int,int> el: arr){
            cout<<el.first<<" "<<el.second<<endl;
        }*/
        sort(arr.begin(),arr.end(),comp);
        cout<<arr[0].first<<" "<<arr[0].second<<endl;
    }
}
//--------------------EOSOLUTION---------------------------------