# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Actuator_simulation_autogen"
  "CMakeFiles/Actuator_simulation_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Actuator_simulation_autogen.dir/ParseCache.txt"
  )
endif()
