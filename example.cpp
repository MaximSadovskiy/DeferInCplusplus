#include <iostream>
#include "defer.h"

void example_function_delete(void* ptrToSomeData) {
    std::cout<< "Deleting zig(garbage)...\n";
    delete[] (char*) ptrToSomeData;
}

int main(void) {
    auto* str = new char[14] {0};
    memcpy_s(str, 13, "Defer printf", 13);
    defer( { example_function_delete(str); } )
    
    defer({
        printf("---------\n");
        printf("%s\n", str);
        printf("---------\n");
        defer({
            puts("\tDefer inside defer...");
        })
    })
    puts("End of main");
    return 0;
}