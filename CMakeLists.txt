cmake_minimum_required(VERSION 3.3)

project (OnePunchGame)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${OnePunchGame_SOURCE_DIR}")

#find_package(SDL2 REQUIRED)
#find_package(SDL2_image REQUIRED)

add_subdirectory(Command/)
add_subdirectory(Input/)
add_subdirectory(Rendering/)
add_subdirectory(File/)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ ${SDL2_INCLUDE}/ ${SDL2_IMAGE_INCLUDE_DIR}/ ${SDL2_INCLUDE_DIR}/ ${SDL2_IMAGE_INCLUDE_DIR}/)
link_directories(${SDL2_LIB}/ ${SDL2_IMAGE_LIBRARIES}/)

add_executable (OnePunchGame main.cpp 
Clases/Director/Director.cpp 
Clases/Escenas/Escena.cpp 
Clases/Escenas/Home.cpp 
Clases/UI/Boton.cpp 
Clases/Escenas/Gameplay.cpp 
Clases/Managers/Animacion.cpp 
Clases/Managers/AudioManager.cpp 
Clases/Managers/Input.cpp 
Clases/Managers/Fondo.cpp 
Clases/Personajes/Demonio.cpp 
Clases/Personajes/State.cpp 
Clases/Personajes/Attack.cpp 
Clases/Personajes/Block.cpp 
Clases/Personajes/Parry.cpp 
Clases/Personajes/Idle.cpp 
Clases/Personajes/Death.cpp 
Clases/Personajes/Personaje.cpp 
Clases/Personajes/Templario.cpp)
target_link_libraries(OnePunchGame FileLibrary)
target_link_libraries(OnePunchGame CommandLibrary)
target_link_libraries(OnePunchGame InputLibrary)
target_link_libraries(OnePunchGame RenderLibrary)
target_link_libraries(OnePunchGame SDL2)
target_link_libraries(OnePunchGame SDL2_image)
target_link_libraries(OnePunchGame ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})

file(GLOB GAME_RESOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/Resources/*"
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resources/ DESTINATION ${CMAKE_BINARY_DIR}/Resources/)   

file(GLOB GAME_RESOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/OnePunch.properties"
)

file(COPY ${GAME_RESOURCES} DESTINATION ${CMAKE_BINARY_DIR}/)                
