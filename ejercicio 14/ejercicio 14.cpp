#include <iostream>

int main() 
{
    int numero, sumamay=0 ,sumamen=0,cantmay=0;
    for(int i=0;i<5;i++)
    {
        printf("Ingrese un numero\n--->");
        scanf("%d",&numero);
        if(numero >100)
        {
            sumamay=sumamay+numero;
            cantmay++;
        }
        if(numero<-10)
        {
            sumamen=sumamen+numero;
        }
    }
   
    printf("Suma de los menores a -10: %d\n",sumamen);
    printf("Promedio de los mayores a 100: %.2f",(float)sumamay/cantmay);
   
   
    return 0;
}
