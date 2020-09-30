#include <sstream>
#include "iostream"
#include "stdlib.h"
#include "vector"
#include "cmath"
#include "algorithm"
#include "map"
#include "fstream"
#include "queue"
#include "unordered_map"
#include "unordered_set"
#include "stack"


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


namespace tools {
    void vector_delete(std::vector<int> &v, int k) {
        for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {        //从vector中删除指定的某一个元素
            if (*iter == k) {
                v.erase(iter);
                break;
            }
        }

    }


    std::vector<int> array2vector(int arr[]) {
        int s = sizeof(arr);
        std::vector<int> v(arr, arr + s);
        return v;
    }

    void printVectorDouble(std::vector<double> &v) {

        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    }

    void printVectorInt(std::vector<int> v) {
        if (v.empty()) std::cout << "[]";
        std::cout << "[";
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i];
            if (i != v.size() - 1)std::cout << ',';
        }
        std::cout << "]";
    }

    void printVectorString(std::vector<std::string> v) {
        if (v.empty()) std::cout << "empty";
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    }

    void print2DVector(std::vector<std::vector<int>> v) {
        if (v.empty()) std::cout << "empty";
        for (int i = 0; i < v.size(); i++) {
            printVectorInt(v[i]);
        }
        std::cout << "***************************" << std::endl;
    }

    void printMap(std::map<char, int> m) {
        std::cout << "{";
        for (auto i = m.begin(); i != m.end(); i++) {
            std::cout << "[" << i->first << "]:" << i->second << ";";
        }
        std::cout << "}" << std::endl;
    }

    void printMap(std::map<char, std::vector<int>> m) {
        std::cout << "{";
        for (auto i = m.begin(); i != m.end(); i++) {
            std::cout << "[" << i->first << "]:";
            printVectorInt(i->second);
            std::cout << ";";
        }
        std::cout << "}" << std::endl;
    }

    std::vector<std::string> SplitString(const std::string &s, const std::string &c) {
        std::vector<std::string> v;
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while (std::string::npos != pos2) {
            v.push_back(s.substr(pos1, pos2 - pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if (pos1 != s.length())
            v.push_back(s.substr(pos1));
        return v;
    }


    std::vector<std::string> string2Vector(std::string s) {
        //["1","2"]
        //去掉[]
        int start, end;
        std::string temp;
        std::vector<std::string> rst = {};

        start = s.find_first_of('[');
        end = s.find_last_of(']');
        s = s.substr(start + 1, end - 1);
        //逗号分割
        start = 0, end = -1;
        while (true) {
            start = s.find('\"', end + 1);
            if (start == std::string::npos)break;
            end = s.find('\"', start + 1);
            temp = s.substr(start + 1, end - start - 1);
            rst.push_back(temp);
        }
        return rst;

        //去引号
    }

    std::vector<char> v_string2v_char(std::vector<std::string> v) {
        std::vector<char> rst = {};
        for (auto i :v) {
            rst.push_back(i.c_str()[0]);
        }
        return rst;
    }




// ListNode************************************************************


    ListNode *num2List(int num) {
        ListNode *head = NULL;
        while (num > 0) {
            ListNode *temp = new ListNode(num % 10);
            temp->next = head;
            head = temp;
            num /= 10;
        }
        return head;
    }

    void printList(ListNode *head) {
        while (head != NULL) {
            std::cout << head->val << "->";
            head = head->next;
        }
        std::cout << std::endl;
    }


// Matrix***************************************************************
    void print_matrix(std::vector<std::vector<int>> matrix) {
        if (!matrix.size()) {
            std::cout << "empty" << std::endl;
            return;
        }

        int ly = matrix.size(), lx = matrix[0].size();
        for (int y = 0; y < ly; y++) {
            int x = 0;
            for (x = 0; x < lx; x++) std::cout << matrix[y][x] << '\t';
            std::cout << std::endl;
        }
        std::cout << "************************************" << std::endl;
    }

    void print_matrix(std::vector<std::vector<char>> matrix) {
        if (!matrix.size()) {
            std::cout << "empty" << std::endl;
            return;
        }

        int ly = matrix.size(), lx = matrix[0].size();
        for (int y = 0; y < ly; y++) {
            int x = 0;
            for (x = 0; x < lx; x++) std::cout << matrix[y][x] << '\t';
            std::cout << std::endl;
        }
        std::cout << "************************************" << std::endl;
    }

    std::vector<std::vector<int>> array2matrix(int a[], int col, int row) {
        if (col == 0) {
            std::vector<std::vector<int>> m;
            return m;
        }
        int ly = row, lx = col;
        std::vector<std::vector<int> > matrix(ly, std::vector<int>(lx, 0));
        for (int y = 0; y < ly; y++) {
            int x = 0;
            for (x = 0; x < lx; x++) matrix[y][x] = a[y * col + x];
        }
        return matrix;
    }

    std::vector<std::vector<char>> string2matrix(std::string s) {
        // e.g.    [["1","1"],["1","1"]]
        int start, end;
        std::string temp;
        std::vector<std::vector<char>> rst;
        std::vector<std::string> tmp_s = {};
        std::vector<char> tmp_c = {};
        // 去掉前后括号
        start = s.find_first_of('[');
        end = s.find_last_of(']');
        s = s.substr(start + 1, end - 1);

        start = 0, end = 0;
        while (true) {
            start = s.find('[', end);
            if (start == std::string::npos)break;
            end = s.find(']', start);
            temp = s.substr(start, end - start + 1);
//            std::cout<<temp<<std::endl;
            tmp_s = string2Vector(temp);
            tmp_c = v_string2v_char(tmp_s);
            rst.push_back(tmp_c);
        }
        return rst;
    }

    std::vector<std::vector<int>> string2matrixInt(std::string s) {
        // todo
    }

// Binary tree*********************************************************
    //中序遍历
    std::vector<TreeNode *> inorderTraversal(TreeNode *root) {
        std::vector<TreeNode *> res;
        std::stack<TreeNode *> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root);
            root = root->right;
        }
        return res;
    }

    void trimLeftTrailingSpaces(std::string &input) {
        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
            return !isspace(ch);
        }));
    }

    void trimRightTrailingSpaces(std::string &input) {
        input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
            return !isspace(ch);
        }).base(), input.end());
    }

    TreeNode *stringToTreeNode(std::string input) {
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
        input = input.substr(1, input.length() - 2);
        if (!input.size()) {
            return nullptr;
        }

        std::string item;
        std::stringstream ss;
        ss.str(input);

        getline(ss, item, ',');
        TreeNode *root = new TreeNode(stoi(item));
        std::queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);

        while (true) {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();

            if (!getline(ss, item, ',')) {
                break;
            }

            trimLeftTrailingSpaces(item);
            if (item != "null") {
                int leftNumber = stoi(item);
                node->left = new TreeNode(leftNumber);
                nodeQueue.push(node->left);
            }

            if (!getline(ss, item, ',')) {
                break;
            }

            trimLeftTrailingSpaces(item);
            if (item != "null") {
                int rightNumber = stoi(item);
                node->right = new TreeNode(rightNumber);
                nodeQueue.push(node->right);
            }
        }
        return root;
    }

    int treeDepth(TreeNode *root) {
        int height = 0;
        if (root != nullptr) {
            height++;
            int max_left = treeDepth(root->left);
            int max_right = treeDepth(root->right);
            height += std::max(max_left, max_right);
        }
        return height;
    }


    void printTree(TreeNode *root) {
/*//        if (root == NULL)return;
//        std::vector<std::string> v = {};
//        std::queue<TreeNode *> q;
//        std::queue<int> depth;
//        TreeNode *temp;
//        int td ;
//        q.push(root);
//        depth.push(1);
//
//        while (!q.empty()) {
//            temp = q.front();
//            td = depth.front();
//            if (temp != nullptr) {
//                q.push(temp->left);
//                q.push(temp->right);
//                depth.push(td+1);
//                depth.push(td+1);
//                std::cout<<temp->val<<'\t';
//                v.push_back(std::to_string(temp->val));
//            } else {
//                v.emplace_back("NULL");
//                std::cout<<'\t';
//            }
//            q.pop();
//            depth.pop();
//            if (td<depth.front())std::cout<<std::endl;
//        }
//        printVectorString(v);// test ok*/
        /*
         * 中序与层序遍历
         * 按中序遍历结果判断每层应打印什么
         */
        if (!root)return ;
        auto tmp = root;
        std::vector<TreeNode *> intv = inorderTraversal(tmp);
        std::string template_str;
        int location = 0;
        std::unordered_map<TreeNode*,int> first_locations;
        for (auto & i : intv) {
            location = template_str.size();
            template_str+=std::to_string(i->val)+" ";
            first_locations[i]=location;
        }
        for(auto &i:template_str)i=' ';
        //层序
        std::queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            int cur_loc = 0;
            std::string tmp_str1 = template_str,tmp_str2 = template_str;
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                cur_loc = first_locations[node];
                std::string num_str = std::to_string(node->val);
                //左边
                if (node->left){
                    q.push(node->left);
                    int first_loc = first_locations[node->left]+1;
                    tmp_str2[first_loc++]='/';
                    while (first_loc<cur_loc)tmp_str1[first_loc++]='_';

                }
                //中间
                for (int j = 0; j < num_str.length(); ++j,++cur_loc ) {
                    tmp_str1[cur_loc]=num_str[j];
                }
                //右边
                if (node->right) {
                    q.push(node->right);
                    int last_loc = first_locations[node->right]-1;
                    tmp_str2[last_loc]='\\';
                    while (cur_loc<last_loc){
                        tmp_str1[cur_loc++]='_';
                    }
                }

            }
            std::cout<<tmp_str1<<std::endl;
            std::cout<<tmp_str2<<std::endl;
        }


    }


// Files***************************************************************
    std::vector<std::vector<int>> matrix_read(std::string filename) {
        std::ifstream infile;
        infile.open(filename);
        if (!infile.is_open()) std::cout << "open file failure" << std::endl;
        while (infile.good() && !infile.eof()) {
            std::string buf;
            //todo read file
        }
        infile.close();

    }


}
