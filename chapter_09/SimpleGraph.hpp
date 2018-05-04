#include <vector>

// ==============================================================

class Graph;

int get_degree(const int input_vertex);
int max_degree(const Graph& rhs);
int avg_degree(const Graph& rhs);
int number_of_self_loop(const Graph& rhs);

// ==============================================================

class Graph {

friend int get_degree(const Graph& rhs, const int input_vertex);
friend int max_degree(const Graph& rhs);
friend int avg_degree(const Graph& rhs);
friend int number_of_self_loop(const Graph& rhs);

public:
    Graph() = default;
    Graph(const Graph& rhs);
    Graph& operator = (const Graph& rhs);

    int vertex() const { return m_vertex; }
    int edge() const { return m_edge; }
    void add_edge(int vertex1, int vertex2);
    std::vector<int> adj(int input_vertex);

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

void add_edge(int vertex1, int vertex2) {
    int len = m_graph.size();
    if (vertex1 > len || vertex2 > len) return;
    m_graph[vertex1].push_back(vertex2);
    m_graph[vertex2].push_back(vertex1);
}

std::vector<int> adj(int input_vertex) {
    std::vector<int> ret;
    if (input_vertex > m_graph.size()) return ret;
    else return m_graph[input_vertex];
}

// Friend Function
// ==============================================================

int get_degree(const Graph& rhs, const int input_vertex) {

}

int max_degree(const Graph& rhs);
int avg_degree(const Graph& rhs);
int number_of_self_loop(const Graph& rhs);