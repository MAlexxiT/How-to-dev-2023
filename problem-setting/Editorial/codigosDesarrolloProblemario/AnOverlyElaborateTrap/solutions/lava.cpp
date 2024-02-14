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
int movs[] = {-1,1};
int** grid;
bool isVal(int r,int c,int pr, int pc){
    if(!(r>=0 && r<rows && c>=0 && c<cols)){
        return false;
    } 
    return grid[r][c]>grid[pr][pc]+1;
}
void bfs(pair<int,int> padre) {
	queue<pair<int,int>> fringe;
	pair<int,int> curr;
    grid[padre.first][padre.second] = 0;
	fringe.push(padre);
	while (fringe.size() > 0) {
		curr = fringe.front();
		fringe.pop();

		for(int d : movs){
            if(isVal(curr.first+d,curr.second,curr.first,curr.second)){
                fringe.push(make_pair(curr.first+d,curr.second));
                grid[curr.first+d][curr.second] = grid[curr.first][curr.second]+1;
            }
            if(isVal(curr.first,curr.second+d,curr.first,curr.second)){
                fringe.push(make_pair(curr.first,curr.second+d));
                grid[curr.first][curr.second+d] = grid[curr.first][curr.second]+1;
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
        //cout<<"----"<<endl;
        bfs(make_pair(r,c));
        //cout<<"----"<<endl;
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
        sort(arr.begin(),arr.end(),comp);
        /*cout<<mv<<endl;
        for(pair<int,int> el: arr){
            cout<<el.first<<" "<<el.second<<endl;
        }*/
        cout<<arr[0].first<<" "<<arr[0].second<<endl;
    }
}
//--------------------EOSOLUTION---------------------------------