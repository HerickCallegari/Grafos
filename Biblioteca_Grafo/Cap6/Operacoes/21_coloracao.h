#ifndef COLORACAO_H
#define COLORACAO_H


/*
    Para implementar essa função usei a logica de procurar sempre o maior
    caminho possivel de vertices dentro de um grafo pois na teoria, seria
    necessario N cores para colorir um grafo com um caminho maximo de N
    vertices.
*/

int MaiorCaminho(pDGrafo grafo, pVertice vOrig, pVertice vDest, FuncaoComparacao fc, pDLista visitados) {

    if (fc(vOrig, vDest) == 0) {
        return 0; // encontrou ocaminho
    }
    incluirInfo(visitados, vOrig);

    pNoh aux = vOrig->listaAdjacencias->primeiro;
    while (aux != NULL) {
        pVertice vert = (pVertice) aux->info;
        //printf("\n\nexisteCaminho\nvOrig: %d", *(int*)vOrig->info);
        //printf("\nvDest: %d", *(int*)vDest->info);
        //printf("\nVert: %d", *(int*)vert->info);
        if (buscarNohInfo(visitados, vert, fc) == NULL) {
                return 1 + MaiorCaminho(grafo, vert, vDest, fc, visitados);;
        }
        aux = aux->prox;
    }

    return 1; // não é um caminho possível
}

int coloracao ( pDGrafo grafo, FuncaoComparacao pfc) {
    if ( grafo == NULL)
        return 0;

    pNoh aux, aux2;
    pVertice vert, vert2;

    aux = grafo->listaVertices->primeiro;
    pDLista visitados = criarLista();
    int N = 0;
    while ( aux != NULL ) {
        vert = (pVertice) aux->info;
        aux2 = grafo->listaVertices->primeiro;
        while ( aux2 != NULL) {
            vert2 = (pVertice) aux2->info;
            destruirLista(visitados);
            int NAux = MaiorCaminho(grafo, vert, vert2, pfc, visitados);
            if ( NAux > N )
                N = NAux;
            aux2 = aux2->prox;
        }
        aux = aux->prox;
    }
    return N;
}

#endif
