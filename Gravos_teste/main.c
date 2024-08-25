#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#include "../Biblioteca_Grafo/Cap6/Grafo.h"
#include "../Biblioteca_Grafo/Cap3/Utils.h"




int comparaVertice(void *info1, void *info2){

    pVertice v1 = (pVertice) info1;
    pVertice v2 = (pVertice) info2;

    int *id1 = (int *) v1->info;
    int *id2 = (int *) v2->info;

    return *id2 - *id1;
}

/* ----------------------------- */
void imprimeAdjacencia(void *info1){
    pVertice v = (pVertice) info1;
    printf("%d - " , *((int *)(v->info)));
}

/* ----------------------------- */
void imprimeVertice(void *info1){
    pVertice v = (pVertice) info1;
    printf("\nVertice %d - Adjacencias [", *((int *)v->info));

    imprimirLista(v->listaAdjacencias, imprimeAdjacencia);
    printf("]\n");
}

/* ----------------------------- */
void imprimeVerticeSemAdjacencias(void *info1){
    pVertice v = (pVertice) info1;
    printf("\nVertice %d - ", *((int *)v->info));
}

/* ---------------------------------------- */
void* alocaInfoVertice(void *info){
   pVertice pv = (pVertice) malloc(sizeof(Vertice));
   pv->info = alocaInfoInt(((pVertice)info)->info);
   return pv;
}

/* ----------------------------- */

pDGrafo grafoPadrao() {
    pDGrafo grafo = criarGrafo();
    int tg;
    int *vertices;
    printf("Escolha o tipo de grafo:\n");
    printf("1. Grafo Inicial\n");
    printf("2. Grafo Normal\n");
    printf("3. Grafo nao Euleriano \n");
    printf("4. Grafo Euleriano \n");
    printf("5. Grafo Hamiltoniano \n");
    scanf ("%d", &tg);
    if ( tg == 1) {
            vertices = malloc(5 * sizeof(int));
            vertices[0] = 1;
            vertices[1] = 2;
            vertices[2] = 3;
            vertices[3] = 4;
            vertices[4] = 5;

            incluirVertice(grafo, &vertices[0], comparaVertice);
            incluirVertice(grafo, &vertices[1], comparaVertice);
            incluirVertice(grafo, &vertices[2], comparaVertice);
            incluirVertice(grafo, &vertices[3], comparaVertice);
            incluirVertice(grafo, &vertices[4], comparaVertice);

            incluirAresta(grafo, &vertices[0], &vertices[1], comparaVertice);
            incluirAresta(grafo, &vertices[1], &vertices[3], comparaVertice);
            incluirAresta(grafo, &vertices[2], &vertices[3], comparaVertice);
            incluirAresta(grafo, &vertices[2], &vertices[4], comparaVertice);
            incluirAresta(grafo, &vertices[3], &vertices[4], comparaVertice);
            incluirAresta(grafo, &vertices[4], &vertices[1], comparaVertice);
    } else if ( tg == 2) {
            vertices = malloc(6 * sizeof(int));
            vertices[0] = 1;
            vertices[1] = 2;
            vertices[2] = 4;
            vertices[3] = 5;
            vertices[4] = 6;
            vertices[5] = 7;

            incluirVertice(grafo, &vertices[0], comparaVertice);
            incluirVertice(grafo, &vertices[1], comparaVertice);
            incluirVertice(grafo, &vertices[2], comparaVertice);
            incluirVertice(grafo, &vertices[3], comparaVertice);
            incluirVertice(grafo, &vertices[4], comparaVertice);
            incluirVertice(grafo, &vertices[5], comparaVertice);

            incluirAresta(grafo, &vertices[0], &vertices[1], comparaVertice);

            incluirAresta(grafo, &vertices[1], &vertices[2], comparaVertice);
            incluirAresta(grafo, &vertices[1], &vertices[3], comparaVertice);

            incluirAresta(grafo, &vertices[2], &vertices[4], comparaVertice);

            incluirAresta(grafo, &vertices[4], &vertices[1], comparaVertice);
            incluirAresta(grafo, &vertices[4], &vertices[5], comparaVertice);

            incluirAresta(grafo, &vertices[5], &vertices[4], comparaVertice);
            incluirAresta(grafo, &vertices[5], &vertices[3], comparaVertice);

    } else if ( tg == 3 ) {
            vertices = malloc(4 * sizeof(int));
            vertices[0] = 1;
            vertices[1] = 2;
            vertices[2] = 3;
            vertices[3] = 4;
            incluirVertice(grafo, &vertices[0], comparaVertice);
            incluirVertice(grafo, &vertices[1], comparaVertice);
            incluirVertice(grafo, &vertices[2], comparaVertice);
            incluirVertice(grafo, &vertices[3], comparaVertice);

            incluirAresta(grafo, &vertices[0], &vertices[1], comparaVertice);
            incluirAresta(grafo, &vertices[0], &vertices[2], comparaVertice);

            incluirAresta(grafo, &vertices[1], &vertices[2], comparaVertice);
            incluirAresta(grafo, &vertices[1], &vertices[3], comparaVertice);

            incluirAresta(grafo, &vertices[2], &vertices[3], comparaVertice);
            incluirAresta(grafo, &vertices[2], &vertices[1], comparaVertice);

            incluirAresta(grafo, &vertices[3], &vertices[0], comparaVertice);
    } else if ( tg == 4) {
        vertices = malloc(4 * sizeof(int));
        vertices[0] = 1;
        vertices[1] = 2;
        vertices[2] = 3;
        vertices[3] = 4;

        incluirVertice(grafo, &vertices[0], comparaVertice);
        incluirVertice(grafo, &vertices[1], comparaVertice);
        incluirVertice(grafo, &vertices[2], comparaVertice);
        incluirVertice(grafo, &vertices[3], comparaVertice);

        incluirAresta(grafo, &vertices[0], &vertices[1], comparaVertice); // Aresta (1, 2)
        incluirAresta(grafo, &vertices[1], &vertices[2], comparaVertice); // Aresta (2, 3)
        incluirAresta(grafo, &vertices[2], &vertices[3], comparaVertice); // Aresta (3, 4)
        incluirAresta(grafo, &vertices[3], &vertices[0], comparaVertice); // Aresta (4, 1)
    }else if ( tg == 5) {
        vertices = malloc(5 * sizeof(int));
        vertices[0] = 1;
        vertices[1] = 2;
        vertices[2] = 3;
        vertices[3] = 4;
        vertices[4] = 5;

        incluirVertice(grafo, &vertices[0], comparaVertice);
        incluirVertice(grafo, &vertices[1], comparaVertice);
        incluirVertice(grafo, &vertices[2], comparaVertice);
        incluirVertice(grafo, &vertices[3], comparaVertice);
        incluirVertice(grafo, &vertices[4], comparaVertice);

        incluirAresta(grafo, &vertices[0], &vertices[1], comparaVertice); // Aresta (1, 2)
        incluirAresta(grafo, &vertices[1], &vertices[2], comparaVertice); // Aresta (2, 3)
        incluirAresta(grafo, &vertices[2], &vertices[3], comparaVertice); // Aresta (3, 4)
        incluirAresta(grafo, &vertices[3], &vertices[4], comparaVertice); // Aresta (4, 5)
        incluirAresta(grafo, &vertices[4], &vertices[0], comparaVertice); // Aresta (5, 1)
        incluirAresta(grafo, &vertices[4], &vertices[1], comparaVertice); // Aresta (5, 2)
        incluirAresta(grafo, &vertices[4], &vertices[2], comparaVertice); // Aresta (5, 3)
    }else
        printf("Nenhum grafo selecionado!");
    return grafo;
}

/* ----------------------------- */
void main(){
    pDGrafo grafoNovo;

    int opcao, vOrigem, vDestino;
    int *pv;

    pDGrafo grafo = criarGrafo();

    do{
        system("cls");
        printf("----------- GRAFO ----------");
        mostrarGrafo(grafo, imprimeVertice);
        printf("----------------------------");

        printf("\n  0  - Criar grafo \n");
        printf("  1  - Incluir Vertice \n");
        printf("  2  - Incluir Aresta \n");
        printf("  3  - Excluir Vertice \n");
        printf("  4  - Excluir Aresta \n");
        printf("  5  - Mostrar grafo \n");
        printf("  6  - Busca em profundidade \n");
        printf("  7  - Busca em amplitude \n");
        printf("  8  - Existe caminho?  \n");
        printf("  9  - Encontra caminho \n");
        printf(" 10  - Caminho Euleriano \n");
        printf(" 11  - Caminho Hamiltoniano \n");
        printf("99 - Sair \n");

        scanf ("%d", &opcao);

        switch (opcao){

         case 0 :
            grafo = grafoPadrao();
            mostrarGrafo(grafo, imprimeVertice);
            getch();
            break;

        case 1 :

            pv = (int *)malloc(sizeof(int));
            printf ("ID do vértice : ");
            scanf("%d", pv);
            incluirVertice(grafo, pv, comparaVertice);

            mostrarGrafo(grafo, imprimeVertice);
            getch();
            break;

        case 2 :

            printf ("\nID do vértice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do vértice destino : ");
            scanf("%d", &vDestino);
            incluirAresta(grafo, &vOrigem, &vDestino, comparaVertice);

            mostrarGrafo(grafo,imprimeVertice);
            getch();
            break;
        case 3 :

             pv = (int *)malloc(sizeof(int));
            printf ("ID do vértice : ");
            scanf("%d", pv);
            int excluiu3 = excluirVertice(grafo, pv, comparaVertice);

            if ( excluiu3 == 1 )
                printf("Excluiu Vertice!");
            else
                printf("Nao foi possivel excluir o vertice");

            mostrarGrafo(grafo,imprimeVertice);
            getch();
            break;

        case 4 :

            printf ("\nID do vértice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do vértice destino : ");
            scanf("%d", &vDestino);
            int excluiu4 = excluirAresta(grafo, &vOrigem, &vDestino, comparaVertice);

            if ( excluiu4 == 1 )
                printf("\nAresta Excluida com sucesso!\n");
            else
                printf("\nNao foi possivel excluir esta aresta.\n");
            mostrarGrafo(grafo,imprimeVertice);
            getch();
            break;

        case 5 :
            mostrarGrafo(grafo, imprimeVertice);
            getch();
            break;

        case 6 :
            buscaEmProfundidade(grafo, comparaVertice, imprimeVerticeSemAdjacencias);
            getch();
            break;
        case 7 :
            buscaAmplitude(grafo, comparaVertice, imprimeVerticeSemAdjacencias);
            getch();
            break;

        case 8 :
            printf ("\nID do vértice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do vértice destino : ");
            scanf("%d", &vDestino);

            int result = existeCaminho(grafo, &vOrigem, &vDestino, comparaVertice);
            // existe um caminho
            if (result != 0)
                printf("Existe caminho!");
            else
                printf("Não existe caminho!");

            getch();
            break;
        case 9 :
            printf ("\nID do vértice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do vértice destino : ");
            scanf("%d", &vDestino);

            pDLista caminho = getCaminho(grafo, &vOrigem, &vDestino, comparaVertice, alocaInfoVertice);
            if (caminho->quantidade > 0){
                printf("\n Existe um caminho: ");
                imprimirLista(caminho, imprimeVerticeSemAdjacencias);
            }
            else
                printf("\n *** NÃO existe um caminho. *** ");

            getch();
            break;
        case 10 :

            if ( existeCaminhoEuleriano(grafo, comparaVertice) == 1 )
                printf("Existe caminho Euleriano!");
            else
                printf("Nao Existe caminho Euleriano.");

            getch();
            break;
        case 11 :
            if ( existeCaminhoHamiltoniano(grafo, comparaVertice) == 1 )
                printf("Existe caminho Hamiltoniano!");
            else
                printf("Nao Existe caminho Hamiltoniano.");

            getch();
            break;
        }

    }while (opcao != 99);

}


