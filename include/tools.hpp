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

    void printVectorDouble(std::vector<double> &v) {

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

    void printVectorString(std::vector<std::string> v) {
        if (v.empty()) std::cout << "empty";
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    }

    void print2DVector(std::vector<std::vector<int>> v){
        if (v.empty()) std::cout << "empty";
        for (int i = 0; i < v.size(); i++) {
            printVectorInt(v[i]);
        }
        std::cout<<"***************************" << std::endl;
    }

    std::vector<std::string> SplitString(const std::string& s, const std::string& c)
    {
        std::vector<std::string> v;
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2-pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
        return v;
    }


    std::vector<std::string> string2Vector(std::string s){
        //["1","2"]
        //去掉[]
        int start,end;
        std::string temp;
        std::vector<std::string> rst={};

        start = s.find_first_of('[');
        end  = s.find_last_of(']');
        s = s.substr(start+1,end-1);
        //逗号分割
        start = 0,end = -1;
        while (true){
            start = s.find('\"',end+1);
            if (start==std::string::npos)break;
            end = s.find('\"',start+1);
            temp = s.substr(start+1,end-start-1);
            rst.push_back(temp);
        }
        return rst;

        //去引号
    }

    std::vector<char> v_string2v_char(std::vector<std::string> v){
        std::vector<char>rst={};
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
        int start ,end ;
        std::string temp;
        std::vector<std::vector<char>> rst;
        std::vector<std::string> tmp_s={};
        std::vector<char> tmp_c={};
        // 去掉前后括号
        start = s.find_first_of('[');
        end  = s.find_last_of(']');
        s = s.substr(start+1,end-1);

        start = 0,end = 0;
        while (true){
            start = s.find('[',end);
            if (start==std::string::npos)break;
            end = s.find(']',start);
            temp = s.substr(start,end-start+1);
//            std::cout<<temp<<std::endl;
            tmp_s = string2Vector(temp);
            tmp_c = v_string2v_char(tmp_s);
            rst.push_back(tmp_c);
        }
        return rst;
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

    int treeDepth(TreeNode *root){
        int height = 0;
        if (root!= nullptr){
            height++;
            int max_left = treeDepth(root->left);
            int max_right = treeDepth(root->right);
            height += std::max(max_left, max_right);
        }
        return height;
    }


    void printTree(TreeNode *root) {
        //todo printTree
        if (root == NULL)return;
        int depth = treeDepth(root);
        std::vector<std::string> v = {};
        std::queue<TreeNode *> q;
        TreeNode *temp;
        q.push(root);


        while (!q.empty()) {
            temp = q.front();
            if (temp != nullptr) {
                q.push(temp->left);
                q.push(temp->right);
                v.push_back(std::to_string(temp->val));
            } else {
                v.emplace_back("NULL");
            }
            q.pop();
        }
        printVectorString(v);// test ok


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
