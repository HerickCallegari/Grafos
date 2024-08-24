#ifndef EXISTE_CAMINHO_H
#define EXISTE_CAMINHO_H

/* ----------------------------------------------------------------
A estrat�gia empregada para a verifica��o de exist�ncia do caminho
parte do v�rtice de destino e procede com a busca pelos v�rtices
que incidem sobre este, e assim sucessivamente, at� o momento
que um dos v�rtices incidentes seja o v�rtice de origem.
Resumindo, a busca � feita no sentido do v�rtice de destino para o
v�rtice de origem.
-------------------------------------------------------------------*/
int existeCaminhoRecursivo(pDGrafo grafo, pVertice vOrig, pVertice vDest, FuncaoComparacao fc, pDLista visitados) {

    if (fc(vOrig, vDest) == 0) {
        return 1; // encontrou ocaminho
    }
    incluirInfo(visitados, vOrig);

    pNoh aux = vOrig->listaAdjacencias->primeiro;
    while (aux != NULL) {
        pVertice vert = (pVertice) aux->info;
        //printf("\n\nexisteCaminho\nvOrig: %d", *(int*)vOrig->info);
        //printf("\nvDest: %d", *(int*)vDest->info);
        //printf("\nVert: %d", *(int*)vert->info);
        if (buscarNohInfo(visitados, vert, fc) == NULL) {
            if (existeCaminhoRecursivo(grafo, vert, vDest, fc, visitados) == 1) {
                return 1;

            }
        }
        aux = aux->prox;
    }

    return 0; // n�o � um caminho poss�vel
}

int existeCaminho(pDGrafo grafo, void *idOrig, void *idDest, FuncaoComparacao fc) {
    pVertice vOrigem = buscarVertice(grafo, idOrig, fc);
    pVertice vDestino = buscarVertice(grafo, idDest, fc);

    if (vOrigem == NULL || vDestino == NULL) {
        return 0;
    }
    if ( fc (vOrigem, vDestino) == 0)
        return 1;

    pDLista visitados = criarLista();
    return existeCaminhoRecursivo(grafo, vOrigem, vDestino, fc, visitados);
}

#endif
