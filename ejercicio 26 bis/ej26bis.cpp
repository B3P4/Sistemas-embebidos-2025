#include <iostream>

struct Contenedor
    {
	char iden;
 	int peso;
 	int puerto;
    };

void pedirDatos(struct Contenedor *contenedores)
{
    printf("Identificion del contenedor: ");
    scanf("%s",&contenedores->iden);
    printf("Peso del contenedor (kg): ");
    scanf("%d",&contenedores->peso);
    printf("Puerto de arribo: ");
    scanf("%d",&contenedores->puerto);
}

int main() {
    int pesoTotal=0, identificacionMayor=0, puerto1=0, puerto2=0, puerto3=0;

    struct Contenedor contenedores[5];
 
    for(int i=0;i<5;i++)
    {
        pedirDatos(&contenedores[i]);
    }
    for(int i=0;i<5;i++)
    {
        pesoTotal+=contenedores[i].peso;
        
        if(contenedores[i].peso > contenedores[identificacionMayor].peso)
	    {
            identificacionMayor=i;
        }
	 
        if(contenedores[i].puerto==1)
	   {
	   		puerto1++;
	   }
	   
	   if(contenedores[i].puerto==2)
	   {
	  		puerto2++;
	   }
	   if(contenedores[i].puerto==3)
	   {
	   		puerto3++;
	   }
    }

    printf("\nEl peso total que el buque debe trasladar es: %d",pesoTotal);
    printf("\nEl contenedor mas pesado es: %c",contenedores[identificacionMayor].iden);
    printf("\nCantidad de contenedores a trasladar al puerto 1: %d",puerto1);
    printf("\nCantidad de contenedores a trasladar al puerto 2: %d",puerto2);
    printf("\nCantidad de contenedores a trasladar al puerto 3: %d",puerto3);

return 0;
}
