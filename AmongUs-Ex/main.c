#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noListaAresta{
    unsigned int u, v;
    int peso;
    struct noListaAresta *prox;
} ListaAresta;

typedef struct noListaVertices {
    int valorNo; // Valor do nó/vértice adjacente.
    int peso; // Valor do peso do caminho da aresta para esse nó.
    struct noListaVertices *prox; // Próximo nó/vértice adjacente.
} ListaVertices;

typedef struct Grafo {
    int orientacao; // 1 - sim, 0 - não.
    int numVertices;
    ListaAresta *listaArestas; // ponteiro para a lista de listaArestas
    ListaVertices **listaVertices; // vetor de lista de vértices, cada instância do vetor é um vértice, e os nós da lista em cadeia são os vértices adjacentes.
} Grafo;

Grafo *criaGrafo(){
    Grafo *gAux = (Grafo *) malloc(sizeof(Grafo));
    gAux->listaVertices = NULL;
    gAux->listaArestas = NULL;
    gAux->numVertices = 0;
    gAux->orientacao = 0;
    return gAux;
}

ListaAresta *criaListaAresta(){
    ListaAresta *lAux = (ListaAresta *) malloc(sizeof (ListaAresta));
    lAux->prox = NULL;
    lAux->peso = 0;
    lAux->u = 0;
    lAux->v = 0;
    return lAux;
}

ListaVertices **criaListaVerticesAdjacentes(int numVertices){
    ListaVertices **lAux = malloc(numVertices * sizeof (ListaVertices *));
    for (int i = 0; i < numVertices; ++i) {
        lAux[i] = NULL;
    }
    return lAux;
}

ListaAresta *insereListaAresta(ListaAresta *l, unsigned int u, unsigned int v, int peso){
    ListaAresta *lAux = criaListaAresta();
    lAux->peso = peso;
    lAux->u = u;
    lAux->v = v;
    lAux->prox = l; // muda a cabeça.
    return lAux;
}

ListaVertices *insereVertice(ListaVertices *l, int i, int peso) {
    if(l!=NULL && i>l->valorNo) {
        l->prox = insereVertice(l->prox,i,peso);
        return l;
    } else {
        ListaVertices *lAux = malloc(sizeof(ListaVertices));
        lAux->valorNo = i;
        lAux->peso = peso;
        lAux->prox = l; // muda a cabeça.
        return lAux;
    }
}

ListaVertices *removeCabecaListaVertices (ListaVertices *l){
    if(l != NULL) {
        ListaVertices *lAux = l->prox;
        free(l);
        return lAux;
    }
    return l;
}

void carregaVertices(Grafo *g) {
    g->listaVertices = criaListaVerticesAdjacentes(g->numVertices);
    ListaAresta *lAux = g->listaArestas;
    int i;

    while (lAux != NULL) {
        for (i = 0; i < g->numVertices; ++i) {
            if(lAux->v == i){
                if(g->orientacao)
                    g->listaVertices[lAux->u] = insereVertice(g->listaVertices[lAux->u], lAux->v, lAux->peso);
                else {
                    g->listaVertices[lAux->u] = insereVertice(g->listaVertices[lAux->u], lAux->v, lAux->peso);
                    g->listaVertices[lAux->v] = insereVertice(g->listaVertices[lAux->v], lAux->u, lAux->peso);
                }
                break;
            }
        }
        lAux = lAux->prox;
    }
}

int main() {
    int T, n, m, k, u, v, w, e, tMax, p, x, y, t, Timer;
    /*  T = number of test cases.
     *  n = number of rooms.
     *  m = number of secret paths.
     *  k = number of crewmates.
     *  u = room u.
     *  v = room v.
     *  w = time to pass through u-v path.
     *  e = number of predictions.
     *  tMax = the time for the crewmates to complete all the tasks.
     *  p = crewmate p.
     *  x = room x.
     *  y = room y.
     *  t = time to crewmate p appear.
     */
    Grafo* mapImpostor = criaGrafo();
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        Timer = 0;
        scanf("%d %d %d", &n, &m, &k);
        mapImpostor->numVertices = n;
        for (int j = 0; j < m; ++j) {
            scanf("%d %d %d", &u, &v, &w);
            mapImpostor->listaArestas = insereListaAresta(mapImpostor->listaArestas,u,v,w);
        }
        carregaVertices(mapImpostor);
        scanf("%d %d", &e, &tMax);
        //todo;
        for (int j = 0; j < e; ++j) {
            scanf("%d %d %d", &p, &x, &t);
            //todo;
        }
        scanf("%d %d", &x, &y);
        //todo;
    }
}