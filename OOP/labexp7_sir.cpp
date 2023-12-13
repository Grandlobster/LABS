#include <iostream>
#include <map>
#include <string>

using namespace std;
int main(){    
    typedef map<string, int> MapType;
    MapType populationMap;

    populationMap.insert(pair<string, int>("Maharashtra", 1234567));
    populationMap.insert(pair<string, int>("Rajasthan", 8103268));
    populationMap.insert(pair<string, int>("Gujrat", 3278910));
    MapType::iterator iter;
    cout << "Population of state in India\n";
    cout << "\nsize of population map: " << populationMap.size() << "\n";

    string state_Name;
    cout << "\nEnter name of the state: ";
    cin >> state_Name;
    iter = populationMap.find(state_Name);
    if (iter != populationMap.end())
        cout << state_Name << " Population is: " << iter->second << endl;
    else
        cout << "Key is not in Population Map...\n";
    populationMap.clear();
    return 0;
};
