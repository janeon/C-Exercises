#include "Coloring.hpp"
#include <iostream>
#include <tuple>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
// Did not pass 6th sample case :(
using namespace std;
int Coloring::main(){
    vector<vector<int>> vertices; string first; getline(cin,first); int n; stringstream(first) >> n;
    vector<string> lines; string line;
    // cout << n << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, line); stringstream stream(line);
        vector<int> values; int n;
        while(stream >> n)
            values.push_back(n);
        vertices.push_back(values);
        // for (int edges : values) cout << edges << " ";
    }
    // sort(vertices.begin(), vertices.end(), [](const std::vector<int>& a, const std::vector<int>& b) { return a.size() > b.size(); }); // cannot sort original vertices for the purpose of labeling them, instead we sort tuples
    vector<tuple<int,int>> list;
    for (int k = 0; k < vertices.size(); k++) {
        vector<int> vertex = vertices.at(k);
        // cout << "on vertex: " << k << endl;
        list.push_back(make_tuple(vertex.size(), k));
    }
    
    sort(list.begin(),list.end());
    
    // for (auto tuple: list)  cout << "label: " << get<1>(tuple) << endl;
    
    
    
    // order the vertices by degree
    vector<int> colors(n,0); // initializing all vertices to be uncolored i.e. 0
    // start coloring from largest degree vertex
    int total = 0;
    
    for (auto element: list) {
        int i = get<1>(element);
        // no need to color an already colored vector
        if (colors.at(i) != 0) continue;
        // initializing stack
        stack<int> mystack; mystack.push(i);
        while (!mystack.empty()) {
            int current = mystack.top();
            // cout << "currently examining vertex: " << current << endl;
            // start checking from the first color
            int color = 1;
            
            // check that no neighbors use the same color
            while (colors.at(current) == 0) { // while vertex has no assigned color
                
                bool used = false; // cout << "which has these uncolored neighbors: ";
                
                for (int neighbor: vertices.at(current)) {
                    // check that all neighbor use a different color
                    if (colors.at(neighbor) == color) {
                        used = true; color++; break;
                    }
                    if (colors.at(neighbor) == 0 && neighbor != current) {
                        // cout << neighbor << " ";
                        mystack.push(neighbor);
                    }
                }
                if (!used) colors.at(current) = color; // cout << endl;
            } // vertex should now have been assigned a color
            // for (int c:colors) cout << c << " "; cout << endl;
            mystack.pop();
            if (total < color) total = color;
            
        }
    }
    cout << total;
    // for (auto color : colors) cout << color << endl;
    
    
    
    return 0;
}

