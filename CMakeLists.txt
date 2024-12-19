cmake_minimum_required(VERSION 3.16)

project(searchusinglinkedlist LANGUAGES C)

add_executable(searchusinglinkedlist main.c)

include(GNUInstallDirs)
install(TARGETS searchusinglinkedlist
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
