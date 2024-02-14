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
	string str;
	vector <char> vec;
	char h=32;
	int n,cont,index=0;

	cin>>str;
	cin>>n;

	for (int i = 0; i < n; i++)
	{
		vec.push_back(h);
	}
	
	cont=0;
	while (cont!=str.size())
	{
		if (str[cont]=='+')
		{
			if (vec[index]==126)
			{
				vec[index]=32;
			}
			else{
				vec[index]++;
			}
		}
		else if(str[cont]=='-'){
			
			if (vec[index]==32)
			{
				vec[index]=126;
			}
			else{
				vec[index]--;
			}
			
		}
		else if(str[cont]=='>'){
			index++;
			if (index==vec.size())
			{
				index=0;
			}
			
		}
		else if(str[cont]=='<'){
			index--;
			if (index<0)
			{
				index=vec.size()-1;
			}
		}
		else if(str[cont]=='.'){
			cout<<vec[index];
		}
		cont++;
		
	}
	
	


}
//--------------------EOSOLUTION---------------------------------