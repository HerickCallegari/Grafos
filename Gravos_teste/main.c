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
    printf("6. Grafo Bipartido \n");
    printf("7. Grafo Colorido \n");
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
    }else if ( tg == 6 ) {
        int *verticesU = malloc(5 * sizeof(int));  // Conjunto U
        int *verticesV = malloc(5 * sizeof(int));  // Conjunto V

        // Inicializa os v�rtices para U
        verticesU[0] = 1;
        verticesU[1] = 2;
        verticesU[2] = 3;
        verticesU[3] = 4;
        verticesU[4] = 5;

        // Inicializa os v�rtices para V
        verticesV[0] = 6;  // C�pia do v�rtice 1
        verticesV[1] = 7;  // C�pia do v�rtice 2
        verticesV[2] = 8;  // C�pia do v�rtice 3
        verticesV[3] = 9;  // C�pia do v�rtice 4
        verticesV[4] = 10; // C�pia do v�rtice 5

        // Adiciona os v�rtices do conjunto U
        for (int i = 0; i < 5; i++) {
            incluirVertice(grafo, &verticesU[i], comparaVertice);
        }

        // Adiciona os v�rtices do conjunto V
        for (int i = 0; i < 5; i++) {
            incluirVertice(grafo, &verticesV[i], comparaVertice);
        }

        // Adiciona as arestas entre U e V
        incluirAresta(grafo, &verticesU[0], &verticesV[1], comparaVertice); // Aresta (1 -> 7)
        incluirAresta(grafo, &verticesU[1], &verticesV[2], comparaVertice); // Aresta (2 -> 8)
        incluirAresta(grafo, &verticesU[2], &verticesV[3], comparaVertice); // Aresta (3 -> 9)
        incluirAresta(grafo, &verticesU[3], &verticesV[4], comparaVertice); // Aresta (4 -> 10)
        incluirAresta(grafo, &verticesU[4], &verticesV[0], comparaVertice); // Aresta (5 -> 6)
        incluirAresta(grafo, &verticesU[4], &verticesV[1], comparaVertice); // Aresta (5 -> 7)
        incluirAresta(grafo, &verticesU[4], &verticesV[2], comparaVertice); // Aresta (5 -> 8)
    }else if ( tg == 7) {
        int* vertices = malloc(6 * sizeof(int));
        vertices[0] = 1; // A
        vertices[1] = 2; // B
        vertices[2] = 3; // C
        vertices[3] = 4; // D
        vertices[4] = 5; // E
        vertices[5] = 6; // F

        incluirVertice(grafo, &vertices[0], comparaVertice);
        incluirVertice(grafo, &vertices[1], comparaVertice);
        incluirVertice(grafo, &vertices[2], comparaVertice);
        incluirVertice(grafo, &vertices[3], comparaVertice);
        incluirVertice(grafo, &vertices[4], comparaVertice);
        incluirVertice(grafo, &vertices[5], comparaVertice);

        incluirAresta(grafo, &vertices[0], &vertices[1], comparaVertice); // A -> B
        incluirAresta(grafo, &vertices[0], &vertices[2], comparaVertice); // A -> C
        incluirAresta(grafo, &vertices[1], &vertices[3], comparaVertice); // B -> D
        incluirAresta(grafo, &vertices[2], &vertices[3], comparaVertice); // C -> D
        incluirAresta(grafo, &vertices[3], &vertices[4], comparaVertice); // D -> E
        incluirAresta(grafo, &vertices[4], &vertices[5], comparaVertice); // E -> F
        incluirAresta(grafo, &vertices[5], &vertices[0], comparaVertice); // F -> A (ciclo)
    }

        printf("Nenhum grafo selecionado!");
    return grafo;
}

/* ----------------------------- */
void main(){
    pDGrafo grafoNovo;
    pDLista grupoA = criarLista();
    pDLista grupoB = criarLista();

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
        printf(" 12  - Grafo Bipartido. \n");
        printf(" 13  - Grago Conexo. \n");
        printf(" 14  - Grago Cores. \n");
        printf(" 15  - Grago Emparelhados. \n");
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
            printf ("ID do v�rtice : ");
            scanf("%d", pv);
            incluirVertice(grafo, pv, comparaVertice);

            mostrarGrafo(grafo, imprimeVertice);
            getch();
            break;

        case 2 :

            printf ("\nID do v�rtice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do v�rtice destino : ");
            scanf("%d", &vDestino);
            incluirAresta(grafo, &vOrigem, &vDestino, comparaVertice);

            mostrarGrafo(grafo,imprimeVertice);
            getch();
            break;
        case 3 :

             pv = (int *)malloc(sizeof(int));
            printf ("ID do v�rtice : ");
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

            printf ("\nID do v�rtice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do v�rtice destino : ");
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
            printf ("\nID do v�rtice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do v�rtice destino : ");
            scanf("%d", &vDestino);

            int result = existeCaminho(grafo, &vOrigem, &vDestino, comparaVertice);
            // existe um caminho
            if (result != 0)
                printf("Existe caminho!");
            else
                printf("N�o existe caminho!");

            getch();
            break;
        case 9 :
            printf ("\nID do v�rtice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do v�rtice destino : ");
            scanf("%d", &vDestino);

            pDLista caminho = getCaminho(grafo, &vOrigem, &vDestino, comparaVertice, alocaInfoVertice);
            if (caminho->quantidade > 0){
                printf("\n Existe um caminho: ");
                imprimirLista(caminho, imprimeVerticeSemAdjacencias);
            }
            else
                printf("\n *** N�O existe um caminho. *** ");

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
        case 12:
            destruirLista(grupoA);
            destruirLista(grupoB);
            if ( grafoBipartido(grafo, comparaVertice, grupoA, grupoB) == 1)
                printf("\nGrafo Bipartido.");
            else
                printf("\nGrafo nao e Bipartido.");

            printf("\nGrupo A:");
            imprimirLista(grupoA, imprimeVerticeSemAdjacencias);
            printf("\nGrupo B:");
            imprimirLista(grupoB, imprimeVerticeSemAdjacencias);

            getch();
            break;
        case 13:
            if ( grafoConexo(grafo, comparaVertice) == 1)
                printf("O grafo e conexo.");
            else
                printf("O grafo nao e conexo.");

            getch();
            break;
        case 14:
            printf("Quantidade de Cores necessarias: %d", coloracao(grafo, comparaVertice));
            getch();
            break;
        case 15:
            if ( grafoConexo(grafo, comparaVertice) == 1)
                printf("O grafo e conexo.");
            else
                printf("O grafo nao e conexo.");

            getch();
            break;
        }

    }while (opcao != 99);

}


