if(EXISTS "/Users/colintaylortaylor/Documents/splineForOptions/build/matrix_tests[1]_tests.cmake")
  include("/Users/colintaylortaylor/Documents/splineForOptions/build/matrix_tests[1]_tests.cmake")
else()
  add_test(matrix_tests_NOT_BUILT matrix_tests_NOT_BUILT)
endif()
