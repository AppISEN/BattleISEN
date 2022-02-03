/*****************************************************
*                                                    *
*           Solution par Alexandre Girolt            *
*                                                    *
*****************************************************/

/***
Read data : scanf("%d",data);
Submit answer : printf("%d",answer)
***/
#include <stdlib.h>
#include <stdio.h>

int main(){

	int size;
	float var, somme = 0;

	scanf("%d", &size);

	for(int i = 0; i < size; i++){
		scanf("%f", &var);
		somme += var;
	}

	printf("%f \n", somme/size);




	// Vous pouvez aussi effectuer votre traitement ici après avoir lu toutes les données 
	return 0;
}