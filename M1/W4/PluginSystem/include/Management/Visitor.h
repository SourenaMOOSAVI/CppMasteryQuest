#ifndef VISITOR_H
#define VISITOR_H

#include <string>
#include <vector>

class Visitor {
private:
    std::string name;
    int age;
    std::vector<std::string> visitedHabitats;

public:
    Visitor(const std::string& name, int age);

    void visitHabitat(const std::string& habitat);
    void displayVisitedHabitats() const;
    std::vector<std::string> getVisitedHabitats() const;

    std::string getName() const;
    int getAge() const;
};

#endif // VISITOR_H