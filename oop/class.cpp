/*
Access Modifiers in C++:

1. public:
   - Members declared as public are accessible from anywhere in the program.
   - Used for interface methods and data that should be available to all.

2. private:
   - Members declared as private are accessible only within the same class.
   - Used to hide implementation details and protect data from outside access.

3. protected:
   - Members declared as protected are accessible within the same class and by derived (child) classes.
   - Useful for inheritance, allowing subclasses to access certain members while keeping them hidden from outside code.

Syntax Example:
class MyClass {
public:
    // Accessible everywhere
protected:
    // Accessible in MyClass and derived classes
private:
    // Accessible only in MyClass
};
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define space " "
#define endl "\n"

/*


*/

// class represents the blueprint of an actual object (an employee here)
// class = user-defined data-type
class Employee
{
    // we put members inside a class - attributes(variables, methods, etc.)
    // by default, everything inside class are private -> only accessible inside class
    // will make em public for now using the public keyword
public:
    string name;
    string company;
    int age;

    // constructor is the first function that gets called when an object is created. As a thumb rule
    // they should be made public always (but can be private and protected also). It goes by the
    // same name as the Class. Also it doesn't return anything
    Employee(string name, string company, int age)
    {
        this->name = name; // java "this.attribute_name" equivalent
        this->company = company;
        this->age = age;
    }

    void introduceYourself()
    {
        cout << "Name: " << name << endl;
        cout << "Company: " << company << endl;
        cout << "Age: " << age << endl;
    }

}; // do not forget to end a class definition with semicolon ";"

signed main()
{
    // fast io
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // creating an instance/object of class Employee
    Employee employee1 = Employee("Mrinmay", "Google", 23); // Employee() -> constructor name
    // employee1.name="Mrinmay";
    // employee1.company="Google";
    // employee1.age=23;
    employee1.introduceYourself();

    Employee employee2 = Employee("Krishank", "Microsoft", 18);
    // employee2.name="Krishank";
    // employee2.company="Microsoft";
    // employee2.age=18;
    employee2.introduceYourself();
}