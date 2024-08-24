#ifndef CAMINHO_EULERIANO_H
#define CAMINHO_EULERIANO_H

 /*
    Usanado conceitos Matematicos, defini que o grafo sera euleriano apenas se ele for fortemente
    conectado e todos os vertices tiverem o mesmo grau de entrada e de saida.

    obs: decidi chamar as adjacencias de saida pois sao arestas que permitem "sair" do Vertice
    o contrario vale para as incidencias, decidi chamalas de entrada pois sao as arestas possiveis
    para "entrar" no Vertice.
 */

 //
int Diferenca ( pDGrafo grafo, pVertice vert, FuncaoComparacao pfc ) {
    int entrada = buscarVerticesIncidentes(grafo, vert, pfc)->quantidade;
    int saida   = vert->listaAdjacencias->quantidade;
    //printf("\nVertice: %d Diferenca: %d\n", *(int*)vert->info,entrada - saida);
    return entrada - saida;
}

int existeCaminhoEuleriano (pDGrafo grafo, FuncaoComparacao pfc) {

    if ( grafo == NULL || grafo->listaVertices == NULL )
        return 0;
     // Verifica se o Grafo é fortemente conexo
    if ( grafoConexo( grafo, pfc) == 0)
        return 0;

    pNoh aux = grafo->listaVertices->primeiro;
    pVertice vert;

    for ( int i = 0; i < grafo->listaVertices->quantidade; i++ ) {
        vert = (pVertice) aux->info;

        if ( Diferenca(grafo, vert, pfc) != 0 ) {
            return 0;
        }

        aux = aux->prox;
    }

    return 1;
}






#endif
