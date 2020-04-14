#include "iostream"
#include "vector"
namespace tools{
    using namespace std;
    std::vector<int>array2vector(int arr[]) {
        int s = sizeof(arr);
        std::vector <int> v(arr, arr+s);
        return v;
    }

    void printVector(vector<double>& v) {

        for (int i=0;i<v.size();i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* num2List(int num){
        ListNode* head = new ListNode(0);
        while(num>0){
            ListNode* temp = new ListNode(num%10);
            temp->next = head;
            head = temp;
            num/=10;
        }
        return head;
    }
}
