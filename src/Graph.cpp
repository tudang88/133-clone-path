#include <iostream>
#include "Graph.h"
using namespace std;

/**
 * dfs solution
*/
Node *Solution::dfs(Node *node)
{
    // empty graph or only one node graph
    if (!node ) return nullptr;
    // already visited node
    if (recordMap.count(node->val) > 0) {
        return recordMap[node->val];
    }
    // new node
    Node *newNode = new Node(node->val);
    recordMap[node->val] = newNode;
    // add neighbors
    for (auto neighbor: node->neighbors) {
        newNode->neighbors.push_back(dfs(neighbor));
    }

    return newNode;
}
/**
 * Breath first search solution
*/
Node *Solution::cloneGraph(Node *node)
{
    // empty graph or only one node graph
    if (!node ) return nullptr;
    queue<Node*> q;
    unordered_map<int, Node*> map;
    q.push(node);
    map[node->val] = new Node(node->val);
    while(q.size()) {
        // step 1: pick up original node
        Node *currentNode = q.front();
        q.pop();
        // step 2: pick up new graph node
        Node *nNode = map.at(currentNode->val);
        // step 3: pick up adjencyList
        for (auto node : currentNode->neighbors) {
            // record non-service node
            if (map.find(node->val) == map.end()) {
                map[node->val] = new Node(node->val);
                q.push(node);
            }
            // step 4: add to adjencyList
            nNode->neighbors.push_back(map[node->val]);
        }
    }
    return map[node->val];
}

/**
 * print graph for confirming
*/
void Solution::printGraph(Node *node)
{
    queue<Node*> q;
    unordered_map<int, Node*> map;
    q.push(node);
    map[node->val] = node;
    cout << "[";
    while(q.size()) {
        Node *cur = q.front();
        cout << cur->val<< ":";
        q.pop();
        // adjcencyList
        vector<Node*> adjList = cur->neighbors;
        cout<< "[";
        for (auto it = adjList.begin() ;it != adjList.end(); it++) {
            int val = (*it)->val; 
            cout << val; 
            if (map.find(val) == map.end()) {
                q.push(*it);
                map[val] = *it;
            }
            // print comma
            if ((it + 1) != adjList.end()) cout<<",";
        }
        cout<<"]";
        // print comma
        if (q.size()>0) cout<<",";
    }
    cout << "]";
}
