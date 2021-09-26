//
// Created by ming on 2020/10/15.
//

#ifndef CMAKETEST_Q0116_CONNECT_HPP
#define CMAKETEST_Q0116_CONNECT_HPP

#endif //CMAKETEST_Q0116_CONNECT_HPP

#include"tools.hpp"

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    /*        if (root == nullptr) return nullptr;
        std::queue<Node *> que;
        que.push(root);
        while (!que.empty()) {
            int n = que.size();
            for (int i = 0; i < n - 1; ++i) {
                Node *cur = que.front();
                que.pop();
                cur->next = que.front();
                que.push(cur->left);
                que.push(cur->right);
            }
            que.pop();
        }
        return root;*/
    Node *connect(Node *root) {
        //recursion
        if (root == nullptr)return nullptr;
        Node *l = connect(root->left), *r = connect(root->right);
        while (l && r) {
            l->next = r;
            l = l->right;
            r = r->left;
        }
        return root;
    }

    void test() {
        std::cout << "test start" << std::endl;

    }
};