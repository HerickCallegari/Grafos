#ifndef GRAFO_FORTEMENTE_CONECTADO_H
#define GRAFO_FORTEMENTE_CONECTADO_H

int grafoConexo(pDGrafo grafo, FuncaoComparacao pfc) {
    if (grafo == NULL)
        return 0;

    pNoh aux, aux2;
    pVertice vert, vert2;

    aux = grafo->listaVertices->primeiro;

    // Vai percorrer o grafo testando se um nó consegue chegar em qualquer outro
    while (aux != NULL) {
        vert = (pVertice) aux->info;
        aux2 = grafo->listaVertices->primeiro;

        while (aux2 != NULL) {
            vert2 = (pVertice) aux2->info;

            if (vert == NULL)
                return 0;

            //printf("\nGrafoConexo\naux1: %d", *(int*)vert->info);
            //printf("\naux2: %d", *(int*)vert2->info);

            if (existeCaminho(grafo, vert->info, vert2->info, pfc) == 0)
                return 0;
            //getch();
            aux2 = aux2->prox;
        }

        aux = aux->prox;
    }
    return 1;
}

#endif
