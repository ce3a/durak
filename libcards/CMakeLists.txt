project(libcards)

add_library(cards "")
add_subdirectory(src)
target_include_directories(cards
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(cards utils)

# vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
