#include <iostream>
using namespace std;

template <class T>

void sort (T a[], int n)
// declare a template
{
	int pos_min, i;
	T temp;

	for (int i=0; i<n-1; i++){
		pos_min = i;
		for (int j=i+1; j<n;j++){
			if (a[j] < a[pos_min])
			pos_min = j;
			}
			if (pos_min != i){
				temp = a[i];
				a[i] = a[pos_min];
				a[pos_min] = temp;
			}
	}
//display sorted element
cout << "\nSorted elements are: \n";
for (int i=0; i<n; i++){
	cout << a[i] << "\t" ;
}
cout << endl;
}

// main function
int main(){
	int n,i,ch;
	int a[10];
	float b[10];
	do{
		cout << "\n Selection sort using function template";
		cout << "\n 1. Sort Integer Number.";
		cout << "\n 2. Sort Float Number.";
		cout << "\n 3. Exit.";
		cout << "\n Enter Choice: ";
		cin >> ch;
		switch(ch){
			case 1:
				cout << "\nSorting integer numbers";
				cout << "\nEnter how many numbers wanted to sort: ";
				cin >> n;
				cout << endl;
				for (i=0; i<n; i++){
					cin >> a[i];
				}
				sort <int> (a,n);
				break;
			case 2:
				cout << "\nSorting float numbers";
				cout << "\nEnter how many number wanted to sort: ";
				cin >> n;
				cout << endl;
				for (i=0; i<n; i++){
					cin >> b[i];
				}
				sort <float> (b,n);
				break;
			case 3:
				exit (0);
		}
	}while (true);
}
