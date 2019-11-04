#include <iostream>
#include <cstdio>
#include <vector>
#include <random>
using namespace std;

#define INF 1000
#define LENGTH 15

void bubble_sort(int* seq, int len){
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i; j++) {
            // cout << len - 1 - j << " : " << len - j << endl;
            if (seq[len - j - 2] > seq[len - j - 1]) {
                swap(seq[len - j - 2], seq[len - j - 1]);
            }
        }
    }
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
    // Output generated sequence
    cout << "pre seq:\n";
    for (int i = 0; i < len; i++) {
        cout << i << ": " << a[i] << endl;
    }
    bubble_sort(a, len);
    // Output sorted sequence
    cout << "sorted:\n";
    for (int i = 0; i < len; i++) {
        cout << i << ": " << a[i] << endl;
    }

}