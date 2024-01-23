# lib/Fuzzer/RandomFuzzer/CMakeLists.txt

add_library(RandomFuzzer
	RandomFuzzer.cpp
)

target_include_directories(RandomFuzzer
	PUBLIC ${PROJECT_SOURCE_DIR}/includes
)

target_compile_options(RandomFuzzer PRIVATE -Wall -Werror)
