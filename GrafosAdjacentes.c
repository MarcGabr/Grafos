/* MARCOS GABRIEL PEREIRA ARUJO
   Nºm: 2017111024
   GRAFOS DE ADJACENCIA
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct grafo{
    int n;
    int **mat;
}Grafo;
void criar_grafo(Grafo *g, int n){
    int i;
    g->mat = (int*)malloc(sizeof(int)*n);
    g->n=n;
    for(int i=0;i<n;i++){
            g->mat[i] = (int*) malloc(sizeof(int)*n);
            for(int j=0; j<n;j++){
                    g->mat[i][j]=0;
            }
    }
}
void destroi(Grafo *g){
    int i;
    for(i=1;i<g->n;i++){
        free(g->mat[i]);
    }
}
void insere_aresta(Grafo *g, int v1, int v2){

//if(v1>v2){
    g->mat[v1-1][v2-1]=1;
//}
//else {
        g->mat[v2-1][v1-1]=1;
//}

}
int verifica_aresta(Grafo *g, int v1, int v2){
    return v1>v2 ? g->mat[v1-1][v2-1]: g->mat[v2-1][v1-1];
}
void remove_aresta(Grafo *g, int v1, int v2) {
    if (v1 > v2)g->mat[v1-1][v2-1] = 0;
    else g->mat[v2-1][v1-1] = 0;
}
void imprime(Grafo *g){
    printf("   ");for(int i=1; i<=g->n;i++)printf(" %d",i);
    printf("\n");
    for(int i=0;i<g->n;i++){
            printf("%2d ",i+1);
            for(int j=0; j<g->n;j++){
                printf("%2d",g->mat[i][j]);
            }
        printf("\n");
    }
}
void textoinicial(Grafo *g){
    int vertices;
    printf("Vamos criar um grafo?\n Digite a quantidade de vertices:\n");
        scanf("%d",&vertices);
        criar_grafo(&*g,vertices);
}
int main()
{
    Grafo g;
    int opcao;
        textoinicial(&g);
    do{int valor1,valor2;
    printf("Oque faremos agora?\n 1- inserir aresta no grafo, 2- para imprimir o grafo, 3- remover aresta grafo, 0- para Sair \n");
    scanf("%d",&opcao);
     if(opcao==1){
        printf("Digite dois numeros: \n");
        scanf("%d %d", &valor1,&valor2);
        int verifica=verifica_aresta(&g,valor1,valor2);
        if(verifica==0){
            insere_aresta(&g,valor1,valor2);
        }else{
            printf("Aresta ja inserida\n");
        }
     }else if(opcao==2){
        imprime(&g);
     }else if(opcao==3){
        printf("Digite dois numeros: \n");
        scanf("%d %d", &valor1,&valor2);
        int verifica=verifica_aresta(&g,valor1,valor2);

        if(verifica!=0){
            remove_aresta(&g,valor1,valor2);
        }else{
            printf("Aresta nao inserida\n");
        }
     }else printf("Saindo...\n");

    }while(opcao !=0);

    return 0;
}
