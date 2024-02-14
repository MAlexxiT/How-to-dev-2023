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
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n,num,cont;
	bool borrar=true;
	vector <int> vec;
	map <int, int> mp;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin>>num;
		vec.push_back(num);
	}

	while(borrar){
		borrar=false;
		cont=0;
		for (int i = 0; i < vec.size()-1; i++)
		{
			if (vec[i]>vec[i+1])
			{
				cont++;
				mp[i+1]++;
			}
		}
		if (cont!=0)
		{
			borrar=true;
			cont=0;
			for (auto it=mp.begin(); it!= mp.end(); it++)
			{
				vec.erase(vec.begin()+it->first-cont);
				cont++;
			}
			
		}
		mp.clear();
		

	}
	for (int i = 0; i < vec.size(); i++)
	{
		cout<<vec[i]<<' ';
	}
	

	

}
//--------------------EOSOLUTION---------------------------------