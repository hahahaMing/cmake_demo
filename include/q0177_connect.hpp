//
// Created by ming on 2020/9/28.
//

#ifndef CMAKETEST_Q0177_CONNECT_HPP
#define CMAKETEST_Q0177_CONNECT_HPP

#endif //CMAKETEST_Q0177_CONNECT_HPP

#include"tools.hpp"

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node *connect(Node *root) {
        /*
         *  建立两个栈，逐层存储
         */
        if (root == nullptr)return root;
        std::queue<Node *> cur_level, next_level;
        cur_level.push(root);
        Node *tmp, *tmp_next = nullptr;
        while (!cur_level.empty()) {
            tmp = cur_level.front();
            tmp->next = tmp_next;
            tmp_next = tmp;
            cur_level.pop();
            if (tmp->right != nullptr)next_level.push(tmp->right);
            if (tmp->left != nullptr)next_level.push(tmp->left);
            if (cur_level.empty()) {
                std::swap(cur_level, next_level);
                tmp_next = nullptr;
            }
        }
        return root;
    }
};