/*
 * The graph is constructed by forming edges from answer to other options. A simple tarjan's algorithm will 
 * provide the strongly connected components. Before printing printing sort all the strongly connected components
 * also sort each vertex within each component
 */
#include <bits/stdc++.h>

#define UNVISITED -1
#define maxN 26

using namespace std;

int dfsNumberCounter;

vector<vector<int>> adjList(maxN);
vector<string> result;

unordered_map<char, int> node_map;
unordered_map<int, char> rev_map;

vector<bool> instack(maxN);
vector<int> dfs_num(maxN);
vector<int> dfs_low(maxN);
stack<int> S;
// to store the strongly connected components
vector<vector<int>> components;

void init()
{
    for (int i=0; i<maxN; i++)
        adjList[i].clear();
    result.clear();
    node_map.clear();
    rev_map.clear();
    instack.assign(maxN, false);
    dfs_num.assign(maxN, UNVISITED);
    dfs_low.assign(maxN, 0);
    dfsNumberCounter = 0;
    components.clear();
}

void tarjanSCC(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push(u);
    instack[u] = true;
    
    for (int j=0; j<(int)adjList[u].size(); j++)
    {
        int v = adjList[u][j];
        if (dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if (instack[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u])
    {
        components.push_back(vector<int>());
        while (1) 
        {
            int x = S.top();
            S.pop();
            instack[x] = false;
            components.back().push_back(x);
            if (x == u)
                break;
        }
    }
}

void solve(int n)
{
    init();
    // node represents the vertex in the graph
    int node = 0; 
    while (n-- > 0)
    {
        char option[5], ans;
        for (int i=0; i<5; i++)
            cin >> option[i];
        cin >> ans;
        
        for (int i=0; i<5; i++)
        {

            if (node_map.find(option[i]) == node_map.end())
            {
// map the numbers to letters, reverse map letters to numbers
// numbers are easy to implement in terms of vertices of graph
                rev_map[node] = option[i];
                node_map[option[i]] = node++;
            }

        }

        for (int i=0; i<5; i++)
            adjList[node_map[ans]].push_back(node_map[option[i]]);
    }
//    cout << endl;

//    for (int i=0; i<(int)adjList.size(); i++)
//    {
//        cout << rev_map[i] << ": ";
//        for (int j: adjList[i])
//            cout << rev_map[j] << " ";
//        cout << endl;
//    }

    // begin the depth first search
    for (int i=0; i<node; i++)
        if (dfs_num[i] == UNVISITED) 
            tarjanSCC(i);


    // format the output
    for (int i=0; i<(int)components.size(); i++)
    {
        string s="";
        for (int j=0; j<(int)components[i].size(); j++) 
        {
            s += rev_map[components[i][j]];
        }
        sort(s.begin(), s.end());
        result.push_back(s);
    }
    sort(result.begin(), result.end());

    for (int i=0; i<(int)result.size(); i++)
    {
        for (int j=0; j<(int)result[i].size(); j++)
            cout << (j>0?" ":"") << result[i][j];
        cout << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
// open the file in respective mode and redirect
// stream into respective file
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    int n=0;
    bool first = true;
    while (cin >> n && n)
    {
        // the last newline is not from the program
        // insert new line at the beggining of each test case
        // thus removing duplicate newlines at the end
        // only the first newline is to be ignored
        if (!first) 
            cout << endl;
        else 
            first = false;
        solve(n);
    }
    return 0;
}
