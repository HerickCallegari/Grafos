#ifndef CAMINHO_EULERIANO_H
#define CAMINHO_EULERIANO_H

 /*
    Usando conseitos matematicos, adotei que se qualquer Vertices tiver o modulo da diferenša
    entre suas adjacencias (Saida) e suas incidencias (entrada) maior que 1,ou seja 2 ou mais
    ou que ele tenha exatamente 2 vertices com grau impar, o grafo necessariamente nao tem
    caminho Euleriano, Exemplo:
    entrada: 1
    saida:   3
    saida - entrada = 2

    obs: decidi chamar as adjacencias de saida pois sao por onde e possivel "sair" do Vertice
    o contrario vale para as incidencias, decidi chamalas de entrada pois sao as arestas possiveis
    para "entrar" no Vertice.
 */


pDGrafo percorreGrafo ( pDGrafo grafo, pVertice vert, FuncaoComparacao fc ) {

    if ( vert == NULL )
        return NULL;
    pNoh aux = vert->listaAdjacencias->primeiro;
    pVertice verAux = (pVertice)aux->info;
    int k = vert->listaAdjacencias->quantidade;
    for ( int i = 0; i < k; i++ ) {
         verAux = (pVertice)aux->info;
        if ( grafo == NULL || aux == NULL || verAux == NULL )
            return NULL;

        pDGrafo grafoAuxiliar = duplicarGrafo(grafo, fc);

        if ( grafoAuxiliar == NULL )
            return NULL;

        excluirAresta(grafoAuxiliar, vert->info, verAux->info, fc);

        if ( quantidadeDeArestas(grafoAuxiliar, fc) == 0 ) {
                return grafoAuxiliar;
        }else  {
            verAux = buscarVertice(grafoAuxiliar, verAux->info, fc);
            return percorreGrafo(grafoAuxiliar, verAux, fc);
        }
        aux = aux->prox;
    }
    return NULL;
}

int existeCaminhoEuleriano (pDGrafo grafo, FuncaoComparacao pfc) {
    if ( grafo == NULL || grafo->listaVertices == NULL )
        return 0;
     // Grafo "virtual" para fazer testagem e as operacoes, vai ser destruido futuramente
    pNoh aux = grafo->listaVertices->primeiro;

     // Noh com menos insidencidencia, pego o primeiro da lista
     // principal para ter um como refenrencia inical, mas nao
     // necessariamente sera o noh escolhido.
    pVertice inicial = (pVertice) aux->info;
     // A quantidade de adjasencias do Noh inicial
    int saidaI        = inicial->listaAdjacencias->quantidade;
     // A quantidade de insidencias do Noh inicial
    int entradaI     = buscarVerticesIncidentes(grafo, inicial, pfc)->quantidade + 1;
    int diferenca = saidaI - entradaI;
    if ( diferenca > 1 || diferenca < -1)
        return 0;
    int quatidadeImpares = 0;

    pVertice auxVert;
    aux = grafo->listaVertices->primeiro;
     // Vai percorrer a Lista de vertices para ver qual tem a menor entrada e maior saida
    for ( int i = 0; i < grafo->listaVertices->quantidade; i++ ) {
        auxVert = (pVertice) aux->info;

        if ( auxVert == NULL )
            return 0;

        int saidaA   = auxVert->listaAdjacencias->quantidade;
        int entradaA = buscarVerticesIncidentes(grafo, inicial, pfc)->quantidade + 1;

        printf("Vertice: %d Entrada: %d Saida: %d\n", *(int*)auxVert->info, entradaA, saidaA);
        diferenca = saidaA - entradaA;
        if ( diferenca > 1 || diferenca < -1)
            return 0;
        quatidadeImpares += diferenca % 2 == 0 ? 0 : 1;

         // Se a entrada do vertice inicial (Incidencia) for maior e
         // a saida (adjacensia) que do vertice auxiliar entao ele troca.
        if ( entradaI >= entradaA) {
            if ( saidaI < saidaA ) {
                inicial  = auxVert;
                saidaI   = saidaA;
                entradaI = entradaA;
            }
        }
        aux = aux->prox;
    }


     // Ultima condicao de existencia baseada na condicao de diferenca entre saida e entrada
    if ( saidaI - entradaI > 1 || saidaI - entradaI < -1)
            return 0;
    if ( quatidadeImpares == 2 )
        return 0;

     // percorre grafo tem a intensao de percorrer o grafo em todos os caminhos possiveis sem que haja
    if ( percorreGrafo(grafo, inicial, pfc) != NULL)
        return 1;
    else
        return 0;
}





#endif
