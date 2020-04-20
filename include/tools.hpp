#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"
#include "map"
#include "fstream"


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

// ListNode************************************************************
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode *num2List(int num) {
        ListNode *head = new ListNode(0);
        while (num > 0) {
            ListNode *temp = new ListNode(num % 10);
            temp->next = head;
            head = temp;
            num /= 10;
        }
        return head;
    }

// Matrix***************************************************************
    void print_matrix(std::vector<std::vector<int>> matrix) {
        if(!matrix.size()){
            std::cout << "empty"<<std::endl;
            return;
        }

        int ly = matrix.size(), lx = matrix[0].size();
        for (int y = 0; y < ly; y++) {
            int x = 0;
            for (x = 0; x < lx; x++) std::cout << matrix[y][x] << '\t';
            std::cout << std::endl;
        }
        std::cout << "************************************"<<std::endl;
    }

    std::vector<std::vector<int>> array2matrix(int a[],int col,int row) {
        if(col==0){
            std::vector<std::vector<int>> m;
            return m;
        }
        int ly = row, lx = col;
        std::vector<std::vector<int> > matrix(ly, std::vector<int>(lx, 0));
        for (int y = 0; y < ly; y++) {
            int x = 0;
            for (x = 0; x < lx; x++) matrix[y][x]=a[y*col+x];
        }
        return matrix;
    }

// files***************************************************************
    std::vector<std::vector<int>> matrix_read(std::string filename){
        std::ifstream infile;
        infile.open(filename);
        if (!infile.is_open()) std::cout << "open file failure" << std::endl;
        while(infile.good() && !infile.eof())
        {
            std::string buf;
            //todo
        }
        infile.close();

    }


}
