#include <chrono>
#include <iostream>
using namespace std;

int main() {
    
    const auto start = std::chrono::high_resolution_clock::now();   

    // start code block need to measure
    int i[10000];
    for (int x=0; x < 10000; x++) {
        i[x] = x * 10;
    }
    // end code block need to measure
    
    const auto stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << ". duration=" << duration.count() << "ms\n";
}