#include <iostream>
#include <string>

class Animal
{
private:
    std::string animal_name;
public:
    Animal(std::string name)
        : animal_name {name}
    {
        
    }
    Animal()
        : Animal{"no name"}
    {
        
    }
    std::string get_animal_name()
    {
        return animal_name;
    }

    virtual void show_info()
    {
        std::cout << "Hi from animal " << std::endl;
    }
};


class Dog : public Animal
{
private:
    std::string dog_bark_status;
public:
    Dog(std::string name, std::string bark)
        : Animal{name}, dog_bark_status{bark}
    {
    }
    std::string return_dog_bark_status()
    {
        return dog_bark_status;
    }

    virtual void show_info() override
    {
        std::cout << "Hi from dog " << std::endl;
    }

};

class Person
{
private:
    std::string name;
    Animal *pet;
public:
    Person(std::string name_val, Animal *pet1)
        : name{name_val}, pet{pet1}
    {
    }
    std::string get_name()
    {
        return name;
    }
    void person_info()
    {
        std::cout << name << " has " << pet->get_animal_name() << std::endl;
    }

    Animal *return_obj()
    {
        return pet;
    }
};

int main () {

    Animal *dog = new Dog ("Leo", "woof");
    Person p1 = {"Akash", dog};
    p1.return_obj()->show_info();
    return 0;

}