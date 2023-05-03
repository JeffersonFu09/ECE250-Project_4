#include <iostream>
#include <string>
#include <fstream>
#include "Graph.hpp"
using namespace std; 

int main();
int main(){
    string cmd;
    int a;
    int b;
    int w;
    bool check;
    Graph graph;
    while(cin>>cmd){
        if (cmd == "INSERT"){
            cin >> a >> b >> w; 
            if (!graph.exceptionCatcher(a, b, w)){
                check = graph.insert(a,b,w);
                if (check){ 
                    cout << "success" << endl;
                }else{
                    cout << "failure" << endl;
                }
            }
        }else if (cmd == "PRINT"){
            cin >> a; 
            if (!graph.exceptionCatcher(a, 1, 1)){
                graph.print(a);
            }
        }else if (cmd == "DELETE"){
            cin >> a;
            if (!graph.exceptionCatcher(a, 1, 1)){
                check = graph.remove(a);
                if (check){
                    cout << "success" << endl;
                }else{
                    cout << "failure" << endl;
                }
            }
        }else if (cmd == "MST"){
            graph.prims(false);
        }else if (cmd == "LOAD"){
            string fName;
            cin >> fName;
            ifstream fin(fName.c_str());
            int blank;
            fin >> blank;
            while (fin >>a >> b >> w){
                graph.insert(a, b, w);
            }
            cout << "success" << endl;
        }else if(cmd == "COST"){
            graph.prims(true);
        }else if (cmd == "END"){
            break;
        }
    }



}
