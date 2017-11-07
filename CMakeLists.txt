cmake_minimum_required(VERSION 3.8)
project(router)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LegosInterface.h LucesInterface.h MensajeRed.cpp MensajeRed.h MensajeFisico.cpp MensajeFisico.h Router.cpp Router.h RoutingTable.cpp RoutingTable.h Socket.cpp Socket.h LegosInterface.cpp RouterInterface.h SocketThread.cpp SocketThread.h)
find_package( Threads )
add_executable(router ${SOURCE_FILES})
target_link_libraries(router ${CMAKE_THREAD_LIBS_INIT})