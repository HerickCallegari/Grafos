#include "../../Cap3/Utils.h"
#ifndef EXCLUIR_VERTICE_H
#define EXCLUIR_VERTICE_H

/* --------------------------- */
int excluirVertice(pDGrafo grafo, void* info, FuncaoComparacao fc){

    pVertice verticeInfo = buscarVertice(grafo, info, fc);

    if ( verticeInfo == NULL )
        return 0;

    pNoh aux = grafo->listaVertices->primeiro;

     // Exclui todas as arestas que contem info
    pVertice verticeAux;
    while (aux != grafo->listaVertices->ultimo) {
        verticeAux = (pVertice) aux->info;
        if ( buscarNohInfo(verticeAux->listaAdjacencias, verticeInfo, fc) != NULL)
            excluirAresta(grafo, verticeAux->info, info, fc);

        aux = aux->prox;
    }
    verticeAux = (pVertice) aux->info;
    if ( buscarNohInfo(verticeAux->listaAdjacencias, verticeInfo, fc) != NULL)
        excluirAresta(grafo, verticeAux->info, info, fc);

     // Retira info do eixo de vertices principal
    excluirInfo(grafo->listaVertices, verticeInfo, fc);
     // Retira todas as arestas que o vertice info tinha
    destruirLista(verticeInfo->listaAdjacencias);

     // Aterra o vertice
    verticeInfo->info = NULL;

     // Libera Memoria
    free(verticeInfo->grau);
    free(verticeInfo->info);
    free(verticeInfo->listaAdjacencias);

    return 1;
}
#endif
