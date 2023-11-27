#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Person
{
    protected:
    string name;
    int age;

    public:

    Person(string name, int age):name(name), age(age){}
    virtual ~Person(){}
    virtual void displayinfo() = 0;
};

class Student: public Person
{
    private:

    string course;
    int student_id;

    public:

    Student(string name, int age, string course, int student_id):Person(name, age), course(course), student_id(student_id){}

    void displayinfo() override
    {
        cout<<"Student: "<<name<<", Age: "<<age<<", Course: "<<course<<", Student ID: "<<student_id<<endl;
    }
};

class Instructor : public Person
{
    private:

    string license_number;
    int experience_y;

    public:
    
    Instructor(string name, int age, string license_number, int experience_y): Person(name, age), license_number(license_number), experience_y(experience_y){}
    void displayinfo() override
    {
        cout<<"Instructor: "<<name<<", Age: "<<age<<", License Number: "<<license_number<<", Experience: "<<experience_y<<" years"<<endl;

    }  
};

class Vehicle
{
    protected:

    string model;
    string reg_number;
    int manufacturing_y;

    public:
    
    Vehicle(string model, string reg_number, int manufacturing_y): model(model), reg_number(reg_number), manufacturing_y(manufacturing_y){}

    virtual void displayinfo() = 0;
};

class Car : public Vehicle
{
    private:
    string transmission_type;

    public:

    Car(string model, string reg_number, int manufacturing_y, string transmission_type): Vehicle(model, reg_number, manufacturing_y), transmission_type(transmission_type){}

    void displayinfo() override
    {
        cout<<"Car Model: "<<model<<", Registration Number: "<<reg_number<<", Manufacturing Year: "<<manufacturing_y<<", Transmission type: "<<transmission_type<<endl;

    }
};

class Bike : public Vehicle
{
    private:

    string type_of_bike;

    public:

    Bike(string model, string reg_number, int manufacturing_y, string type_of_bike): Vehicle(model, reg_number, manufacturing_y), type_of_bike(type_of_bike){}

    void displayinfo() override
    {
        cout<<"Bike Model: "<<model<<", Registration Number: "<<reg_number<<", Manufacturing Year: "<<manufacturing_y<<", Type of Bike: "<<type_of_bike<<endl;

    }
};

class DrivingSchool
{
    private:

    vector<Student*> students;
    vector<Instructor*> instructors;
    vector<Vehicle*> vehicles;

    public:

    void addStudent(Student* student)
    {
        students.push_back(student);
    }

    void addInstructor(Instructor* instructor)
    {
        instructors.push_back(instructor);
    }

    void addVehicle(Vehicle* vehicle)
    {
        vehicles.push_back(vehicle);
    }

    void displayStudents()
    {
        cout<<"Students: "<<endl;
        for(const auto& student : students)
        {
            student->displayinfo();
        }
    }

    void displayInstructors()
    {
        cout<<"Instructors: "<<endl;
        for(const auto& instructor : instructors)
        {
            instructor->displayinfo();
        }
    }

    void displayVehicles()
    {
        cout<<"Vehicle: "<<endl;
        for(const auto& vehicle : vehicles)
        {
            vehicle->displayinfo();
        }
    }

};
int main()
{
    DrivingSchool favorit;

    Student student1("Johny", 47, "Bike", 001);
    favorit.addStudent(&student1);
    Student student2("Rayan", 34, "Car", 002);
    favorit.addStudent(&student2);
    Student student3("Brayan", 21, "Car", 003);
    favorit.addStudent(&student3);

    Instructor instructor1("Toretto", 68, "E46N21", 52);
    favorit.addInstructor(&instructor1);

    Car car1("Mustang", "47N54F", 2006, "Mechanic");
    favorit.addVehicle(&car1);

    Car car2("Civic", "24N87F", 1998, "Mechanic");
    favorit.addVehicle(&car2);

    Bike bike1("Harley Davidson", "01N32F", 1973, "Chopper");
    favorit.addVehicle(&bike1);


    favorit.displayStudents();
    favorit.displayInstructors();
    favorit.displayVehicles();


    return 0;
}