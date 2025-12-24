cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("pga")

file(GLOB PGA_HEADERS "*.h")
file(GLOB PGA_SOURCES "*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/pga)

add_library (pga STATIC ${PGA_HEADERS} ${PGA_SOURCES})
target_include_directories(pga PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIRS})
target_link_libraries(pga PUBLIC math ${Boost_LIBRARIES}  ${OpenCASCADE_LIBRARIES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET pga PROPERTY CXX_STANDARD 20)
endif()

install(TARGETS pga ARCHIVE DESTINATION lib)
install(FILES ${PGA_HEADERS} DESTINATION include/pga)
