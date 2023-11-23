#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int vertices, edges;

void inputGraph() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < edges; ++i) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
}

void findVertexCover() {
    printf("Vertex Cover: ");
    for (int u = 0; u < vertices; ++u) {
        for (int v = 0; v < vertices; ++v) {
            if (graph[u][v] == 1) {
                printf("%d ", u);
                printf("%d ", v);
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    inputGraph();
    findVertexCover();

    // Adding name
    printf("Name: Hari Prasad Gyawali\n");

    return 0;
}
