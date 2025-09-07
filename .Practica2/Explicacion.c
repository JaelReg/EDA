#include <stdio.h>



int main(void) {

    int numeros[4] = {5, 10, 15, 20}; //Se crea un arreglo de 4 enteros.

    int *p = numeros;



    printf("1) numeros[2] = %d\n", numeros[2]); //Imprime el valor del tercer elemento del arreglo.

    printf("2) *(p+2) = %d\n", *(p+2)); //p apunta al inicio (numeros[0]). p + 2 apunta a numeros[2]. *(p+2) obtiene el valor almacenado en numeros[2]. Ese valor es 15. 

    printf("3) *p = %d\n", *p); //*p significa “el valor apuntado por p”. Como p apunta a numeros[0], imprime 5



    p++; //Mueve el apuntador una posición hacia adelante en memoria.

    printf("4) *p = %d\n", *p); //Ahora *p da el valor en numeros[1]. Ese valor es 10.



    return 0;

}