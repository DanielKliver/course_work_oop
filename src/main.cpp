#include<iostream>
#include<string>

using namespace std;



class car
{
    private:

    string name;
    string drive_unit;
    string type_of_transmission;
    bool left_hand_drive;

    
    public:

    car()
    {
        cout<<"No input data"<<endl;
    }

    car(string name, string drive_unit, string type_of_transmission, bool left_hand_drive)
    {
        this->name = name;
        this->drive_unit = drive_unit;
        this->type_of_transmission = type_of_transmission;
        this->left_hand_drive = left_hand_drive;
        
    }

    ~car()
    {
        //do something
    }

    void Getcar()
    {
        cout<<"Name of car: "<<name<<endl<<"Drive unit: "<<drive_unit<<endl;
        cout<<"Type of transmission: "<<type_of_transmission<<endl;
        if(left_hand_drive)
        {
            cout<<"left_hand_drive: yes"<<endl;
        }
        else
        {
            cout<<"left_hand_drive: no"<<endl;
        }
    }

};

class instructor
{
    private:

    string name;
    int experience;
    string car_name;

    protected:

    void Getinstructor()
    {
        cout<<"Name: "<<name<<endl<<"Experience: "<<experience<<endl;
        cout<<"Name of car: "<<car_name<<endl;
    }

    public:

    instructor()
    {
        cout<<"No input data"<<endl;
    }

    instructor(string name, int experience, string car_name)
    {
        this->name = name;
        this->experience = experience;
        this->car_name = car_name;
    }

    ~instructor()
    {
        //do something
    }

};

class student
{
    private:

    string name;
    int age;

    protected:

    void Getstudent()
    {
        cout<<"Name of student: "<<name<<endl<<"Age of student: "<<age<<endl;
    }

    public:

    student()
    {
        cout<<"No input data"<<endl;
    }

    student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    ~student()
    {
        //do something
    }

};

class autoschool : public car, public instructor, public student
{
    private:

    string address;
    int rating;
    string phone_number;

    public:

    autoschool(string address, int rating, string phone_number)
    {
        this->address = address;
        this->rating = rating;
        this->phone_number = phone_number;
    }

    ~autoschool()
    {
        
    }

    void Getautoschool()
    {
        cout<<"Adress of autoschool: "<<address<<endl<<"Rating: "<<rating<<endl;
        cout<<"Phone number: "<<phone_number<<endl;
        
    }

};


int main()
{
    setlocale(LC_ALL, "ru");


    autoschool aa("Выборная", 3, "88005553535");
    car ac("Mustang", "rear", "M", true);
    car bc("Civic", "front", "M", false);
    car cc("Prius", "front", "A", false);
    ac.Getcar();
    aa.Getautoschool();

    return 0;
}