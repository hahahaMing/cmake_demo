//
// Created by ming on 2020/8/12.
//

#ifndef CMAKETEST_Q0133_CLONEGRAPH_HPP
#define CMAKETEST_Q0133_CLONEGRAPH_HPP

#endif //CMAKETEST_Q0133_CLONEGRAPH_HPP

#include"tools.hpp"

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = std::vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node *>();
    }

    Node(int _val, std::vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    void copy_val_only(Node *node, std::map<Node *, Node *> &rcd) {
        if (rcd.find(node) == rcd.end()) {
            rcd[node] = new Node(node->val);
        }else return;
        for (auto i:node->neighbors) {
            copy_val_only(i, rcd);
        }
    }

public:
    Node *cloneGraph(Node *node) {
        /*
         * 遍历节点，建立map对应上，然后再遍历一遍map更新其中的vector
         *
         */
        if(node==nullptr)return nullptr;
        std::map<Node *, Node *> rcd;
        copy_val_only(node, rcd);
        for (auto i:rcd) {
            for (auto j:i.first->neighbors) {
                i.second->neighbors.push_back(rcd[j]);
            }
        }
        return rcd[node];
    }
};