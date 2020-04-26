#include <sstream>
#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"
#include "map"
#include "fstream"
#include "queue"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


namespace tools {
//    using namespace std;
    std::vector<int> array2vector(int arr[]) {
        int s = sizeof(arr);
        std::vector<int> v(arr, arr + s);
        return v;
    }

    void printVector(std::vector<double> &v) {

        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    }

    void printVectorInt(std::vector<int> v) {
        if (v.empty()) std::cout << "empty";
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
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

    void printList(ListNode* head){
        while (head!=NULL){
            std::cout << head->val<<"->";
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

// Binary tree*********************************************************
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
