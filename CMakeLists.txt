## linux ou windows + wsl ubuntu apenas

cmake_minimum_required(VERSION 3.2)
project(Autocomplete)

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
