#ifndef QUANTIDADE_DE_ARESTAS_H
#define QUANTIDADE_DE_ARESTAS_H

int quantidadeDeArestas( pDGrafo grafo, FuncaoComparacao pfc ) {
    pNoh aux = grafo->listaVertices->primeiro;

    pVertice vert;
     // Somatoria das adjacencias
    int somatoria = 0;
    for ( int i = 0; i < grafo->listaVertices->quantidade; i++ ) {
        vert = (pVertice) aux->info;

        somatoria += vert->listaAdjacencias->quantidade;

        aux = aux->prox;
    }
    return somatoria;
}


#endif
