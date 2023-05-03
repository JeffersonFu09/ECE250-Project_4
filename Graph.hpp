#include <vector>
#include <utility>
#include <iostream>
#include "Node.hpp"
using namespace std;

class Graph{
    private: 
        vector<Node> nodes[50001]; 
    public:
        Graph();
        bool insert(int a, int b, int w);
        void print(int a);
        bool vertexExists(int a);
        bool remove(int a);
        void prims(bool func);
        bool exceptionCatcher(int a, int b, int w);
};