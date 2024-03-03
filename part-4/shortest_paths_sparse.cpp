#include "shortest_paths_sparse.hpp"
#include <priority_queue.hpp>

#include <cmath>

std::vector<hop_t> bellman_ford(const SparseGraph &graph, const int source,
                                bool &has_negative_cycle)
{
    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(V, {inf, -1});

    // WRITE YOUR CODE HERE
    DP[source].weight=0;

    for(int i=0;i<V-1;i++){
        has_negative_cycle=false;
        for(int r=0;r<V;r++){
            for(int v=0;v<V;v++){
                for(const auto& edge : graph[v]) {
                int u = edge.vertex;
                float weight = edge.weight;
                if (DP[v].weight < inf && DP[v].weight + weight < DP[u].weight) {
                    DP[u].weight = DP[v].weight + weight;
                    DP[u].vertex = v;
                }
            }
            }
        }
    }

    return DP;
}

struct triplet_t {
    float d;
    int r;
    int v;
};

std::vector<hop_t> dijkstra(const SparseGraph &graph, const int source)
{
    assert(source >= 0);
    assert(source < (signed)graph.size());

    auto DP = std::vector<hop_t>(graph.size(), {inf, -1});

    // WRITE YOUR CODE HERE
    const int V = static_cast<int>(graph.size());
     DP[source].weight = 0.0;

    std::vector<bool> Open(V, true);

    while(true) {
        float D_star = inf;
        int v_star = -1;
        for(int v = 0; v < V; v++) {
            if(Open[v] && DP[v].weight < D_star) {
                D_star = DP[v].weight;
                v_star = v;
            }
        }
        if(v_star == -1) {
            break;
        }

        Open[v_star] = false;

        for(const auto& near : graph[v_star]) {
            int v = near.vertex;
            float weight = near.weight;
            if(Open[v] && DP[v_star].weight + weight < DP[v].weight) {
                DP[v].weight = DP[v_star].weight + weight;
                DP[v].vertex = v_star;
            }
        }
    }
    
    return DP;
}
