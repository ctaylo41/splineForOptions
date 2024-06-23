# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-src"
  "/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-build"
  "/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix"
  "/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/tmp"
  "/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp"
  "/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src"
  "/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
