#ifndef CRIAR_GRAFO_H
#define CRIAR_GRAFO_H

/* --------------------------- */
pDGrafo criarGrafo(){

  pDGrafo grafo = malloc(sizeof(DGrafo));
  grafo->listaVertices = criarLista();
  return grafo;

}

#endif
