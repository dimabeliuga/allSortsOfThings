#include "Templates.h"

void userImplementation::outputAllNumberBits(int64_t num){
    for(int i = 0; i < 64; ++i){
        bool bit = num & (1 << i);
        std::cout << bit;
    }
}
    