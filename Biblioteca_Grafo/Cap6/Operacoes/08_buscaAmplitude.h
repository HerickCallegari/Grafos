#ifndef BUSCA_AMPLITUDE_H
#define BUSCA_AMPLITUDE_H

/* --------------------------- */
void buscaAmplitudeRecursivo (pDGrafo grafo, pVertice vert, FuncaoComparacao fc, FuncaoImpressao fi, pDLista Visitados) {

    if ( vert == NULL )
        return;

    fi(vert);

    incluirInfo(Visitados, vert);

    pNoh aux = vert->listaAdjacencias->primeiro;

    pDLista pendentes = criarLista();

     // Cria a Lista de Vertices pendentes a serem visitados
    for (int i = 0; i < vert->listaAdjacencias->quantidade; i++) {
        if ( buscarNohInfo(Visitados, aux->info, fc) == NULL )
            incluirInfo(pendentes,aux->info);
        aux = aux->prox;
    }

    aux = pendentes->primeiro;

    for ( int i = 0; i < pendentes->quantidade; i++ ) {
        if ( buscarNohInfo(Visitados, aux->info, fc) == NULL )
            buscaAmplitudeRecursivo(grafo, aux->info, fc, fi, Visitados);

        aux = aux->prox;
    }
    destruirLista(pendentes);
    free(pendentes);
    return;
}
/* --------------------------- */
void buscaAmplitude(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi){

     // Caso o grafo nao exista
    if ( grafo == NULL )
        return;

    pDLista visitados = criarLista();

     // Primeiro Noh da lista principal
    pNoh aux = grafo->listaVertices->primeiro;
    pVertice vert = aux->info;

    buscaAmplitudeRecursivo(grafo, vert, fc, fi, visitados);
}
#endif
