add_custom_target(LLVMCookBook)
set_target_properties(LLVMCookBook PROPERTIES FOLDER Examples)

# 设置 LLVM 工具路径（根据你的环境修改）
set(LLVM_BIN /workspace/install-release-AArch64/bin)
set(OPT ${LLVM_BIN}/opt)
set(CLANG ${LLVM_BIN}/clang)
set(LLVM_AR ${LLVM_BIN}/llvm-ar)

macro(add_my_experiment name)
	add_dependencies(LLVMCookBook ${name})
  add_llvm_example(${name} ${ARGN})
endmacro(add_my_experiment)

add_subdirectory(Chapter1)
add_subdirectory(Chapter2)
#add_subdirectory(Experiment3)
