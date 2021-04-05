cmake_minimum_required(VERSION 3.17)
project(Graphics)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graphics main.cpp)

# ah yes dynamic linking pro pog gamer move what an op move, if you dont have libraries insta break
# also this wont work on windows only unix based system with sfml installed lmaooo feels bad actually
# I don't kow this might work on windows I should test it.
target_link_libraries(Graphics GL GLEW sfml-window sfml-graphics sfml-system sfml-audio)
