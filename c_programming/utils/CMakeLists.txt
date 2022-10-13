cmake_minimum_required(VERSION 3.15.3)
project(utils_c.elf)

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(./ DIR_SRCS)
SET(SRC_PATH ${DIR_SRCS})

IF(WIN32)
    MESSAGE(STATUS "Now is windows")
    SET(SRC_PATH ${DIR_SRCS})
    include_directories(./)
#    link_libraries(
#            ${openssl_dir}/lib/libssl.lib
#            -lws2_32
#    )
    add_executable(${PROJECT_NAME} ${SRC_PATH})

ELSEIF(APPLE)

    MESSAGE(STATUS "Now is apple")
    SET(SRC_PATH ${DIR_SRCS})
    include_directories(./)
#    link_libraries(
#            ${openssl_dir}/lib/libssl.lib
#            -lws2_32
#    )
    add_executable(${PROJECT_NAME} ${SRC_PATH})


ELSEIF(UNIX)
    MESSAGE(STATUS "Now is Linux")
    SET(SRC_PATH ${DIR_SRCS})
    include_directories(./)
#    link_libraries(
#            ${openssl_dir}/lib/libssl.lib
#            -lws2_32
#    )
    add_executable(${PROJECT_NAME} ${SRC_PATH})

ENDIF()