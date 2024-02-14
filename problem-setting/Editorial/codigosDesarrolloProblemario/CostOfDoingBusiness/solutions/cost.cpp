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

long long int* arr;
template<class T> class SegmentTree {
private:
	unsigned long long int stHeight, maxNumLeaves;
	T* sTree;
	int origSize;
	void createSTree(int arrLen);
	T valorInex;
	std::function<T(T, T, int)> funcionLlenadora;
	//Nodo segTree, Index inicio , index final
	T fill(int STIndex, int startIndex, int endIndex);
	//Consulta de L a R, nodo STIndex del segtree, rango cubierto actual de startindex a endindex
	T search(int L, int R, int STIndex, int startIndex, int endIndex);
	//valor,indice, nodo del segtree, rango cubierto actual de startindex a endindex
	void updateValue(T value, int valueInd, int STIndex, int startIndex, int endIndex);
public:
	//CONSTRUCTORES
	SegmentTree(int n, T inex, const std::function<T(T, T, int)>& llen);
	//PROCEDIMIENTOS
	T query(int L, int R);
	void update(T value, int valueInd);
	void print();
	void resizeSTree(int arrLen);
	//DESTRUCTOR
	~SegmentTree();
};
template<class T> void SegmentTree<T>::createSTree(int arrLen) {
	//CALCULA LA ALTURA, CANTIDAD DE HOJAS Y EN BASE A ELLO CERA EL ARREGLO
	stHeight = ceil(log2(arrLen));
	maxNumLeaves = (2 * pow(2, stHeight)) - 1;
	sTree = new T[maxNumLeaves];
	//ALMACENA EL TAMANO ORIGINAL DEL ARREGLO
	origSize = arrLen;
}
template<class T> void SegmentTree<T>::resizeSTree(int arrLen) {
	//CALCULA LA ALTURA, CANTIDAD DE HOJAS Y EN BASE A ELLO CERA EL ARREGLO
	stHeight = ceil(log2(arrLen));
	maxNumLeaves = (2 * pow(2, stHeight)) - 1;
	//ALMACENA EL TAMANO ORIGINAL DEL ARREGLO
	origSize = arrLen;
	fill(0, 0, arrLen - 1);
}
template<class T> SegmentTree<T>::SegmentTree(int n, T inex, const std::function<T(T, T, int)>& llen) {
	funcionLlenadora = llen;
	valorInex = inex;
	//CONSTRUYE EL SEGMENT TREE
	createSTree(n);
	//RELLENA EL SEGMENT TREE
	fill(0, 0, n - 1);

}

template<class T> T SegmentTree<T>::fill(int STIndex, int startIndex, int endIndex) {
	//Si el nodo representa un solo elemento regresa el valor de ese elemento
	if (startIndex == endIndex) {
		sTree[STIndex] = arr[startIndex];
		return sTree[STIndex];
	}
	//Caso contrario busca en el hijo izquierdo y en el derecho
	int middleIndex = startIndex + ((endIndex - startIndex) / 2);
	int leftChildIndex = STIndex * 2 + 1;
	int rightChildIndex = STIndex * 2 + 2;
	T leftChild = fill(leftChildIndex, startIndex, middleIndex);
	T rightChild = fill(rightChildIndex, middleIndex + 1, endIndex);
	// para despues alamacenar el menor y devolverlo
	sTree[STIndex] = funcionLlenadora(leftChild, rightChild, log2(endIndex - startIndex + 1));
	return sTree[STIndex];
}

template<class T> T SegmentTree<T>::search(int L, int R, int STIndex, int startIndex, int endIndex) {
	//SI LA SECCION BUSCADA NO CORRESPONDE AL SEGMENTO REGRESAR EL MAXIMO NUMERO POSIBLE
	if (endIndex<L || startIndex>R) {
		return  valorInex;
	}
	//SI LOS INDICES DEL QUERY CUBREN TOTALMENTE AL SEGMENTO REGRESAR EL MINIMO DEL SEGMENTO
	if (L <= startIndex && endIndex <= R) {
		return sTree[STIndex];
	}
	//SI ESTA CUBIERTO PARCIALMENTE POR EL QUERY PREGUNTA A SUS HIJOS
	int middleIndex = startIndex + ((endIndex - startIndex) / 2);
	int leftChildIndex = STIndex * 2 + 1;
	int rightChildIndex = STIndex * 2 + 2;
	T leftChild = search(L, R, leftChildIndex, startIndex, middleIndex);
	T rightChild = search(L, R, rightChildIndex, middleIndex + 1, endIndex);
	//PARA DESPUES DEVOLVER EL MENOR DE SUS HIJOS
	return funcionLlenadora(leftChild, rightChild, log2(endIndex - startIndex + 1));
}
template<class T> T SegmentTree<T>::query(int L, int R) {
	//HACE LA PRIMERA LLAMADA RECURSIVA
	return search(L, R, 0, 0, origSize - 1);
}
template<class T> void SegmentTree<T>::updateValue(T value, int valueInd, int STIndex, int startIndex, int endIndex) {
	//SI EL NODO REPRESENTA UN SOLO ELEMENTO SE IGUALA EL VALOR AL NUEVO
	if (startIndex == endIndex) {
		sTree[STIndex] = value;
		return;
	}
	//CASO CONTRARIO BUSCARA EN SUS HIJOS
	int middleIndex = startIndex + ((endIndex - startIndex) / 2);
	int leftChildIndex = STIndex * 2 + 1;
	int rightChildIndex = STIndex * 2 + 2;
	//REVISA EN CUAL HIJO SE ENCUENTRA EL ELEMENTO PARA DESPUES ACTUALIZAR MEDIANTE RECURSION
	if (startIndex <= valueInd && valueInd <= middleIndex) {
		updateValue(value, valueInd, leftChildIndex, startIndex, middleIndex);
	}
	else {
		updateValue(value, valueInd, rightChildIndex, middleIndex + 1, endIndex);
	}
	//UNA VEZ ACTUALIZADO TOMA EL VALOR MENOR DE LOS DOS HIJOS 
	T LeftChild = sTree[leftChildIndex];
	T RightChild = sTree[rightChildIndex];
	sTree[STIndex] = funcionLlenadora(LeftChild, RightChild, log2(endIndex - startIndex + 1));
}
template<class T> void SegmentTree<T>::update(T value, int valueInd) {
	//PRIMERA LLAMADA RECURSIVA
	updateValue(value, valueInd, 0, 0, origSize - 1);
}
template<class T> void SegmentTree<T>::print() {
	//RECORRE EL SEGTREE E IMPRIME CADA ELEMENTO SEPARADO POR UN ESPACIO
	for (T curr : sTree) {
		cout << curr << " ";
	}
	cout << endl;
}
//DESTRUCTOR
template<class T>  SegmentTree<T>::~SegmentTree() {
	delete[] sTree;
	sTree = nullptr;
	origSize = 0;
	stHeight = 0;
	maxNumLeaves = 0;
}



//lenadora T left, T right, int lvl
long long int bitllena(long long int left, long long int right, int lvl) {
	return min(left,right);
}

struct permiso{
	long long int l,r,w;
};
bool comp( permiso a,permiso b){
    if(a.l == b.l){
        return a.r > b.r;
    }
    return a.l < b.l;
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    long long int  m,c;
    cin>>m;
    
    //arr representa el costo minimo para las distancias en el intervalo cerrado [0-m]
    arr = new long long int[m+1];
    //el costo para cubrir el envio al pais 0 es cero, pues jaime vive ahi
    arr[0] = 0;
    //se inicializa en +infinito 
    for(int i = 1; i<=m; i++){
        arr[i] = 100000000000000000LL;
    }

    permiso aux;
    vector<permiso> tratados;
    int q;
    cin>>q;
    while(q--){
        cin>>aux.l>>aux.r>>aux.w;
        //solo nos interesa si el tratado cubre hasta m
        if(aux.l>m){
            continue;
        }
        aux.r = min(aux.r,m);
        tratados.push_back(aux);
    }

    sort(tratados.begin(),tratados.end(),comp);

	SegmentTree<long long int> st(m+1,100000000000000000LL,bitllena);

	for(permiso el: tratados){
		c = st.query(el.l,el.r)+el.w;
		if(st.query(el.r,el.r)>c){
			st.update(c,el.r);
		}
	}


	long long int res = st.query(m,m);

	cout<<(res==100000000000000000LL?-1:res)<<endl;
    
}
//--------------------EOSOLUTION---------------------------------