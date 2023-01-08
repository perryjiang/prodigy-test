function(add_boost_test name)
  cmake_path(GET CMAKE_CURRENT_LIST_DIR PARENT_PATH current_parent_path)
  cmake_path(GET current_parent_path FILENAME library)
  set(target "${name}.test")
  add_executable("${target}" "${name}.cpp")
  target_compile_definitions("${target}" PRIVATE BOOST_TEST_DYN_LINK)
  target_link_libraries("${target}" PRIVATE Boost::unit_test_framework "${library}")
  add_test(NAME "${name}" COMMAND "${target}")
endfunction()