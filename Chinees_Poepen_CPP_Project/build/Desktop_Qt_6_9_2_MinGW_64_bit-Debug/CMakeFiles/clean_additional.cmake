# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Chinees_Poepen_CPP_Project_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Chinees_Poepen_CPP_Project_autogen.dir\\ParseCache.txt"
  "Chinees_Poepen_CPP_Project_autogen"
  )
endif()
