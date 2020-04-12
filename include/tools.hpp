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
}
