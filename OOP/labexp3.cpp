#include <iostream>
#include <string>

class Publication
{
protected:
    std::string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    virtual void getData()
    {
        std::cout << "Enter title: ";
        std::cin >> title;
        std::cout << "Enter price: ";
        std::cin >> price;
    }

    virtual void displayData() const
    {
        std::cout << "Title: " << title << "\n";
        std::cout << "Price: $" << price << "\n";
    }
};

class Book : public Publication
{
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void getData() override
    {
        Publication::getData();
        std::cout << "Enter page count: ";
        std::cin >> pageCount;
    }

    void displayData() const override
    {
        Publication::displayData();
        std::cout << "Page Count: " << pageCount << "\n";
    }
};

class Tape : public Publication
{
private:
    float playingTime;

public:
    Tape() : playingTime(0.0) {}

    void getData() override
    {
        Publication::getData();
        std::cout << "Enter playing time (minutes): ";
        std::cin >> playingTime;
    }

    void displayData() const override
    {
        Publication::displayData();
        std::cout << "Playing Time: " << playingTime << " minutes\n";
    }
};

int main()
{
    try
    {
        Book book;
        Tape tape;

        std::cout << "============" << std::endl;
        std::cout << "Enter details for the book" << std::endl;
        book.getData();
        std::cout << "============" << std::endl;
        std::cout << "Enter details for the tape" << std::endl;
        tape.getData();
        std::cout << "============" << std::endl;
        std::cout << "============" << std::endl;
        std::cout << "Book details" << std::endl;
        book.displayData();
        std::cout << "============" << std::endl;
        std::cout << "Tape details" << std::endl;
        tape.displayData();
        std::cout << "============" << std::endl;
    }
    catch (...)
    {
        std::cerr << "An exception occurred. Resetting all data members to zero.\n";
    }

    return 0;
}