# Object-Oriented Programming (OOP) : Zoo Management System

Develop a Zoo Management System using Object-Oriented Programming principles. The system will manage different types of animals, their habitats, feeding schedules, and visitors. This project will focus on creating a hierarchy of classes, leveraging *inheritance*, *polymorphism*, and *encapsulation*, and applying design patterns for effective code organization.

## Concepts to Master

1. **Core OOP Principles**:
    * **Encapsulation**: Encapsulation is the bundling of data and methods that operate on that data within a single unit or class. It restricts direct access to some of the object's components, which can prevent the accidental modification of data. For example, using private variables and providing public getter and setter methods.
    * **Inheritance**: Inheritance is a mechanism where a new class inherits properties and behavior (methods) from an existing class. This promotes code reusability. For example, a `Bird` class can inherit from an `Animal` class.
    * **Polymorphism**: Polymorphism allows objects of different classes to be treated as objects of a common super class. It is typically achieved through method overriding (runtime polymorphism) or method overloading (compile-time polymorphism). For example, different animal classes can have their own implementation of a `makeSound` method.
    * **Abstraction**: Abstraction is the concept of hiding the complex implementation details and showing only the essential features of the object. It helps in reducing programming complexity and effort. For example, an `Animal` class can have an abstract method `makeSound` that is implemented by its subclasses.

2. **Abstract Classes and Interfaces**:
    * Abstract classes cannot be instantiated and are often used to define a common interface for derived classes. They can contain both abstract methods (without implementation) and concrete methods (with implementation).
    * Interfaces define a contract that implementing classes must follow. They can only contain method signatures and static final variables (constants).

3. **Design Patterns**:
    * Common design patterns include Singleton, Factory, Observer, and Strategy. These patterns provide solutions to common software design problems and help to write more maintainable and scalable code.

4. **Composition vs. Inheritance**:
    * Composition involves building complex types by combining objects of other types, rather than inheriting from a base class. It promotes greater flexibility and reusability. For example, a `Zoo` class can have a list of `Animal` objects rather than inheriting from an `Animal` class.

5. **Relationships between Classes**:
    * Relationships include association, aggregation, and composition. Association is a general relationship between classes. Aggregation is a special form of association with a whole-part relationship but without ownership. Composition is a stronger form of aggregation with ownership, meaning the lifetime of the part is managed by the whole.

6. **OOP Best Practices**:
    * Follow the SOLID principles (Single Responsibility, Open/Closed, Liskov Substitution, Interface Segregation, Dependency Inversion).
    * Use meaningful names for classes, methods, and variables.
    * Keep classes focused on a single responsibility.
    * Favor composition over inheritance where appropriate.
    * Write unit tests to ensure code correctness.
    * Document code to improve readability and maintainability.

## How to run the project

1. **Clone the repository**:
    Clone the repository to your local machine using the following command:

    ```sh
    git clone https://github.com/sourenamoosavi/zoo-management-system.git
    cd zoo-management-system
    ```

2. **Create the build directory**:

    ```sh
    mkdir build && cd build
    ```

3. **Build the project**:
    Ensure you have a C++ compiler installed. Then, run the following command to compile the project:

    ```sh
    cmake ..
    make
    ```

4. **Run the executable**:
    After building the project, you can run the executable:

    ```sh
    ./test/zoo_main
    ```

5. **Run tests**:
    To ensure everything is working correctly, run the tests:

    ```sh
    ./test/zoo_test
    ```
