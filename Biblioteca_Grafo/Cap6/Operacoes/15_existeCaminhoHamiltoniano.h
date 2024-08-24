#ifndef CAMINHO_HAMILTONIANO_H
#define CAMINHO_HAMILTONIANO_H


int existeCaminhoSem(pDGrafo grafo, pVertice vOrig, pVertice vDest, FuncaoComparacao fc, pDLista visitados, pDLista excluidos) {

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
        if (buscarNohInfo(visitados, vert, fc) == NULL && buscarNohInfo(excluidos, vert, fc) == NULL) {
            if ( existeCaminhoSem(grafo, vert, vDest, fc, visitados, excluidos ) == 1) {
                return 1;
            }
        } else if ( fc (vert, vDest) == 0) {
            return 1;
        }
        aux = aux->prox;
    }

    return 0;
}



int existeCaminhoHamiltoniano (pDGrafo grafo, FuncaoComparacao pfc) {
    if ( grafo == NULL )
        return 0;

     // Caso o grafo nao seja fortemente conectado ele necessariamente nao é hamiltoniano
    if ( grafoConexo(grafo, pfc) == 0)
        return 0;

    pNoh aux, aux2;
    pVertice vert, vert2;

    aux = grafo->listaVertices->primeiro;
     // Percorre o grafo verificando se é possivel acessar o primeiro vertice excluindo
    while (aux != NULL) {
        vert = (pVertice) aux->info;
        aux2 = grafo->listaVertices->primeiro;
        pDLista excluidos = criarLista();
        int flag = 1;
        while (aux2 != NULL) {
            vert2 = (pVertice) aux2->info;

            if (vert == NULL)
                return 0;

            //printf("\nGrafoConexo\naux1: %d", *(int*)vert->info);
            //printf("\naux2: %d", *(int*)vert2->info);

            pDLista visitados = criarLista();
            incluirInfo(excluidos, vert2);
            if (existeCaminhoSem(grafo, vert2, vert, pfc, visitados, excluidos) == 0) {
                flag = 0;
                break;
            }
            //getch();
            aux2 = aux2->prox;
        }

        if ( flag == 1)
            return 1;

        aux = aux->prox;
    }

    return 0;
}

#endif
