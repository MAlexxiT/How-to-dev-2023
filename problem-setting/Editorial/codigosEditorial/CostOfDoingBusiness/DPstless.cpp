struct tratado{
    int ini;
    int fin;
    long long int costo;
};
//se iguala a un costo que no se puede obtener
long long int inf = 1000000000000000LL;
//todo inicializado en inf
long long int dp[100001];
vector<tratado> tratados;
long long int solve(int paisActual){
    //llegar hasta el pais cero es gratis, pues 
    if(paisActual == 0) return 0;
    //si esta instancia de la funcion ya fue calculada, retorna su resultado
    if(dp[paisActual]!= inf) return dp[paisActual];
    long long int respuesta = inf;
    for(tratado actual: tratados){
        //si el paisActual no es el fin del tratado actual, no hagas nada 
        if(actual.fin != paisActual) continue;
        //por cada pais en el tratado menor al pais actual
        //igualar la respuesta al minimo costo de cada pais mas el costo del tratado que nos ayudo a acceder a dicho pais
        for(int p = actual.ini; p<paisActual; p++){
            respuesta = min(respuesta, solve(p)+actual.costo)
        }
    }
    dp[paisActual] = respuesta;
    return respuesta;
}