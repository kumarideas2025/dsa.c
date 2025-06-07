#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* bellman_ford(int v, int edges[][3], int e, int s) {
    int* dist = (int*)malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) {
        dist[i] = INT_MAX; // Use INT_MAX to represent infinity
    }
    dist[s] = 0;

    // Relax edges v-1 times
    for (int i = 0; i < v - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Nth relaxation to check for negative cycles
    for (int j = 0; j < e; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            free(dist); // Free allocated memory
            int* result = (int*)malloc(sizeof(int)); // Allocate memory for result
            result[0] = -1; // Indicates a negative cycle
            return result;
        }
    }

    return dist; // Return the distance array
}

int main() {
    int v = 5; // Number of vertices
    int edges[][3] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 1, 1},
        {3, 2, 5},
        {4, 3, -3}
    };
    int e = sizeof(edges) / sizeof(edges[0]); // Number of edges
    int s = 0; // Starting vertex

    int* distances = bellman_ford(v, edges, e, s);
    
    if (distances[0] == -1) {
        printf("Negative cycle detected\n");
    } else {
        printf("Vertex Distance from Source\n");
        for (int i = 0; i < v; i++) {
            printf("%d \t\t %d\n", i, distances[i]);
        }
    }

    free(distances); // Free allocated memory
    return 0;
}

