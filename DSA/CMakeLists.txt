set(APP_NAME "DSAApp")

file(GLOB_RECURSE TARGET_SRC "src/*.cpp")
file(GLOB_RECURSE TARGET_H "include/*.h")

add_executable(${APP_NAME} ${TARGET_SRC} ${TARGET_H})

target_link_libraries(${APP_NAME} PRIVATE Qt::Core)

target_include_directories(${APP_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
