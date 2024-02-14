#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'


vector<unsigned long long int>*arr;
void sim(unsigned long long int n, unsigned long long int meta,int ind){
	while(n!=meta){
		arr[ind].push_back(n);
        if(n%2LL==0LL){
            n/=2LL;
        }else{
            n*=3LL;
            n++;
        }
    }
    arr[ind].push_back(1);
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	vector<unsigned long long int> cam;
    //Este tipo de dato se usa porque los nodos pueden tener un ID tan grande como 10**18
	unsigned long long int n,spawnHarold,spawnAmigo,x;
    
	cin>>n>>spawnHarold;
	arr = new vector<unsigned long long int>[n+1]();
    sim(spawnHarold,1,n);
    
	
    for(int i = 0; i<n; i++){
        cin>>spawnAmigo;
        sim(spawnAmigo,1,i);
    }
 
    bool allSame = true;
    while(allSame){
        //Lo iguala a x, por si este es el ultimo nodo en comun
        x = arr[0].back();
        for(int i = 0; i<=n; i++){
            arr[i].pop_back();
        }
 
        //revisa que todos los amigos sigan en el mismo nodo
        //o que no se haya acabado la lista para algun amigo
        for(int i = 0; i<=n; i++){
            if(arr[i].size()==0){
                allSame = false;
                break;
            }
            if(i>0){
                if(arr[i].back()!=arr[i-1].back()){
                    allSame = false;
                    break;
                }
            }            
        }
    }
    
    int tamCaminoHarold,maximoCamino;   
    //Harold tiene que recorrer los nodos que quedaron
    tamCaminoHarold = arr[n].size();
    maximoCamino = 0;
    
    //busca el amigo, incluyendo a Harold, con el camino pendiente mas largo
    for(int i = 0; i<=n; i++){
        maximoCamino = max(maximoCamino,(int)arr[i].size());
    }
    cout<<"Harold must reach node "<<x<<" and wait "<<maximoCamino-tamCaminoHarold<<" second(s) for his friend(s) to arrive"<<endl;
}
//--------------------EOSOLUTION---------------------------------
