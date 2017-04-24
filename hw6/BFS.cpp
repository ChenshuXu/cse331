#include <fstream>
using namespace std;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
#include <string>
using std::string;
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <limits>

using namespace std;


class node{
    int value;
    int distance;
    node *parent;
    bool visited;
    vector<node> children;

public:
    node(int data);
    void add_child(node child);
    void add_child(int data);
    void set_visited(bool v);
    bool get_visited();
    int get_value();
    vector<node> get_child();
    bool leaf();
    bool operator==(node b);
};

node::node(int data){
    value = data;
    distance = std::numeric_limits<int>::max();
    visited = false;
    parent = NULL;
}

void node::add_child(node child){
    children.push_back(child);
}

void node::add_child(int data){
    node temp(data);
    temp.parent = this;
    children.push_back(temp);
}

void node::set_visited(bool v){
    this->visited = v;
}

bool node::get_visited(){
    return this->visited;
}

int node::get_value(){
    return value;
}

vector<node> node::get_child(){
    return children;
}

bool node::leaf(){
    return children.size()==0;
}

bool node::operator==(node b){
    return b.value==value;
}


// This class represents a directed graph using adjacency list representation
class Graph
{
    int n;    // No. of vertices
    vector<node> adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int n);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int n)
{
    this->n = n;
    adj = new list<node>[n];
    
}
 
void Graph::addEdge(int v, int w)
{
	bool exist = false;
	node* ptr;
	for(node i = adj.begin(); i != adj.end(); i++){
		if (i.get_value() == v){
			i.add_child(w);
			exist = true;
		}
	}
	
	if (!exist){
		node tmp = new node(w);
		adj.push_back(temp);
	}
	
}
 
void Graph::BFS(int s)
{

}


int main(int argc, char *argv[])
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(1);
 
    return 0;
}