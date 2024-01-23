# CMakeList.txt: Fuzzing에 대한 CMake 프로젝트, 여기에 소스를 포함하고
# 프로젝트 특정 논리를 정의합니다.
#
Project(Fuzzing LANGUAGES CXX)

add_subdirectory(
    lib
)

# 이 프로젝트의 실행 파일에 소스를 추가합니다.
add_executable (${PROJECT_NAME} "Fuzzing.cpp" "CIF.cpp" )

target_include_directories(${PROJECT_NAME}
	PUBLIC 
	${PROJECT_SOURCE_DIR}/includes
	${PROJECT_SOURCE_DIR}/lib/Fuzzer/RandomFuzzer
	
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

# TODO: 필요한 경우 테스트를 추가하고 대상을 설치합니다.

target_link_libraries(${PROJECT_NAME} RandomFuzzer)
