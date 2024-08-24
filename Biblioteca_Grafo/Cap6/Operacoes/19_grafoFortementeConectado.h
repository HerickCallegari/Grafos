#ifndef GRAFO_FORTEMENTE_CONECTADO_H
#define GRAFO_FORTEMENTE_CONECTADO_H

int grafoConexo ( pDGrafo grafo, FuncaoComparacao pfc ) {
    if ( grafo == NULL )
        return NULL;

    pNoh aux, aux2;
    pVertice vert, vert2;

    aux = grafo->listaVertices->primeiro;
    aux2 = aux;

     // Vai percorrer o grafo testando se um noh consegue chegar em qualquer outro
    while ( aux != NULL ) {
        vert = (pVertice) aux->info;
        aux2 = grafo->listaVertices->primeiro;
        //printf("\nVertice origem: %d\n", *(int*)vert->info);

        while ( aux2 != NULL ) {
            vert2 = (pVertice) aux2->info;
            //printf("\nVertice destino: %d", *(int*)vert2->info);

            if ( vert == NULL )
                return 0;

            if ( existeCaminho(grafo, vert->info, vert2->info, pfc) == 0)
                return 0;

            aux2 = aux2->prox;
        }

        aux  = aux->prox;
    }
    return 1;
}

#endif
