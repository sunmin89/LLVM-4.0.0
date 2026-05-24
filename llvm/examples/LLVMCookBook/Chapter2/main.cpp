#include "llvm/Support/raw_ostream.h"
#include <cstdio>

int main() {
    printf("Test basic LLVM link\n");
    llvm::outs() << "LLVM outs works\n";
    return 0;
}
