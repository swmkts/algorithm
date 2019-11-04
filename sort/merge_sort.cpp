#include <iostream>
#include <cstdio>
#include <random>
using namespace std;

#define INF 10000
#define LENGTH 15000


void merge_sort(int* seq, int start, int end);
void conquer(int* seq, int left_start, int left_end, int right_start, int right_end);

void merge_sort(int* seq, int start, int end){
    if (start == end) {
        return;
    }
    int left_start = start;
    int left_end;
    left_end = (end - start) / 2 + start;
    int right_start = left_end + 1;
    int right_end = end;
    merge_sort(seq, left_start, left_end);
    merge_sort(seq, right_start, right_end);
    conquer(seq, left_start, left_end, right_start, right_end);
    return;
}

void conquer(int* seq, int left_start, int left_end, int right_start, int right_end){
    int i = 0, j = 0, k = 0;
    int c_sort[right_end - left_start + 1];
    while (i < left_end - left_start + 1 && j < right_end - right_start + 1) {
        if (seq[left_start + i] <= seq[right_start + j]) {
            c_sort[k] = seq[left_start + i];
            i++;
        } else if (seq[left_start + i] > seq[right_start + j]) {
            c_sort[k] = seq[right_start + j];
            j++;
        }
        k++;
    }
    while (i < left_end - left_start + 1) {
        c_sort[k] = seq[left_start + i];
        i++;
        k++;
    }
    while (j < right_end - right_start + 1){
        c_sort[k] = seq[right_start + j];
        j++;
        k++;
    }
    for (int i = 0; i < right_end - left_start + 1; i++) {
        seq[left_start + i] = c_sort[i];
    }
    cout << endl;
}

int main(){
    // generate random sequence with length "len" with random integer from 0 to 1000. 
    random_device rd{};
    mt19937 mt(rd());
    uniform_int_distribution<> unif(0, INF);
    
    int len = LENGTH;
    int a[len];
    for (int i = 0; i < len; i++) {
        a[i] = unif(mt);
    }
    // // Output generated sequence
    // cout << "pre seq:\n";
    // for (int i = 0; i < len; i++) {
    //     cout << i << ": " << a[i] << endl;
    // }
    merge_sort(a, 0, len - 1);
    // Output sorted sequence
    cout << "sorted:\n";
    for (int i = 0; i < len; i++) {
        cout << i << ": " << a[i] << endl;
    }

}