## linux ou windows + wsl ubuntu apenas

cmake_minimum_required(VERSION 3.2)
project(Autocomplete)

#include(./ncurses.cmake)

#com ncurses
#add_executable(words_complete_correct_extra
#              src/main_ncurses.cpp)
#target_include_directories(words_complete_correct_extra PUBLIC
#                          ./include
#                         ${NCURSES_INCLUDES}/ncurses)
#target_link_libraries(words_complete_correct_extra ncurses)


#sem ncurses
add_executable(words_complete_correct
               src/main.cpp
               src/Dados.cpp
               src/AutoComplete.cpp
               src/AutoCorrect.cpp
               src/Interface.cpp
              )
              
target_include_directories(words_complete_correct PUBLIC
                           include
                           )
