#include <iostream>
#include "ConceptModelDefinition.h"
#include <vector>

struct Action_Ciao
{
    Action_Ciao() = default;
    ~Action_Ciao() = default;
    void Execute()
    {
        std::cout << "Ciao\n";
    }
};

struct Action_Pizza
{
    Action_Pizza() = default;
    ~Action_Pizza() = default;
    void Execute()
    {
        std::cout << "Pizza\n";
    }
};

struct Action_Espresso
{
    Action_Espresso() = default;
    ~Action_Espresso() = default;
    void Execute()
    {
        std::cout << "Espresso\n";
    }
};

int main()
{

    std::vector<Action> Actions;

    Actions.emplace_back(Action_Ciao());
    Actions.emplace_back(Action_Espresso());
    Actions.emplace_back(Action_Pizza());

    for (auto&& Action : Actions)
    {
        Action.Execute();
    }
}
