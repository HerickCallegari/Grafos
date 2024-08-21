#ifndef CAMINHO_EULERIANO_H
#define CAMINHO_EULERIANO_H

int existeCaminhoEuleriano (pDGrafo grafo, FuncaoComparacao pfc) {
    if ( grafo == NULL || grafo->listaVertices == NULL )
        return 0;

    pNoh inicial = grafo->listaVertices->primeiro;


    pVertice auxVert;
    pNoh aux = grafo->listaVertices->primeiro;
    for ( int i = 0; i < grafo->listaVertices->quantidade; i++ ) {

    }




}

#endif
