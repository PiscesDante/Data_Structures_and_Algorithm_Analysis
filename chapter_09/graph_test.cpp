#include <vector>
#include <iostream>

#include "SimpleGraph.hpp"

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> temp;
    temp.push_back({2, 1, 5});
    temp.push_back({0, 2});
    temp.push_back({0, 1, 3, 4});
    temp.push_back({5, 4, 2});
    temp.push_back({3, 2});
    temp.push_back({3, 0});
    Graph sg(temp, 6, 8);
    dfs(sg);
    std::cout << "=====================================" << std::endl;
    bfs(sg);
    return 0;
}