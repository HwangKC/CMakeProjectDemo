# CMakeList.txt : CMake project for CMakeProjectDemo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (CMakeProjectDemo VERSION 2.4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE MATCHES "Debug")
set(CMAKE_INSTALL_PREFIX "D:/Workspace/projects/General/CMakeProjectDemo/output")

IF (CMAKE_BUILD_TYPE MATCHES "Debug"
        OR CMAKE_BUILD_TYPE MATCHES "None")
    MESSAGE(STATUS "CMAKE_BUILD_TYPE is Debug")
ELSEIF (CMAKE_BUILD_TYPE MATCHES "Release")
    MESSAGE(STATUS "CMAKE_BUILD_TYPE is Release")
ELSEIF (CMAKE_BUILD_TYPE MATCHES "RelWitchDebInfo")
    MESSAGE(STATUS "CMAKE_BUILD_TYPE is RelWitchDebInfo")
ELSEIF (CMAKE_BUILD_TYPE MATCHES "MinSizeRel")
    MESSAGE(STATUS "CMAKE_BUILD_TYPE is MinSizeRel")
ELSE ()
    MESSAGE(STATUS "unknown CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
ENDIF ()



# Add source to this project's executable.
aux_source_directory(. DIR_SRCS)

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )



# 是否使用自己的 MathFunctions 库
option (USE_MYMATH "Use provided math implementation" ON)

# 是否加入 MathFunctions 库
#if (USE_MYMATH)
#  include_directories ("${PROJECT_SOURCE_DIR}/math")
#  add_subdirectory (math)  
#  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
#endif (USE_MYMATH)

if(USE_MYMATH)
  add_subdirectory(math)
  list(APPEND EXTRA_LIBS MathFunctions)
  #list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/math")
endif()

aux_source_directory(./math2 DIR_SUB_SRCS)

add_executable (CMakeProjectDemo ${DIR_SRCS} ${DIR_SUB_SRCS})

target_link_libraries(CMakeProjectDemo ${EXTRA_LIBS})

#target_include_directories(CMakeProjectDemo PUBLIC "${PROJECT_BINARY_DIR}" ${EXTRA_INCLUDES})
target_include_directories(CMakeProjectDemo PUBLIC ${PROJECT_BINARY_DIR} )

# TODO: Add tests and install targets if needed.
install (TARGETS CMakeProjectDemo DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"  DESTINATION include)