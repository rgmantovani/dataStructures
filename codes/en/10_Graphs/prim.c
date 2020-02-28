int primMST(LAdj *g, int p[], int w[]) {
  int i, imin, v, r=0, cor[g->nvert];
  Nodo *aux;
  int fsize=0, fringe[g->nvert]; // ORLA (stack de vértices)

  // Inicializações...
  for (i=0; i<g->nvert; i++) {
    p[i] = -1;
    cor[i] = BLACK;
  }
  cor[0] = GREY;
  w[0] = 0;
  fringe[fsize++] = 0; //f = addV(f, 0, 0);

  //ciclo principal...
  while (fsize>1) {
    // Retirar melhor elemento da orla ("f = nextF(f, &v);"):
    // (1) encontrar mínimo
    imin = 0;
    for (i=1; i<fsize; i++)
      if (w[fringe[imin]] < w[fringe[i]]) imin = i;
    // (2) remover elemento
    v = fringe[imin];
    fringe[imin] = fringe[++fsize];
    // FIM DE "retirar"
    cor[v] = BLACK;
    r += w[v];
    for (aux=g->adj[v]; aux; aux=aux->prox)
      switch (cor[aux->dest])
	{
	case WHITE:
	  cor[aux->dest] = GREY;
	  fringe[fsize++] = aux->dest; //f = addV(f, aux->dest, aux->peso);
	  w[aux->dest] = aux->peso;
	  p[aux->dest] = v;
	  break;
	case GREY:
	  if (aux->peso > w[aux->dest]) {
	    //f = updateV(f, aux->dest, aux->peso);
	    p[aux->dest] = aux->peso;
	    w[aux->dest] = v;
	  }
	default:
	  break;
	}
  }
  return r;
}
