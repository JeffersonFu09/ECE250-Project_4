#include "Graph.hpp"
#include "Illegal_Exception.hpp"
#include "MinHeap.hpp" 
Graph::Graph(){

}

bool Graph::insert(int a, int b, int w){
    for (int i =0 ; i < nodes[a].size(); i++){
        if (nodes[a][i].getV() == b){
            return false;
        } 
    }     
    nodes[a].push_back(Node(b,w));
    nodes[b].push_back(Node(a,w));
    return true;
}

void Graph::print(int a ){
    if(!vertexExists(a)){
        cout << "failure" << endl;
        return;
    }
    for (int i =0 ; i < nodes[a].size(); i++){
        cout << nodes[a][i].getV() << " ";
    }
    cout << endl;
    return;

}

bool Graph::vertexExists(int a ){
    if (nodes[a].size() == 0 ){
        return false ;
    }
    return true;
}   

bool Graph::remove(int a){
    if(!vertexExists(a)){
        return false;
    }
    vector<int> adjNodes;
    for (int i = 0 ; i < nodes[a].size(); i++) {
        adjNodes.push_back(nodes[a][i].getV());
    }
    nodes[a].clear();
    while (!adjNodes.empty()){
        int b = adjNodes.back();
        adjNodes.pop_back(); 
        for (int i = 0 ; i < nodes[b].size(); i++ ){ 
            if (nodes[b][i].getV() == a){
                nodes[b].erase(nodes[b].begin()+i);
                break;
            }
        }
    }
    return true;
}

void Graph::prims(bool func){
    MinHeap pq;
    for (int i = 0 ; i < 50001; i++){
        if (vertexExists(i)){
            pq.insert(i);
        }
    }
    int cost = 0;
    int connectedNodes = 0;
    int n = pq.getSize();
    while(connectedNodes < n){
        Node u = pq.extractMin();
        int uVertex = u.getV();
        int uWeight = u.getW();
        if (connectedNodes ==0 ){
            uWeight=0;
        }
   
        cost+=uWeight;
      
        connectedNodes++;
        for (int i = 0; i < nodes[uVertex].size(); i++ ){ 
            int curV = nodes[uVertex][i].getV();
            int curW = nodes[uVertex][i].getW();
            if (curW <= pq.getWeight(curV) && pq.existsInPQ(curV)){ 
                pq.setWeight(curV, curW);
                pq.update(curV);
                pq.setParent(curV, Node(uVertex, curW));
               
            }
        }

    }
    if (!func){
        if(cost == 0){
            cout << "failure" << endl;
        }else{
            pq.printParents();
        }
    }else{
        cout << "cost is " << cost << endl;
    }
}

bool Graph::exceptionCatcher(int a, int b, int w){
    try{
        if (a>50000 || a <= 0 || b>50000 || b <= 0 || w<=0){
            throw illegal_exception();
        }
        return false;
    }catch(illegal_exception){
        cout << "illegal argument" << endl;
        return true;
    }
}