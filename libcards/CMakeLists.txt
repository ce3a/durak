project(libcards)

add_library(cards "")
target_link_libraries(cards utils)
target_sources(cards PRIVATE card.cpp deck.cpp)
target_include_directories(cards PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
