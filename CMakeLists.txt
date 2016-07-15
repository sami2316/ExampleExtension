
cmake_minimum_required(VERSION 2.8.12)
string(ASCII 27 ESC)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

project(example_extension)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

  
# Name of extension.
set(TARGET example_extension.ext)

find_package(Osquery REQUIRED)

include_directories(BEFORE ${OSQUERY_INCLUDE_DIRS})
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(BEFORE ${CMAKE_BINARY_DIR}/src)

set(LINK_LIBS ${LINK_LIBS}  ${OSQUERY_LIBRARY} )

set(CMAKE_CXX_FLAGS "-I ${OSQUERY_INCLUDE_DIR} ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

include(RequireCXX11)


# Platform specifics.
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(LINK_LIBS ${LINK_LIBS} "-lpthread")

    # TODO: Better ways to handle these?
    set(LINK_LIBS ${LINK_LIBS} "-lboost_thread -lboost_system -lboost_filesystem -lthrift -lcrypto -ldl -lglog -lthriftz -lgflags -lrocksdb -lz -lbz2 -lsnappy")

elseif (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
    message(FATAL_ERROR "FreeBSD not yet tried.")

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    message(FATAL_ERROR "Darwin not yet tried.")

else ()
    message(FATAL_ERROR "Platform ${CMAKE_SYSTEM_NAME} not supported.")
endif ()

set(SRCS
    src/sdk_example.cpp
)



#SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_executable(${TARGET} ${SRCS})
target_link_libraries(${TARGET} ${LINK_LIBS})

install(TARGETS ${TARGET} RUNTIME DESTINATION bin)


message(
    "\n==================|  Bro-Osquery Config Summary  |===================="
    "\nInstall prefix:   ${CMAKE_INSTALL_PREFIX}"
    "\nOsquery prefix:   ${OSQUERY_ROOT_DIR}"
    "\n"
    "\nLink libraries:   ${LINK_LIBS}"
    "\nCC:               ${CMAKE_C_COMPILER}"
    "\nCFLAGS:           ${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_${BuildType}}"
    "\nCXX:              ${CMAKE_CXX_COMPILER}"
    "\nCXXFLAGS:         ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_${BuildType}}"
    "\n=================================================================")

include(UserChangedWarning)
