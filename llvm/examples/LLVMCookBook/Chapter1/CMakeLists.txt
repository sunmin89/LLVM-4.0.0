# 创建输出目录
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/output)

# 执行优化
add_custom_target(opt-instcombine
    COMMAND ${OPT} -S -instcombine ${CMAKE_CURRENT_SOURCE_DIR}/testfile.ll -o ${CMAKE_CURRENT_BINARY_DIR}/output1.ll
    COMMENT "Running opt -instcombine on testfile.ll"
)

add_custom_target(opt-deadargelim 
    COMMAND ${OPT} -S -deadargelim ${CMAKE_CURRENT_SOURCE_DIR}/testfile.ll -o ${CMAKE_CURRENT_BINARY_DIR}/output2.ll
    COMMENT "Running opt -deadargelim on testfile.ll"
)

# clang
add_custom_target(clang-emit-llvm 
    COMMAND ${CLANG} -emit-llvm -S ${CMAKE_CURRENT_SOURCE_DIR}/multiply.c -o ${CMAKE_CURRENT_BINARY_DIR}/multiply.ll
    COMMENT "Running clang -emit-llvm -S multiply.c -o multiply.ll"
)

# 添加到主目标
add_dependencies(LLVMCookBook 
    opt-instcombine 
    opt-deadargelim
    clang-emit-llvm
)
