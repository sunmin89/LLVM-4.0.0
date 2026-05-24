add_custom_target(LLVMCookBook)
set_target_properties(LLVMCookBook PROPERTIES FOLDER Examples)

macro(add_my_experiment name)
	add_dependencies(LLVMCookBook ${name})
  add_llvm_example(${name} ${ARGN})
endmacro(add_my_experiment)

add_subdirectory(Chapter2)
#add_subdirectory(Experiment3)
