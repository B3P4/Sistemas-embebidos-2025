#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int A,B;
	printf("Ingrese un numero A: ");
	scanf("%d",&A);
	
	printf("Ingrese un numero B: ");
	scanf("%d",&B);
	
	printf("La suma de sus numeros es: %d\n",A+B);
	printf("La resta de sus numeros es: %d\n",A-B);
	printf("El producto de sus numeros es: %d",A*B);
	
	getch();
	return 0;
}
