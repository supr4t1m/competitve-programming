/*
 * This is a straight forward max flow - min cut problem. 
 * We traverse through the graph and each time send the 
 * minimum capacity flow through the path from source to target
 * until we cannot send more. 
 * We then output the cut-set, i.e. the edges which are connecting
 * from S-component to T-component. 
 */
#include <bits/stdc++.h>

using namespace std;

#define V 51

bool visited[V];
int n;
int rGraph[V][V];

struct edge {
    int from;
    int to;
};

void  print_graph() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) 
            printf("%3d ", rGraph[i][j]);
        cout << endl;
    }
    cout << endl;
}

void print_parent(int parent[]) {
    for (int i=0; i<n; i++)
        cout << parent[i] << " ";
    cout << endl;
}

/*
 * Simple breadth first search to find a path from source 
 * to target node, such that a flow can be sent across. 
 *
 * @param s the source vertex
 * @param t the target vertex
 * @param parent the path to be populated. 
 *
 * @return boolean value representing whether a flow can be
 *         sent across s and t. 
 */
bool bfs(int s, int t, int parent[]) {
    memset(visited, 0, sizeof(bool)*n);
    queue<int> q;
    q.push(s);
    visited[s] = true; 

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v=0; v<n; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        } 
    }

    return visited[t];
}

/*
 * This function will do breadth first search, and on each iteration 
 * it will find the minimum capacity of a pipe(edge) connecting source to target. 
 * It will send a flow equal to the minimum capacity. It will repeat the steps until 
 * it cannot reach from source to target. 
 *
 * forFulkerson(int graph[][], int s, int t)
 * @param graph[][] the graph formed from uniform bidirectional flow from given edges
 * @param s the source vertex
 * @param t the target vertex 
 *
 * @return the maximum flow that can be passed through the network. 
 */
int fordFulkerson(int graph[V][V], int s, int t) {
    int parent[n];
    int max_flow = 0;

    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++)
            rGraph[i][j] = graph[i][j];

    while (bfs(s, t, parent)) {
        int minCapacity = INT_MAX;

//      print_parent(parent);

//      print_graph();
        
        for (int v=t; v!=s; v=parent[v]) {
            int u = parent[v];
            if (minCapacity > rGraph[u][v]) {
                minCapacity = rGraph[u][v];
            }
        }

//      cout << minCapacity << endl;

        for (int v=t; v!=s; v=parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= minCapacity;
            rGraph[v][u] += minCapacity;
        }

        max_flow += minCapacity;
    }

//  print_graph();
    
    return max_flow;
}



int main() {
#ifndef ONLINE_JUDGE
// open the file in respective mode and redirect
// stream into respective file
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // if ONLINE_JUDGE
    int links;
    int u, v, cap;
    int graph[V][V];

    int s = 0, t = 1;

    while (cin >> n >> links && (n||links)) {
        struct edge e[links];

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                graph[i][j] = 0;

        for (int i=0; i<links; i++) {
            cin >> u >> v >> cap;
            e[i].from=u, e[i].to=v;
            graph[u-1][v-1] = graph[v-1][u-1] = cap;

        }

        fordFulkerson(graph, s, t);

        int parent[n];
        memset(parent, s, sizeof(int)*n);

        bfs(s, t, parent);

        for (int i=0; i<links; i++) {
            if (visited[e[i].from-1] && !visited[e[i].to-1] && !rGraph[e[i].from-1][e[i].to-1])
                cout << e[i].from << " " << e[i].to << endl;
            else if (visited[e[i].to-1] && !visited[e[i].from-1] && !rGraph[e[i].to-1][e[i].from-1])
                cout << e[i].from << " " << e[i].to << endl;
        }
        cout << endl;
    }
}

