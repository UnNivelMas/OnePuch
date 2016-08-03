cmake_minimum_required(VERSION 3.3)

project (OnePunchGame)
set(CMAKE_BUILD_TYPE Release)

add_subdirectory(Command/)
add_subdirectory(Input/)
add_subdirectory(Rendering/)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ ${SDL2_INCLUDE}/)
link_directories(${SDL2_LIB}/)

add_executable (OnePunchGame main.cpp 
Clases/Director/Director.cpp 
Clases/Escenas/Escena.cpp 
Clases/Escenas/Gameplay.cpp 
Clases/Managers/Animacion.cpp 
Clases/Managers/AudioManager.cpp 
Clases/Managers/Input.cpp 
Clases/Managers/Fondo.cpp 
Clases/Personajes/Demonio.cpp 
Clases/Personajes/Personaje.cpp 
Clases/Personajes/Templario.cpp)
target_link_libraries(OnePunchGame CommandLibrary)
target_link_libraries(OnePunchGame InputLibrary)
target_link_libraries(OnePunchGame RenderLibrary)
target_link_libraries(OnePunchGame SDL2)
target_link_libraries(OnePunchGame SDL_image)
