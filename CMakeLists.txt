﻿# CMakeList.txt : 최상위 CMake 프로젝트 파일, 전역 구성을 수행하고
# 여기에 하위 프로젝트를 포함합니다.
#
cmake_minimum_required (VERSION 3.8)

# 지원되는 경우 MSVC 컴파일러에 대해 핫 다시 로드 사용하도록 설정합니다.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Fuzzing")

add_subdirectory(src)

set(LIBRARIES RandomFuzzer tools)

foreach(LIBRARY ${LIBRARIES})
	set(LIB_OBJS ${LIB_OBJS} $<TARGET_OBJECTS:${LIBRARY}>)
endforeach()

file(GLOB TEST ${CMAKE_SOURCE_DIR}/tests/*.cpp)

add_executable(${PROJECT_NAME} ${TEST} ${LIB_OBJS})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/includes)


