# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/w017289m/Documents/lowlevel/out/build/x64-Debug/_deps/ogg-src"
  "C:/Users/w017289m/Documents/lowlevel/out/build/x64-Debug/_deps/ogg-build"
  "C:/Users/w017289m/Documents/lowlevel/out/build/x64-Debug/_deps/ogg-subbuild/ogg-populate-prefix"
  "C:/Users/w017289m/Documents/lowlevel/out/build/x64-Debug/_deps/ogg-subbuild/ogg-populate-prefix/tmp"
  "C:/Users/w017289m/Documents/lowlevel/out/build/x64-Debug/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp"
  "C:/Users/w017289m/Documents/lowlevel/out/build/x64-Debug/_deps/ogg-subbuild/ogg-populate-prefix/src"
  "C:/Users/w017289m/Documents/lowlevel/out/build/x64-Debug/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/w017289m/Documents/lowlevel/out/build/x64-Debug/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/w017289m/Documents/lowlevel/out/build/x64-Debug/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
