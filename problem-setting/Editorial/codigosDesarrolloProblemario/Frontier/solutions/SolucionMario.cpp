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
	int tC,cont;
	string str;

	cin >> tC;
	cin.ignore();
	while (tC--) {
		getline(cin,str);
		
		cont=0;
		for (int i = 0; i < str.size()-1; i++)
		{
			if(str[i]=='A'|| str[i]=='H'|| str[i]=='M'|| str[i]=='N'|| str[i]=='O'|| str[i]=='U'|| str[i]=='W' || str[i]=='V'|| str[i]=='J'||str[i]=='I'){
				if(str[i+1]=='B'|| str[i+1]=='C'|| str[i+1]=='D'|| str[i+1]=='E'|| str[i+1]=='F'|| str[i+1]=='G'|| str[i+1]=='I'|| str[i+1]=='K'|| str[i+1]=='L'|| str[i+1]=='P'|| str[i+1]=='Q'|| str[i+1]=='R'|| str[i+1]=='T' || str[i+1]=='A'|| str[i+1]=='H'|| str[i+1]=='M'|| str[i+1]=='N'|| str[i+1]=='O'|| str[i+1]=='U'|| str[i+1]=='W' ){
					cont++;
				}
			}
		}
		cout<<cont<<endl;
		str.clear();
        

	}

}
//--------------------EOSOLUTION---------------------------------