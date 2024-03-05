#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void DFS(int node, vector<vector<int>> &adjlist, vector<bool> &visit){
    visit[node] = true;
    cout << node << " ";
    for(int i = 0; i < adjlist[node].size(); i++){
        if(!visit[adjlist[node][i]]){
            DFS(adjlist[node][i], adjlist, visit);
        }
    }
}#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void DFS(int node, vector<vector<int>> &adjlist, vector<bool> &visit){
    visit[node] = true;
    cout << node << " ";
    for(int i = 0; i < adjlist[node].size(); i++){
        if(!visit[adjlist[node][i]]){
            DFS(adjlist[node][i], adjlist, visit);
        }
    }
}

int main(){
    int n, edges;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<vector<int>> adjlist(n + 1);
    cout << "Enter number of edges: ";
    cin >> edges;
    for(int i = 0; i < edges; i++){
        int x, y;
        cout << "Enter edge " << i + 1 << " (v1 --> v2): ";
        cin >> x >> y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    
    // BFS traversal
    cout << "BFS Traversal: ";
    vector<bool> visit_bfs(n + 1, false);
    queue<int> q;
    q.push(1);
    visit_bfs[1] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i = 0; i < adjlist[node].size(); i++){
            if(!visit_bfs[adjlist[node][i]]){
                visit_bfs[adjlist[node][i]] = true;
                q.push(adjlist[node][i]);
            }
        }
    }
    
    // DFS traversal
    cout << "\nDFS Traversal: ";
    vector<bool> visit_dfs(n + 1, false);
    DFS(1, adjlist, visit_dfs);

    return 0;

int main(){
    int n, edges;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<vector<int>> adjlist(n + 1);
    cout << "Enter number of edges: ";
    cin >> edges;
    for(int i = 0; i < edges; i++){
        int x, y;
        cout << "Enter edge " << i + 1 << " (v1 --> v2): ";
        cin >> x >> y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    
    // BFS traversal
    cout << "BFS Traversal: ";
    vector<bool> visit_bfs(n + 1, false);
    queue<int> q;
    q.push(1);
    visit_bfs[1] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i = 0; i < adjlist[node].size(); i++){
            if(!visit_bfs[adjlist[node][i]]){
                visit_bfs[adjlist[node][i]] = true;
                q.push(adjlist[node][i]);
            }
        }
    }
    
    // DFS traversal
    cout << "\nDFS Traversal: ";
    vector<bool> visit_dfs(n + 1, false);
    DFS(1, adjlist, visit_dfs);

    return 0;
