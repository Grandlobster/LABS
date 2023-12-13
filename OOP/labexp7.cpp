#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, long long> statePopulations;

    statePopulations["Maharashtra"] = 39512223;
    statePopulations["Tamil Nadu"] = 28995881;
    statePopulations["Uttar Pradesh"] = 21477737;
    statePopulations["Bihar"] = 19453561;
    statePopulations["J&K"] = 12671821;

    std::string inputState;
    std::cout << "Enter the name of a state: ";
    std::getline(std::cin, inputState);

    auto it = statePopulations.find(inputState);

    if (it != statePopulations.end())
    {

        std::cout << "Population of " << inputState << ": " << it->second << std::endl;
    }
    else
    {
        std::cout << "Population data not available for " << inputState << std::endl;
    }

    return 0;
}
