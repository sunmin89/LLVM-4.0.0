# 创建输出目录
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/output)

# 执行优化
add_custom_target(run-instcombine
    COMMAND ${OPT} -S -instcombine ${CMAKE_CURRENT_SOURCE_DIR}/testfile.ll -o ${CMAKE_CURRENT_BINARY_DIR}/output/output1.ll
    COMMENT "Running opt -instcombine on testfile.ll"
)