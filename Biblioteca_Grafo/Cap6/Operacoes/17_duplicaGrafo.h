#ifndef DUPLICA_GRAFO_H
#define DUPLICA_GRAFO_H

pDGrafo duplicarGrafo(pDGrafo grafo, FuncaoComparacao pfc) {

    if ( grafo == NULL || grafo->listaVertices == NULL )
        return NULL;

    pDGrafo grafoNovo = criarGrafo();

    pNoh aux = grafo->listaVertices->primeiro;
    pVertice auxVertice;
    pVertice auxAresta;
    printf("aqui");
     // Adciona todos os vertices do grafo
    for( int i = 0; i < grafo->listaVertices->quantidade; i++ ) {

        if ( aux == NULL )
            break;

        pVertice auxVertice = (pVertice)aux->info;

        if ( auxVertice == NULL )
            break;

        incluirVertice(grafoNovo, auxVertice->info, pfc);
        aux = aux->prox;
    }

     // Adciona todas as arestas
    aux = grafo->listaVertices->primeiro;
    pNoh aux2;
    for ( int i = 0; i < grafo->listaVertices; i++ ) {

        if ( aux == NULL )
            break;

        pVertice auxVertice = (pVertice)aux->info;

        if ( auxVertice == NULL )
            break;

        aux2 = auxVertice->listaAdjacencias->primeiro;
        for ( int j = 0;  j < auxVertice->listaAdjacencias->quantidade; j++ ) {

            if ( aux2 == NULL )
                break;

            auxAresta = (pVertice)aux2->info;

            if ( auxAresta == NULL )
                break;

            incluirAresta(grafoNovo, auxVertice->info, auxAresta->info, pfc);
            aux2 = aux2->prox;
        }

        aux = aux->prox;
    }

    return grafoNovo;
}
#endif
