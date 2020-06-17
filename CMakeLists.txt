cmake_minimum_required(VERSION 3.15)
project(BL_CH_CW_JS_Final_Project_Graphics)

if (WIN32)
    set(FREEGLUT_INCLUDE_DIRS "C:/Program\ Files/Common\ Files/freeglut/include")
    set(FREEGLUT_LIBRARY_DIRS "C:/Program\ Files/Common\ Files/freeglut/lib/")
endif (WIN32)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Werror=return-type")

find_package (OpenGL REQUIRED)

if (APPLE)
    find_package(GLUT REQUIRED)
endif (APPLE)

if (WIN32)
    include_directories(${OPENGL_INCLUDE_DIR}  ${FREEGLUT_INCLUDE_DIRS})
    link_directories(${FREEGLUT_LIBRARY_DIRS})
elseif (APPLE)
    include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})
endif ()


add_executable(graphics Graphics.cpp  Button.cpp  Quad.cpp BarGraph.cpp SubmitButton.cpp BooleanButton.cpp
                Album.cpp Song.cpp RapSong.cpp PopSong.cpp)
#add_executable(BL_CH_CW_JS_Final_Project_Graphics
#        Album.cpp
#        Song.cpp
#        RapSong.cpp
#        PopSong.cpp
#        main.cpp)

if (WIN32)
    target_link_libraries (graphics ${OPENGL_LIBRARIES} freeglut)
elseif (APPLE)
    target_link_libraries (graphics ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif ()


