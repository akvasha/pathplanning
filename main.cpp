#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    long n = std::strtol(argv[1], nullptr, 10);
    for (long i = 0; i < n; ++i) {
        std::cout << "Path planning\n";
    }
    return 0;
}