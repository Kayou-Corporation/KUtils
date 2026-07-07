# --------------------------------------- #
#               CMAKE CONFIG              #
# --------------------------------------- #

# Define minimum CMake version required
cmake_minimum_required(VERSION 3.20)

# Define Project Name
project(KUtils VERSION 1.0.0 LANGUAGES CXX)

# Add as interface
add_library(KUtils INTERFACE)

add_library(KUtils::KUtils ALIAS KUtils)

target_include_directories(KUtils INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
    $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)

install(TARGETS KUtils
    EXPORT KUtilsTarget
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT KUtilsTarget
    FILE KUtils.cmake
    NAMESPACE KUtils::
    DESTINATION ${CMAKE_INSTALL_DATADIR}/KUtils/cmake
)