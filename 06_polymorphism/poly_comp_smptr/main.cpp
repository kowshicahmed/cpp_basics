#include <iostream>
#include <string>
#include <memory>
#include <vector>

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
    std::shared_ptr<Animal> pet;
public:
    Person(std::string name_val, std::shared_ptr<Animal> pet1)
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

    std::shared_ptr<Animal> return_obj()
    {
        return pet;
    }
};

int main () {

    std::vector<std::shared_ptr<Animal>> animals;
    animals.emplace_back(new Dog("Leo", "woof"));
    Person p1 = {"Akash", animals.at(0)};
    Person p2 = {"Batash", std::make_shared<Dog>("Cleo", "bark")};
    p1.return_obj()->show_info();
    p2.return_obj()->show_info();
    return 0;

}