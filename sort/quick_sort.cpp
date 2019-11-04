#include <iostream>
#include <cstdio>
#include <random>
using namespace std;

#define INF 100
#define LENGTH 150

// Calculate the index of the pivot x
int partition(int* seq, int start, int end){
    int x = seq[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (seq[j] <= x) {
            i++;
            swap(seq[i], seq[j]);
        }
    }
    swap(seq[i + 1], seq[end]);
    return i + 1;
}

int randomized_partition(int* seq, int start, int end) {
    random_device rd{};
    mt19937 mt(rd());
    uniform_int_distribution<> unif(start, end);
    int p = unif(mt);
    swap(seq[p], seq[end]);
    return partition(seq, start, end);
}

void quick_sort(int* seq, int start, int end) {
    int p;
    if (start < end) {
        p = partition(seq, start, end);
        quick_sort(seq, start, p - 1);
        quick_sort(seq, p + 1, end);
    }

}

void randomized_quick_sort(int* seq, int start, int end) {
    int p;
    if (start < end) {
        p = randomized_partition(seq, start, end);
        randomized_quick_sort(seq, start, p - 1);
        randomized_quick_sort(seq, p + 1, end);
    }
}


int main() {
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
    cout << "pre seq:\n";
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    // quick_sort(a, 0, LENGTH - 1);
    randomized_quick_sort(a, 0, LENGTH - 1);
    // Output sorted sequence
    cout << "sorted:\n";
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}