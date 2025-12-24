cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("math")

file(GLOB MATH_HEADERS "*.h")
file(GLOB MATH_SOURCES "*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/math)

add_library (math STATIC ${MATH_HEADERS} ${MATH_SOURCES})
# 设置头文件路径， PUBLIC 表示依赖方会继承该路径
target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET math PROPERTY CXX_STANDARD 20)
endif()

install(TARGETS math ARCHIVE DESTINATION lib)
install(FILES ${MATH_HEADERS} DESTINATION include/math)
