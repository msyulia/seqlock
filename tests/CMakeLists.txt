FIND_PACKAGE (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
INCLUDE_DIRECTORIES (${TEST_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIRS}
        )
ADD_DEFINITIONS (-DBOOST_TEST_DYN_LINK)
ADD_EXECUTABLE (SeqLockTests src/main.cpp)
TARGET_LINK_LIBRARIES (Test
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )