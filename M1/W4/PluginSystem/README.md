# Proposed Project Structure

Below is the structure for "Zoo Management System" project.

```plaintext
ZooManagementSystem/
├── src/                    # Source code
│   ├── main.cpp            # Main entry point of the program
│   ├── Animal/             # Animal-related classes
│   │   ├── Animal.cpp      # Base class implementation
│   │   ├── Mammal.cpp      # Mammal class implementation
│   │   ├── Bird.cpp        # Bird class implementation
│   │   ├── Reptile.cpp     # Reptile class implementation
│   ├── Management/         # Zoo management classes
│   │   ├── Habitat.cpp     # Habitat class implementation
│   │   ├── FeedingSchedule.cpp # FeedingSchedule implementation
│   │   ├── Visitor.cpp     # Visitor class implementation
│   ├── Utils/              # Utility classes and helpers
│   │   ├── AnimalFactory.cpp  # Factory Method implementation
│   │   ├── ZooSettings.cpp    # Singleton implementation
│   ├── CLI/                # Command-line interface
│   |   ├── Menu.cpp        # CLI menu implementation
|   ├── CMakeLists.txt
│
├── include/                # Public headers for shared/external use
│   ├── Animal/             # Public headers for Animal classes
│   │   ├── Animal.h        # Base class definition
│   │   ├── Mammal.h        # Mammal class definition
│   │   ├── Bird.h          # Bird class definition
│   │   ├── Reptile.h       # Reptile class definition
│   ├── Management/         # Public headers for Management classes
│   │   ├── Habitat.h       # Habitat class definition
│   │   ├── FeedingSchedule.h # FeedingSchedule class definition
│   │   ├── Visitor.h       # Visitor class definition
│   ├── Utils/              # Public headers for utility classes
│   │   ├── AnimalFactory.h # Factory Method header
│   │   ├── ZooSettings.h   # Singleton header
│   ├── CLI/                # Public headers for CLI components
│       ├── Menu.h          # CLI menu definition
│
├── tests/                  # Unit tests
│   ├── AnimalTests.cpp     # Tests for Animal classes
│   ├── HabitatTests.cpp    # Tests for Habitat class
│   ├── FeedingScheduleTests.cpp
│   ├── VisitorTests.cpp
│   ├── AnimalFactoryTests.cpp
|   ├── CMakeLists.txt
│
├── build/                  # Build output (e.g., object files, binaries)
├── data/                   # Data files (e.g., save files, input files)
│   ├── zoo_data.json       # Example zoo data
├── docs/                   # Documentation
│   ├── class_diagram.png   # UML diagrams or other visuals
│   ├── README.md           # Detailed description of the project
├── CMakeLists.txt          # Build configuration for CMake
├── .gitignore              # Files and directories to ignore in version control
└── README.md               # Overview of the project
```
