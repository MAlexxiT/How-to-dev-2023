#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

//           filas,columnas (r,c)
int tiempo[1000][1000];
bool visitado[1000][1000];
int filas, columnas;
bool esValido(int f, int c){
    if(f<0) return false;
    if(f>=filas) return false;
    if(c<0) return false;
    if(c>=columnas) return false;
    if(visitado[f][c]) return false;
    //si llego aqui entonces si es valido
    return true;
}
void simular(vector<pair<int,int>> padres){
    for(int f = 0; f<filas; f++){
        for(int c = 0; c<columnas; c++){
            visitado[f][c] = false;
            //como la lava fluye a lo sumo por 3 segundos, si una celda se queda con 4 significa que nunca es alcanzada
            tiempo[f][c] = 4;
        }
    }

    queue<pair<int,int>> porProcesar;
    pair<int,int> actual;

    for(pair<int,int> padre: padres){
        visitado[padre.first][padre.second] = 1;
        //se tardan cero segundos en llegar a cada celda padre
        tiempo[padre.first][padre.second] = 0;
        porProcesar.push(padre);
    }
    

    //mientras queden celdas por procesar
    while(porProcesar.size()>0){
        //toma la celda mas reciente que aun este pendiente de procesar.
        actual = porProcesar.front();
        porProcesar.pop();
        //si el tiempo que tardo la lava en llegar a esta celda es 3, ya no se puede expandir mas por lo que se puede omitir esta celda
        if(tiempo[actual.first][actual.second]==3) continue;
        //---------------IZQUIERDA------------
        //si tiene una celda izquierda y aun no ha sido visitada, introducirla a la lista de celdas por procesar 
        //y actualizar su tiempo de introduccion
        if(esValido(actual.first,actual.second-1)){
            porProcesar.push(make_pair(actual.first,actual.second-1));
            visitado[actual.first][actual.second-1] = true;
            tiempo[actual.first][actual.second-1] = tiempo[actual.first][actual.second]+1;
        }
        //---------------DERECHA--------------
        //si tiene una celda derecha y aun no ha sido visitada, introducirla a la lista de celdas por procesar 
        //y actualizar su tiempo de introduccion
        if(esValido(actual.first,actual.second+1)){
            porProcesar.push(make_pair(actual.first,actual.second+1));
            visitado[actual.first][actual.second+1] = true;
            tiempo[actual.first][actual.second+1] = tiempo[actual.first][actual.second]+1;
        }
        //---------------ARRIBA---------------
        //si tiene una celda arriba y aun no ha sido visitada, introducirla a la lista de celdas por procesar 
        //y actualizar su tiempo de introduccion
        if(esValido(actual.first-1,actual.second)){
            porProcesar.push(make_pair(actual.first-1,actual.second));
            visitado[actual.first-1][actual.second] = true;
            tiempo[actual.first-1][actual.second] = tiempo[actual.first][actual.second]+1;
        }
        //---------------ABAJO---------------
        //si tiene una celda abajo y aun no ha sido visitada, introducirla a la lista de celdas por procesar 
        //y actualizar su tiempo de introduccion
        if(esValido(actual.first+1,actual.second)){
            porProcesar.push(make_pair(actual.first+1,actual.second));
            visitado[actual.first+1][actual.second] = true;
            tiempo[actual.first+1][actual.second] = tiempo[actual.first][actual.second]+1;
        }
    }

}

bool comp(const pair<int,int> a, const pair<int,int> b){
    if(a.first == b.first){
        return a.second<b.second;
    }
    return a.first > b.first;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>filas>>columnas;
    vector<pair<int,int>> padres;
    pair<int,int> actual;
    int bloquesLava;
    cin>>bloquesLava;
    while(bloquesLava-->0){
        cin>>actual.first>>actual.second;
        padres.push_back(actual);
    }
    simular(padres);

    int mejorTiempo = 0;

    for(int f = 0; f<filas; f++){
        for(int c = 0; c<columnas; c++){
            mejorTiempo = max(mejorTiempo,tiempo[f][c]);
        }
    }
    
    if(mejorTiempo==0){
        cout<<-1<<endl;
        return 0;
    }
    vector<pair<int,int>> res;

    for(int f = 0; f<filas; f++){
        for(int c = 0; c<columnas; c++){
            if(tiempo[f][c] == mejorTiempo){
                res.push_back(make_pair(f,c));
            }
        }
    }


    sort(res.begin(),res.end(),comp);
    cout<<res[0].first<<" "<<res[0].second<<endl;
    return 0;
}