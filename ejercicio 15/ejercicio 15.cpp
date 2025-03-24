#include <iostream>

struct Infraccion
    {
       int tipo;
       int multa;
       char grav;
    };
   
int main() {
   
    int sumaL=0,sumaM=0,sumaG=0,cantG=0;
   
    struct Infraccion inf[5];
   
    for(int i=0;i<5;i++)
    {
       
        printf("Tipo de infraccion: ");
        scanf("%d",&inf[i].tipo);
        printf("Valor de multa: ");
        scanf("%d",&inf[i].multa);
        printf("Gravedad: ");
        scanf("%s",&inf[i].grav);
    }
       
    for(int i=0;i<5;i++)
    {
       
        if(inf[i].grav=='L' || inf[i].grav=='l')
        {
            sumaL=sumaL+inf[i].multa;
        }
        if(inf[i].grav=='M' || inf[i].grav=='m')
        {
            sumaM=sumaM+inf[i].multa;
        }
        if(inf[i].grav=='G' || inf[i].grav=='g')
        {
            sumaG=sumaG+inf[i].multa;
           
            if(inf[i].tipo>=3)
            {
                cantG++;
            }
        }
    }
   
    printf("\nEl valor de las multas tipo L es: %d",sumaL);
    printf("\nEl valor de las multas tipo M es: %d",sumaM);
    printf("\nEl valor de las multas tipo G es: %d",sumaG);
   
    if(cantG>3)
    {
        printf("\nClausurar fábrica");
    }
    return 0;
}
