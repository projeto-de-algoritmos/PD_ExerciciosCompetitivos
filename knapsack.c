#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int weight;
	int value;
}Item;

long long int max(long long int a,long long int b){
	return (a>b?a:b);
}
void solve(){

	int num_itens,max_weight;
	
	scanf("%d %d",&num_itens,&max_weight);
	
	// alocação dinâmica
	Item *itens = malloc(sizeof(Item)*num_itens);
	
	// leitura dos itens
	for(int i = 0; i < num_itens;i++){
		scanf("%d %d",&itens[i].weight,&itens[i].value);
	}
	
	// alocar a matriz
	long long int matriz[num_itens+1][max_weight+1];

	// preenchimento de zero
	for(int i = 0; i < max_weight+1;i++)
		matriz[0][i] = 0;
	
	// preenchimento de zero
	for(int i = 0; i < num_itens+1;i++)
		matriz[i][0] = 0;
	
	// resolução do problema 

	for(int i = 1; i < num_itens+1;i++){
		for(int wi = 1; wi < max_weight +1;wi++){
			// se o peso do item i for menor que o peso wi só copia o de cima
			//printf("Item %d\nvalor:%d\nPeso :%d\n",i,itens[i-1].value,itens[i-1].weight);
			if(itens[i-1].weight > wi)
				matriz[i][wi] = matriz[i-1][wi];
			else{
				matriz[i][wi] = max(matriz[i-1][wi],itens[i-1].value + matriz[i-1][wi - itens[i-1].weight]);
			}
		}
	}
	
	printf("%lld\n",matriz[num_itens][max_weight]);

}


int main(){
	solve();

	return 0;
	
}
