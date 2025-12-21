# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\NEWtestCPP_PJ_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\NEWtestCPP_PJ_autogen.dir\\ParseCache.txt"
  "NEWtestCPP_PJ_autogen"
  )
endif()
