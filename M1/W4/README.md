# OOP Architecture & Plugin Engineering

Welcome to Week 4 of the CppMasteryQuest!  
This week, you move beyond syntax and memory fundamentals — into architecture.  
Modern C++ software (games, compilers, IDEs, scientific tools, trading engines…) all rely heavily on good OOP design.  
Knowing OOP superficially is easy — but mastering it, understanding when to use inheritance, how to design abstractions, and why SOLID principles matter, is what makes you a real C++ engineer.  

By the end of this week, you’ll architect and build a full Plugin System with dynamically loaded modules — the same concept behind how browsers, Unreal Engine, VSCode extensions, and real-world applications load features at runtime.

---

## Concepts Covered

1. **Object-Oriented Design Fundamentals**

    Object-Oriented Programming provides a structured way to model systems using objects, interfaces, and relationships. This week, you’ll refine your understanding not just of syntax, but architecture.

   **Core Concepts**

    - **Encapsulation** — hide internal details and expose a clean API.
    - **Inheritance** — reuse behavior and define hierarchical relationships.
    - **Polymorphism** — write code that works uniformly for all derived types.
    - **Abstraction** — strip unnecessary details and expose essential operations.

   **Example (Pure Virtual Interface)**

    ```cpp
    class Plugin {
    public:
        virtual void initialize() = 0;
        virtual std::string name() const = 0;
        virtual ~Plugin() = default;
    };
    ```

    **Interview Mini Q&A :**

    - ❓ **What is the difference between interface inheritance and implementation inheritance?**  
      Interface inheritance defines what is done; implementation inheritance defines how it's done. Prefer interface inheritance for extensibility.
    - ❓ **Why should destructors be virtual in polymorphic base classes?**  
      To ensure proper cleanup of derived objects through base pointers.
    - ❓ **When should you avoid inheritance?**  
      Avoid inheritance when “is-a” is not true, or when behavior does not need to be overridden.

    **Types of interview questions**

    - Explain the difference between composition and inheritance.
    - What are the downsides of deep inheritance hierarchies?
    - Identify violations of encapsulation in a code snippet.

2. **SOLID Principles :**

    SOLID is not about “rules” — it is about writing code that is flexible, testable, and extendable without breaking existing behavior.

    - **S — Single Responsibility**  
        Each class should do one thing and do it well.  
        A plugin loader should load plugins, not manage logs or config.
    - **O — Open/Closed**  
        Your system should allow adding new plugins without modifying the loader.
    - **L — Liskov Substitution**  
        Derived classes should be usable anywhere the base class is expected.
    - **I — Interface Segregation**  
        Prefer small, specialized interfaces (e.g., Renderable, Scriptable, Serializable) over large monolithic ones.
    - **D — Dependency Inversion**  
        High-level code depends on abstractions — not concrete implementations.

   **Example (Dependency Inversion)**

    ```cpp
    class ILogger {
    public:
        virtual void log(const std::string&) = 0;
    };

    class PluginManager {
        ILogger& logger_;
    public:
        PluginManager(ILogger& logger) : logger_(logger) {}
    };
    ```

    **Interview Mini Q&A:**
    - ❓ *Which SOLID principle encourages designing small interfaces?*
      - Interface Segregation Principle (ISP).
    - ❓ *What does “Open for extension, closed for modification” mean?*
      - You can add new behavior (like new plugins) without altering existing classes.
    - ❓ *What is a good sign that DIP is being followed?* 
      - Core logic depends only on interfaces, not specific implementations.

    **Types of interview questions**

    - Identify the SOLID principle violated in a design.
    - Refactor a class to follow SRP or OCP.
    - Explain how abstract interfaces improve testability.

3. **Polymorphism & Dynamic Dispatch**

    Polymorphism enables runtime flexibility — the cornerstone of plugin systems.

   **Example (Run-Time Polymorphism)**

    ```cpp
    void runPlugin(Plugin* p) {
        p->initialize();
        std::cout << "Running: " << p->name() << "\n";
    }
    ```

    Here, the exact implementation depends on the derived type loaded at runtime.

    **Interview Mini Q&A**

    - ❓ *What is dynamic dispatch?* 
      - The mechanism that selects which overridden method to call at runtime.
    - ❓ *When is polymorphism cost acceptable?* 
      - Whenever extensibility outweighs the small overhead of virtual calls.
    - ❓ *Why avoid non-virtual destructors in polymorphic classes?*
      - Because deleting a derived object through a base pointer causes UB.

    **Types of interview questions**

    - Explain virtual tables and vptrs.
    - Identify incorrect polymorphic design.
    - Compare static vs dynamic polymorphism.

4. **Design Patterns (OOP Essentials)**

    Real-world C++ uses patterns to create flexible architectures.  
    Patterns you will directly use in the challenge:

    - **Factory Pattern**  
        To instantiate plugins without knowing their concrete type.
    - **Strategy Pattern**  
        Allow replacing algorithms at runtime.
    - **Interface Pattern**  
        Your plugins will implement a pure virtual class.
    - **Singleton (optional)**  
        For plugin registry or configuration managers (use sparingly).

    **Example — Factory**

    ```cpp
    extern "C" Plugin* createPlugin(); 
    ```

    This export allows dynamic loading via dlopen/dlsym (Linux) or LoadLibrary (Windows).

    **Interview Mini Q&A :**

    - ❓ *Why are factories useful in plugin systems?*
        They decouple instantiation from implementation.
    - ❓ *Why avoid singletons unless necessary?*
        They reduce testability and introduce global state.
    - ❓ *What’s the advantage of the Strategy pattern?*
        You can change an object’s behavior without modifying its class.

    **Types of interview questions**

    - Describe a real-world use of Strategy.
    - Identify inappropriate uses of singletons.
    - Explain why abstract factories improve modularity.

## Challenge — Modular Plugin System

This week, you’ll design and build a **runtime-loadable plugin framework** — similar to how **VSCode extensions**, **Photoshop plugins**, and **Blender addons** work.

### Your Plugin System Will Support

1. **Plugin Interface (`IPlugin`)**  
   - Pure virtual base class.  
   - Defines the minimum contract for plugins.
2. **Dynamic Loading**  
   - On Linux: `dlopen`, `dlsym`, `dlclose`.  
   - On Windows: `LoadLibrary`, `GetProcAddress`, `FreeLibrary`.
3. **Factory Function Per Plugin**  
   - Each plugin must export a `createPlugin()` function.
4. **Plugin Manager**  
   - Loads shared libraries.  
   - Instantiates plugin instances.  
   - Maintains plugin lifetime.
5. **Two Sample Plugins**  
   - Example:  
     - `LoggerPlugin`  
     - `MathPlugin`
     - or anything creative.
6. **Optional Stretch Goals**  
   - Plugin metadata system.  
   - Hot reloading.  
   - JSON/YAML plugin manifest.  
   - Plugin dependency management.

---

## Learning Outcomes

By the end of this week, you will be able to:

- Understand **inheritance**, **composition**, and **dynamic dispatch**
- Apply the **SOLID principles** to real code
- Use **interfaces + factories** to decouple implementations
- Build a **runtime plugin loader** using:

  - `dlopen()` / `dlsym()` on Linux
  - (Windows-ready via `LoadLibrary`, though we focus mainly on Linux)

- Demonstrate how applications discover and load plugins at runtime, without recompiling the main executable
