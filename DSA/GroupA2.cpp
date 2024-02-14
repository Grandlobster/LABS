// Aadesh Lawande 
#include<iostream>
#include<string>
using namespace std;
#define SIZE 10

class Juvenile{
    struct node{
        int data;
        string value;
        struct node *next;
    };
    struct node *head[SIZE];
public:
    Juvenile() {
        for(int i = 0; i < SIZE; ++i)
            head[i] = nullptr;
    }

    void insert(){
        int data_;
        string value_;
        cout<<"Enter the data :";
        cin>>data_;
        cout<<"Enter the value:";
        cin>>value_;
        struct node *nn = new node;
        nn->data = data_;
        nn->value = value_;
        nn->next = nullptr;

        int i = data_ % SIZE;
        if(head[i] == NULL){
            head[i] = nn;
        }
        else{
            node *temp = head[i];
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = nn;
        }
    }
void display() {
    for (int i = 0; i < SIZE; i++) {
       // cout << "Hash Table at index " << i << ": ";
        
        if (head[i] == NULL) {
            cout << "Empty" << endl;
        } else {
            node *temp = head[i];
            while (temp != NULL) {
                cout << "\t" << temp->data << " :\t" << temp->value << " --> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
}
void deletion(){
    int data_;
    cout<<"Enter the data to be deleted:\n";
    cin>>data_;
    int i=data_%SIZE;
    node *temp=head[i];
    if(head[i]->data==data_){
    head[i]->data=0;
    head[i]->value="";
    head[i]->next=nullptr;
    cout<<"DATA DELETED\n";
    }
    else{
    node *temp=head[i];
    while(temp->data!=data_){
    temp=temp->next;
    }
    temp->next=temp->next->next;
    cout<<"Data deleted\n";
    }
}
void search(){
    int data_;
    cout<<"Enter the data to be searched:";
    cin>>data_;
    int i=data_%SIZE;
    node *temp=head[i];
    if(temp->data==data_){
    cout<<"Data is found .....!";
    }
    else{
    while(temp->data!=data_){
    temp=temp->next;
    }
    if(temp->data==data_){
    cout<<"The given data is found\n";
    }
    else{
    cout<<"Data not found 404...!";
    }
    }
}
};

int main(){
    Juvenile h;
    int choice;
    do {
        cout << "\nMenu\n1. Insert\n2. Display\n3. Delete\n4. Search\n5. Exit \nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
            cout<<"INSERTING ELEMENT:\n";
                h.insert();
                break;
            case 2:
            cout<<"DISPLAY OF WHOLE LIST:\n";
                h.display();
                break;
            case 3:
            cout<<"DELETION OF ELEMENT\n";
               h.deletion();
               break;
            case 4:
            cout<<"SEARCHING OF AN ELEMENT\n";
            h.search();
            case 5:
            cout<<"EXITING THE PROGRAM\n";
            break;
          	
            default:
                cout << "Invalid choice\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
