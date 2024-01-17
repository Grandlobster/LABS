// Group A Hashing Function Aadesh 
#include <iostream>
#include<string>
using namespace std;
int SIZE=10;
class node {
    string name;
    int id;
    long int tel;
    friend class hashing;
    
public:
    node() {
        id = 0;
        tel = 0;
    }
};

class hashing {
    node data[10];
    int index;
public:
    void create(int size, string n, int i, long int t) {
        index = i % size;
        int j;
        for (j = 0; j < size; j++) {
            if (data[index].id == 0) {
                data[index].id = i;
                data[index].name = n;
                data[index].tel = t;
                break;  
            } else {
                index = (index + 1) % size;
            }}
        
        cout<<"Record inserted";}
    
    void display(int size) {
        cout << "\n\tID\tNAME\tTELEPHONE NO.";
        for (int i = 0; i < size; i++) {
            if (data[i].id != 0) {
                cout << "\n\t" <<data[i].id << "\t" <<data[i].name << "\t" << data[i].tel;
            }
        }
    }
    void delete_(int id_){
    int index=id_%SIZE;
    for(int i=0;i<SIZE;i++){
    	if(data[i].id==id_){
    		data[i].id=0;
    		data[i].name=" ";
    		data[i].tel=0;
    		cout<<"the id:"<<id_<<"is deleted.";
    	}
    	else{
    		index=(index+1)%SIZE;
    	}
    }}
    void searching(int id_){
    int flag=1;
    int index=id_%SIZE;
    if(flag==1){
    for(int i=0;i<SIZE;i++){
    	if(data[i].id==id_){
    		cout<<"The given record is found at the index:"<<i;
    		cout << "\n\t" << data[i].id << "\t" << data[i].name << "\t" << data[i].tel;
    		flag=0;
    		
    	}
    	else{
    		index=(index+1)%SIZE;
    	}
    }}
    else{
    	cout<<"404 error";
    }
}
   void modify(int id_){
   int index=id_%SIZE;
   for(int i=0;i<SIZE;i++){
   	if(data[i].id=id_){
   		string new_name;
   		int new_tel;
   		cout<<"Enter the new values for the id\n";
   		
   		cout<<"Enter the new name\n";
   		cin>>new_name;
   		cout<<"Enter the new telephone number\n";
   		cin>>new_tel;
   		data[i].name=new_name;
   		data[i].tel=new_tel;
   		break;
   	}
   	else{
   		cout<<"Given Id not found 404 error\n";
   	}
   }
   }
};

int main() {
    hashing h;
    int choice, size, id;
    string name;
    long int tel;
    cout << "Enter size of hash table: ";
    cin >> size;
    do {
        cout << "\nMenu\n1.Create\n2.Display\n3.Delete\n4.Search\n5.Modify \n6.Exit Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter name, id, and telephone number: ";
                cin >> name >> id >> tel;
                h.create(size, name, id, tel);
                break;
            case 2:
                h.display(size);
                break;
            case 3:
                cout << "Enter the id you want to delete";
                int temp;
                cin>>temp;
                h.delete_(temp);
                break;
           case 4:
           	cout<<"Enter the searching index";
           	int temp_2;
           	cin>>temp_2;
           	h.searching(temp_2);
           	break;
           case 5:
           	//MOdify
           	int temp_3;
           	cout<<"Enter the id you want to modify";
           	cin>>temp_3;
           	h.modify(temp_3);
           	break;
           case 6:
           	cout<<"Exiting the program";
           	break;
            default:
                cout << "Invalid choice";
                break;
        }
    } while (choice != 6);
    return 0;
}
