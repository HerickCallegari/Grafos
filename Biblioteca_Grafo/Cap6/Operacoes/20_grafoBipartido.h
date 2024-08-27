#ifndef GRAFO_BIPARTIDO_H
#define GRAFO_BIPARTIDO_H

void grafoBipartidoRecursivo( pDGrafo grafo, pVertice vert, pDLista grupoA, pDLista grupoB, FuncaoComparacao fc) {
    if ( grafo == NULL )
        return;

    if ( vert == NULL )
        return;


     // Inclui o vertice em analise no grupo correto
    if ( buscarNohInfo(grupoA, vert, fc) == NULL && buscarNohInfo(grupoB, vert, fc) == NULL) {
        incluirInfo(grupoA, vert);
    }

    pDLista Conectados = criarLista();

    pNoh aux = vert->listaAdjacencias->primeiro;
    pVertice auxVert;

     // Popula a lista de grafos adjacentes ao vertice
     while ( aux != NULL ) {
        auxVert = (pVertice) aux->info;
        //printf("auxVert: %d", *(int*)auxVert->info);
        if ( buscarNohInfo(grupoA, auxVert, fc) == NULL && buscarNohInfo(grupoB, auxVert, fc) == NULL)
            incluirInfo(Conectados, auxVert);

        aux = aux->prox;
     }
     aux = buscarVerticesIncidentes(grafo, vert, fc)->primeiro;
      // Popula a lista de vertices conectados ao vertice em analise
     while ( aux != NULL ) {
        auxVert = (pVertice) aux->info;
        if ( buscarNohInfo(grupoA, vert, fc) == NULL && buscarNohInfo(grupoB, vert, fc) == NULL)
            incluirInfo(Conectados, auxVert);
        aux = aux->prox;
     }

    aux = Conectados->primeiro;

     // Coloca Vertices conectados ao vertice em analise no respetivo
     // grupo e entao chama novamente a funcao recursiva invertendo a ordem dos grupos
    while ( aux != NULL ) {
    auxVert = (pVertice) aux->info;
        if ( buscarNohInfo(grupoA, auxVert, fc) == NULL && buscarNohInfo(grupoB, auxVert, fc) == NULL) {
            incluirInfo(grupoB, auxVert);
            grafoBipartidoRecursivo(grafo, auxVert, grupoB, grupoA, fc);
        }

        aux = aux->prox;
     }



}

int grafoBipartido( pDGrafo grafo, FuncaoComparacao fc, pDLista grupoA, pDLista grupoB) {
    if ( grafo == NULL || grupoA == NULL || grupoB == NULL)
        return 0;

    pNoh aux = grafo->listaVertices->primeiro;
    pVertice vert;
     // Chama a funcao para todos os vertices do grafo, pois é possivel
     // que algum vertice nao seja acessivel apenas atraves das adjacencias
    while ( aux != NULL ) {
        vert = (pVertice) aux->info;

        if ( vert->listaAdjacencias->quantidade == 0 && buscarVerticesIncidentes(grafo, vert, fc) == 0) {
            return 0;
        }

        grafoBipartidoRecursivo(grafo, vert, grupoA, grupoB, fc);
        aux = aux->prox;
    }

     // Garante que todos os vertices pertencem a pelo menos 1 grupo
    while ( aux != NULL ) {
        vert = (pVertice) aux->info;

        if ( buscarNohInfo(grupoA, vert, fc) == 0 && buscarNohInfo(grupoB, vert, fc) == 0) {
            return 0;
        }

        aux = aux->prox;
    }

    aux = grupoA->primeiro;
    pNoh aux2;
    pVertice vert2;

     // Verifica se nenhum Vertice do grupo A esta conectado entre si
    while ( aux != NULL ) {
        vert = (pVertice) aux->info;

        aux2 = grupoA->primeiro;
        while ( aux2 != NULL ) {
            vert2 = (pVertice) aux2->info;

            if ( fc(vert2, vert) != 0 && buscarNohInfo(vert->listaAdjacencias, vert2, fc) != NULL ) {
                return 0;
            }

            aux2 = aux2->prox;
        }

        aux = aux->prox;
    }

     // Verifica se nenhum Vertice do grupo B esta conectado entre si
    aux = grupoB->primeiro;
    while ( aux != NULL ) {
        vert = (pVertice) aux->info;

        aux2 = grupoB->primeiro;
        while ( aux2 != NULL ) {
            vert2 = (pVertice) aux2->info;

            if ( fc(vert2, vert) != 0 && buscarNohInfo(vert->listaAdjacencias, vert2, fc) != NULL ) {
                return 0;
            }

            aux2 = aux2->prox;
        }

        aux = aux->prox;
    }

    return 1;
}

#endif
