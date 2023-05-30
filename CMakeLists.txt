cmake_minimum_required(VERSION 3.10)
project(ppC LANGUAGES C CXX)

# set(CMAKE_C_STANDARD 11)

#add_executable(ppC
#        "Program 1 (hw)/Program01/Program01/Program01.c"
#        "Program 1 (hw)/Program01/Program01/Program01A.c"
#        "Program 1 (hw)/Program01/Program01/Program01B.c"
#        "Program 1 (hw)/Program01/Program01/Program01C.c"
#        "Program 1 (hw)/Program01/Program01/Program01D.c"
#        "Program 1 (hw)/Program01/Program01/Program01E.c"
#        "Program 2 (temp)/Program02/Temperatura1.c"
#        "Program 2 (temp)/Program02/Temperatura1A.c"
#        "Program 2 (temp)/Program02/Temperatura1B.c"
#        "Program 2 (temp)/Program02/Temperatura1C.c"
#        "Program 2 (temp)/Program02/Temperatura1D.c"
#        "Program 2 (temp)/Program02/Temperatura1Dint.c"
#        "Program 2 (temp)/Program02/Temperatura1E.c"
#        "Program 2 (temp)/Program02/Temperatura2.c"
#        "Program 2 (temp)/Program02/Temperatura2A.c"
#        "Program 2 (temp)/Program02/Temperatura2B.c"
#        "Program 2 (temp)/Program02/Temperatura2C.c"
#        "Program 2 (temp)/Program02/Temperatura2D.c"
#        "Program 2 (temp)/Program02/Temperatura2E.c"
#        "Program 2 (temp)/Program02/Temperatura2F.c")
add_executable(P04 "Program04/silnia.c")
add_executable(P09 "Program09/macierze.c")
add_executable(P10 Program10/zespolone.c Program10/TypZespolone.c Program10/TypZespolone.h)
target_compile_options(P10 PRIVATE -pedantic -Wall)
target_link_libraries(P10 m)