#include "Node.hpp"
#include <iostream>
using namespace std;

Node::Node(int val, int weight){
    v = val;
    w = weight;
}
Node::Node(){
    
}

void Node::setV(int val){
    v = val;
}


void Node::setW(int val){
    w = val;
}

int Node::getW(){
    return w;
}

int Node:: getV(){
    return v;
}