//Aadesh Lawande
//ROLL NO:37 S2
/* lab assignment 3 Imagine a publishing company which does marketing for book and outro casstte versions
 create a class publication that stores the title (string) and price (type float) of publication
 from this class derive two classes book which adds page count (type int) and tape
 which adds a playing time in mintues (type float)
 Write a program that instantiates the book and tape class 
 Allow the user to enter data and display the data members If an exception is caught,replace all the 
 data members with zen value. */
#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
class Publication{
    public:
        string title;
        float price;
        char tem;
        void input(){
         cout<<"Enter title :";
            cin>>title;
         cout<<"Enter price :";
         cin>>price;
     }
        void display(){
        cout<<"Price is:"<<price;
        cout<<"Title is:"<<title;
        }
    };

class Book : public Publication{
 public: int pagecount;
  	 void input1(){
  	 cout<<"Add Page count\n";
  	 cin>>pagecount;
  	 }
  	 void input1_display(){
  	 	cout<<"Page count:\n";
		cout<<pagecount;
	   }
};
class Tape: public Publication{
 public: float playingtime;
  	 void input2(){
  	 cout<<"Add Playing Time\n"<<endl;
  	 cin>>playingtime;
  	 }
  	 void input2_display(){
  	 	cout<<"Playing time is :\n"<<playingtime<<"min"<<endl;
	   }
};
int main() {
    // Create instances outside the try-catch block
    Book book;
    Tape tape;

    try {
        cout << "This is to display std inputs:\n" << endl;
        book.input();
        cout << "This is to input book input\n" << endl;
        book.input1();
        cout << "This is to input tape input\n" << endl;
        tape.input2();
        cout << "This is to display data:\n" << endl;
        book.input1_display();
        tape.input2_display();
    }
    catch (const exception& e) {
        cout << "Exception is caught" << endl;
        cerr << "Exception caught: " << e.what() << endl;

        // Replace values with "Zen" values
        book = Book();  // Reconstruct the book object
        tape = Tape();  // Reconstruct the tape object

        cout << "Zen values:\n" << endl;
        book.input1_display();
        tape.input2_display();
    }

    return 0;
}


