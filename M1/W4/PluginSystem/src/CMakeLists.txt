add_library(zoo_management
    ${PROJECT_SOURCE_DIR}/src/Animal/Animal.cpp
    ${PROJECT_SOURCE_DIR}/src/Animal/Mammal.cpp
    ${PROJECT_SOURCE_DIR}/src/Animal/Bird.cpp
    ${PROJECT_SOURCE_DIR}/src/Animal/Reptile.cpp
    ${PROJECT_SOURCE_DIR}/src/Management/Habitat.cpp
    ${PROJECT_SOURCE_DIR}/src/Management/FeedingSchedule.cpp
    ${PROJECT_SOURCE_DIR}/src/Management/Visitor.cpp          
    ${PROJECT_SOURCE_DIR}/src/Utils/AnimalFactory.cpp    
    ${PROJECT_SOURCE_DIR}/src/CLI/Menu.cpp                  
    ${PROJECT_SOURCE_DIR}/src/Utils/ZooSettings.cpp           
)

# Ensure the library knows where to find headers
target_include_directories(zoo_management PUBLIC 
    ${PROJECT_SOURCE_DIR}/include 
    ${PROJECT_SOURCE_DIR}/include/Animal
    ${PROJECT_SOURCE_DIR}/include/Management
    ${PROJECT_SOURCE_DIR}/include/Utils
    ${PROJECT_SOURCE_DIR}/include/CLI
)

# Add the executable for the main program
add_executable(zoo_main ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(zoo_main zoo_management)
