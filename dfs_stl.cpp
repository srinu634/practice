#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#define BLACK 0
#define WHITE 1
#define GRAY 2
/*
WHITE - Unvisited
Gray - Visited and in the dfs run
BLACK - Completed dfs from this point
*/



using namespace std;

class Graph {
    vector<int> g[1000]; //Atmost 1000 vertices
    int n; //# of nodes
    bool visited[1000];
    short int color[1000];

public:
    Graph(int);
    void dfs();
    void run_dfs(int);
    void modified_dfs();
    void run_modified_dfs(int);
    void addEdge(int,int);
    void printGraph();
    void DetectCycle();
};

 Graph::Graph(int n){
    int i;

    this->n = n; //set the size of the graph

    for(i=0;i<this->n;i++)
        visited[i] = false;

} //constructor

void Graph::dfs() {
    int i;

    for(i=0;i<n;i++)
        if( visited[i] == false)
            run_dfs(i);

} //Graph::dfs

void Graph::run_dfs(int v){
    int i;

    if( visited[v] == false){
         cout<<"Visiting vertex: "<<v<<endl;
        visited[v] = true;
    }


    for(i=0;i<g[v].size();i++){
        if( visited[g[v][i]] == false){
            visited[g[v][i]] = true;
            cout<<"Visiting vertex: "<<g[v][i]<<endl;
            run_dfs(g[v][i]);
        }
    }
}//run_dfs

void Graph::modified_dfs() {
    int i;

    for(i=0;i<n;i++)
        visited[i] = false,color[i] = WHITE;

    for(i=0;i<n;i++)
        if( visited[i] == false)
            run_modified_dfs(i);

} //Graph::dfs

void Graph::run_modified_dfs(int v){
    int i;

    if( visited[v] == false){
         cout<<"Visiting vertex: "<<v<<endl;
        visited[v] = true;
    }


    for(i=0;i<g[v].size();i++){
        if( visited[g[v][i]] == false){
            visited[g[v][i]] = true;
            cout<<"Visiting vertex: "<<g[v][i]<<endl;
            run_modified_dfs(g[v][i]);
        }
        else{
            cout<<"CYCLE DETECTED."<<v<<", "<<g[v][i]<<" are two nodes of the cycle"<<endl;
        }
    }
}//run_dfs

void Graph::addEdge(int a,int b){
    g[a].push_back(b);
    //Take care of selp loops
    if(a !=b)
        g[b].push_back(a);
}

void Graph::printGraph(){
    int i,j;
    for(i=0;i<n;i++){
        j=g[i].size();
        for(j=0;j<g[i].size();j++)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }

}

void Graph::DetectCycle() {
    modified_dfs();
}

int main( ) {
    Graph g(6);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,1);
    g.addEdge(5,5);
    g.printGraph();
    g.dfs();

    cout<<endl<<endl<<"Running Cycle Detection algorithm"<<endl<<endl;;
    g.DetectCycle();

    return 0;
}
