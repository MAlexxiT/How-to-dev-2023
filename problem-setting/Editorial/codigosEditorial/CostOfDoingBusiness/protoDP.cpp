struct tratado{
    int ini;
    int fin;
    long long int costo;
};
//se iguala a un costo que no se puede obtener
long long int inf = 1000000000000000LL;
vector<tratado> tratados;
long long int solve(int paisActual){
    //llegar hasta el pais cero es gratis, pues 
    if(paisActual == 0) return 0;
    long long int respuesta = inf;
    for(tratado actual: tratados){
        //si el tratado no afecta al pais actual, continua con el siguiente
        if(actual.ini> paisActual) continue;
        if(actual.fin< paisActual) continue;
        //por cada pais en el tratado menor al pais actual
        //igualar la respuesta al minimo costo de cada pais mas el costo del tratado que nos ayudo a acceder a dicho pais
        for(int p = actual.ini; p<paisActual; p++){
            respuesta = min(respuesta, solve(p)+actual.costo)
        }
    }
    return respuesta;
}