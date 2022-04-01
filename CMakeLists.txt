cmake_minimum_required(VERSION 3.11)

set(PROJECT_NAME session)
project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES C CXX)

# -----------------------------------------------------------------------------

include(FetchContent)
FetchContent_Declare(
    catch2_download
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.4
)

FetchContent_GetProperties(catch2_download)
if(NOT catch2_download_POPULATED)
  FetchContent_Populate(catch2_download)
  add_subdirectory(${catch2_download_SOURCE_DIR} ${catch2_download_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# -----------------------------------------------------------------------------

add_executable(${PROJECT_NAME} src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

#--------------- UNIT TESTING ----------------------------------------------------------

add_executable(${PROJECT_NAME}_test EXCLUDE_FROM_ALL
        test/catch_main.cpp
)

target_include_directories(${PROJECT_NAME}_test
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(NOT hasParent)
        add_custom_target(tests
                COMMAND "${PROJECT_BINARY_DIR}/${PROJECT_NAME}_test"
                DEPENDS ${PROJECT_NAME}_test
        )
endif()

#--------------- CATCH2 STUFF ----------------------------------------------------------

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${catch2_download_SOURCE_DIR}/contrib/")

target_link_libraries(${PROJECT_NAME}_test Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(${PROJECT_NAME}_test)
