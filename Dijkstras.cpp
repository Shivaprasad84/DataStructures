#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <utility>
#include <set>

template <typename T>
class Graph
{
private:
    std::unordered_map<T, std::list<std::pair<T, int>>> m;

public:
    Graph() {}
    void add_edge(T u, T v, int w, bool bi_dir = true)
    {
        m[u].push_back(std::make_pair(v, w));
        if (bi_dir)
        {
            m[v].push_back(std::make_pair(u, w));
        }
    }

    void print_graph()
    {
        for (auto i : m)
        {
            std::cout << i.first << " : ";
            for (auto j : i.second)
            {
                std::cout << j.first << ", " << j.second << " ";
            }
            std::cout << std::endl;
        }
    }

    void BFS(T start_node)
    {
        std::unordered_map<T, bool> visited;
        for (auto j : m)
            visited[j.first] = false;
        std::queue<T> q;
        visited[start_node] = true;
        q.push(start_node);

        while (!q.empty())
        {
            T s = q.front();
            q.pop();
            std::cout << s << " ";
            for (auto it : m[s])
            {
                if (!visited[it.first])
                {
                    visited[it.first] = true;
                    q.push(it.first);
                }
            }
        }
    }

    void DFS(T start_node)
    {
        std::unordered_map<T, bool> visited;
        for (auto j : m)
            visited[j.first] = false;
        DFS_Helper(start_node, visited);
    }

    void DFS_Helper(T start_node, std::unordered_map<T, bool> &visited)
    {
        visited[start_node] = true;
        std::cout << start_node << " ";
        for (auto j : m[start_node])
        {
            if (!visited[j.first])
                DFS_Helper(j.first, visited);
        }
    }

    std::unordered_map<T, int> Dijkstra(T src)
    {
        std::unordered_map<T, int> dist;

        // Set all dist to max int
        for (auto j : m)
        {
            dist[j.first] = INT32_MAX;
        }

        // Set to find out node with min dist
        std::set<std::pair<int, T>> s;

        dist[src] = 0;
        s.insert(std::make_pair(0, src));

        while (!s.empty())
        {
            // Find the pair at front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;

            s.erase(s.begin());

            for (auto child : m[node])
            {
                if (nodeDist + child.second < dist[child.first])
                {
                    T dest = child.first;
                    auto f = s.find(std::make_pair(dist[dest], dest));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    dist[dest] = nodeDist + child.second;
                    s.insert(std::make_pair(dist[dest], dest));
                }
            }
        }
        return dist;
    }

    void Dijkstra_shortest_path_from(T src)
    {
        std::unordered_map<T, int> dist = Dijkstra(src);
        std::cout << "Distance from " << src << " to " << std::endl;
        for(auto j : dist)
        {
            std::cout << j.first << " : " << j.second << std::endl;
        }
    }
};

int main()
{
    Graph<std::string> g;
    g.add_edge("Mysore", "Mandya", 2);
    g.add_edge("Mysore", "Bangalore", 3);
    g.add_edge("Mysore", "Madikeri", 2);
    g.add_edge("Mysore", "Kasaragod", 4);
    g.add_edge("Mysore", "Mangalore", 5);
    g.add_edge("Mandya", "Bangalore", 1);
    g.add_edge("Mandya", "Madikeri", 3);
    g.add_edge("Bangalore", "tumkur", 1);
    g.add_edge("Bangalore", "Goa", 7);
    g.add_edge("Kasaragod", "Mangalore", 1);
    g.add_edge("Kasaragod", "Karwar", 2);
    g.add_edge("Mangalore", "Karwar", 1);


    g.Dijkstra_shortest_path_from("Mysore");
}