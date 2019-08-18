#include <iostream>
#include <vector>
using namespace std;

int* insertion_sort(int* seq, int len){
    for (int j = 1; j < len; j++){
        int key = seq[j];
        int i = j - 1;
        while (i > -1 && seq[i] > key) {
            seq[i + 1] = seq[i];
            i--;
        }
        seq[i + 1] = key;
    }
    return seq;
}

int main(){
    int a[10] = {3, 2, 5, 7, 1, 9, 10, 8, 19, 0};
    int len = sizeof(a) / sizeof(*a);
    cout << "length: " << len << endl;
    cout << "Unsorted sequence:\n";
    for (int i = 0; i < len; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    int* s_seq = insertion_sort(a, len);
    cout << "Sorted sequence:\n";
    for (int i = 0; i < len; i++){
        cout << s_seq[i] << " ";
    }
    cout << endl;
}