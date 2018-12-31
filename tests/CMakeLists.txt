project(tests)

macro(_add_test _name)
    set(_tgt test_${_name})
    add_executable(${_tgt} ${_tgt}.cpp)
    target_link_libraries(${_tgt} Boost::unit_test_framework)
    target_compile_definitions(${_tgt} PRIVATE "BOOST_TEST_DYN_LINK=1")
    target_compile_definitions(${_tgt} PRIVATE "BOOST_TEST_MODULE=${_tgt}")
    add_test(${_name} ${_tgt})
endmacro()

_add_test(iterable_enums)
target_link_libraries(test_iterable_enums utils)

_add_test(card)
target_link_libraries(test_card cards)

_add_test(deck)
target_link_libraries(test_deck cards)

# vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
