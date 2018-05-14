#include <vector>
#include <iostream>
#include <list>
#include <queue>

// ==============================================================

class Graph;

int get_degree(const int input_vertex);
int max_degree(const Graph& rhs);
int avg_degree(const Graph& rhs);
int number_of_self_loop(const Graph& rhs);

void dfs(const Graph& rhs);
void dfs_node(const Graph& rhs, const int vertex, std::vector<int>& marked, std::list<int>& r);

void bfs(const Graph& rhs);

// ==============================================================

class Graph {

friend int get_degree(const Graph& rhs, const int input_vertex);
friend int max_degree(const Graph& rhs);
friend int avg_degree(const Graph& rhs);
friend int number_of_self_loop(const Graph& rhs);

friend void dfs(const Graph& rhs);
friend void dfs_node(const Graph& rhs, const int vertex, std::vector<int>& marked, std::list<int>& r);

friend void bfs(const Graph& rhs);

public:
    Graph(std::vector<std::vector<int>> g, int v, int e) :
        m_graph(g), m_vertex(v), m_edge(e) { }
    Graph(const Graph& rhs);
    Graph& operator = (const Graph& rhs);

    int vertex() const { return m_vertex; }
    int edge() const { return m_edge; }
    void add_edge(const int vertex1, const int vertex2);
    std::vector<int> adj(const int input_vertex);

    ~Graph() = default;

private:
    std::vector<std::vector<int>> m_graph;
    int m_vertex = 0;
    int m_edge = 0;

};

// ==============================================================

Graph::Graph(const Graph& rhs) {
    m_graph = rhs.m_graph;
    m_vertex = rhs.m_vertex;
    m_edge = rhs.m_edge;
}

Graph& Graph::operator = (const Graph& rhs) {
    if (this != &rhs) {
        this->m_graph = rhs.m_graph;
        this->m_vertex = rhs.m_vertex;
        this->m_edge = rhs.m_edge;
    }
}

void Graph::add_edge(const int vertex1, const int vertex2) {
    int len = m_graph.size();
    if (vertex1 > len || vertex2 > len) return;
    m_graph[vertex1].push_back(vertex2);
    m_graph[vertex2].push_back(vertex1);
    m_edge += 1;
}

std::vector<int> Graph::adj(const int input_vertex) {
    std::vector<int> ret;
    if (input_vertex > m_graph.size()) return ret;
    else return m_graph[input_vertex];
}

// Friend Function
// ==============================================================

int get_degree(const Graph& rhs, const int input_vertex) {
    return (rhs.m_graph)[input_vertex].size();
}

int max_degree(const Graph& rhs) {
    int max = 0;
    for (auto v : rhs.m_graph) {
        if (v.size() > max) max = v.size();
    }
    return max;
}

int avg_degree(const Graph& rhs) {
    int sum_degree = 0;
    int number_of_vertex = rhs.m_graph.size();
    for (auto each_v : rhs.m_graph) {
        sum_degree += each_v.size();
    }
    return sum_degree / number_of_vertex;
}

int number_of_self_loop(const Graph& rhs) {
    int self_loop = 0;
    int len = rhs.m_graph.size();
    for (int vtx = 0; vtx < len; ++vtx) {
        for (int sub_vtx : rhs.m_graph[vtx]) {
            if (sub_vtx == vtx) self_loop += 1;
        }
    }
    return self_loop;
}

// 深度优先搜索
// ===============================================================

void dfs(const Graph& rhs) {
    std::vector<int> is_marked(rhs.m_vertex);
    std::list<int> route;
    dfs_node(rhs, 0, is_marked, route);
}

void dfs_node(const Graph& rhs, const int vertex, std::vector<int>& marked, std::list<int>& r) {
    marked[vertex] = 1;
    r.push_back(vertex);
    for (int attached_node : rhs.m_graph[vertex]) {
        if (!marked[attached_node]) dfs_node(rhs, attached_node, marked, r);
    }
    for (int node : r) std::cout << node << " ";
    std::cout << std::endl;
    r.pop_back();
}

// 广度优先搜索
// ================================================================

void bfs(const Graph& rhs) {
    std::vector<int> is_marked(rhs.m_vertex);
    std::queue<int> route;
    route.push(0);
    while (!route.empty()) {
        is_marked[route.front()] = 1;
        for (int attached_vertex : rhs.m_graph[route.front()]) {
            if (!is_marked[attached_vertex]) {
                route.push(attached_vertex);
                is_marked[attached_vertex] = 1;
            }
        }
        std::cout << route.front() << " ";
        route.pop();
    }
    std::cout << std::endl;
}