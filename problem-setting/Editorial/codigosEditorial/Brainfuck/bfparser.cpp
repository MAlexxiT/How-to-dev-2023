//supongamos que la lectura de programa y longitud fueron hechas.
//tambien que fue creado un arreglo global arr con todas sus posiciones inicializadas con 32
string programa;
int longitud;
//el puntero debe iniciar en la primera celda de memoria
int puntero = 0;
for(char instruccion: programa){
    //mueve el puntero a la izquierda.
    if(instruccion == '<'){
        puntero--;
        //si el puntero es menor a cero
        //significa que se movio a la izquierda desde la posicion cero
        if(puntero<0){
            puntero = longitud -1;
        }
    }
    //mueve el puntero a la derecha.
    if(instruccion == '>'){
        puntero++;
        //si el puntero es mayor o igual a longitud
        //significa que se movio a la derecha desde la posicion mas derecha posible
        if(puntero>= longitud){
            puntero = 0;
        }
    }
    //Aumenta el valor de la casilla.
    if(instruccion == '+'){
        arr[puntero]++;
        //si es mayor al valor maximo permitido, regresar a 32
        if(arr[puntero] > 126){
            arr[puntero] = 32;
        }
    }
    //Disminuye el valor de la casilla.
    if(instruccion == '-'){
        arr[puntero]--;
        //si es menor al valor minimo permitido, regresar a 126
        if(arr[puntero] < 32){
            arr[puntero] = 126;
        }
    }
    //Imprime el valor debajo del puntero.
    if(instruccion == '.'){
        //Como la tabla del problema coincide con la tabla ascii
        //podemos hacer la conversion directamente con un casteo de la forma
        cout<< (char)arr[puntero];
    }
}