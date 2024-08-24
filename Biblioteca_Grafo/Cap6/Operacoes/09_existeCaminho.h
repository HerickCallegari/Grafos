#ifndef EXISTE_CAMINHO_H
#define EXISTE_CAMINHO_H

/* ----------------------------------------------------------------
A estratégia empregada para a verificação de existência do caminho
parte do vértice de destino e procede com a busca pelos vértices
que incidem sobre este, e assim sucessivamente, até o momento
que um dos vértices incidentes seja o vértice de origem.
Resumindo, a busca é feita no sentido do vértice de destino para o
vértice de origem.
-------------------------------------------------------------------*/
int existeCaminhoRecursivo(pDGrafo grafo, pVertice vOrig, pVertice vDest, FuncaoComparacao fc, pDLista visitados){

    // encontrou o caminho se o vertice de destino coincidir com o de origem
    if (fc(vOrig, vDest)== 0){
        return 1; // return true
    }
    incluirInfo(visitados, vOrig);

    pNoh aux = grafo->listaVertices->primeiro;

    // busca todos os vértices que levam a vDestino e
    // dispara uma chamada recursiva para cada um deles
    // e exclui os que ja foram visitados
    pDLista pendentes = criarLista();
    while (aux != NULL) {
        pVertice vert = (pVertice) aux->info;
        if ( buscarInfoPos(visitados, vert) == 0)
            incluirInfo(pendentes, vert);
        aux = aux->prox;
    }
    // não é um caminho possível
    if (pendentes->quantidade == 0){
        return 0;   // return false
    }

    // Repete Para Caminho

    int cont = 1;
    int flag = 0;
    while (cont <= pendentes->quantidade){

        pVertice verticeIncidente  = (pVertice) buscarInfoPos(pendentes, cont);
        cont++;

        if (existeCaminhoRecursivo(grafo, vOrig, verticeIncidente, fc, visitados) != 0){
                flag = 1;
                break;
        }
    }

    return flag;
}


/* --------------------------- */
int existeCaminho(pDGrafo grafo, void *idOrig, void *idDest, FuncaoComparacao fc){

   // busca os vértices para a origem e destino
   pVertice vOrigem  = buscarVertice(grafo, idOrig, fc);
   pVertice vDestino = buscarVertice(grafo, idDest, fc);


   if (vOrigem==NULL || vDestino==NULL){
      return 0;
   }

   pDLista visitados = criarLista();
   return existeCaminhoRecursivo(grafo, vOrigem, vDestino, fc, visitados);

}
#endif
