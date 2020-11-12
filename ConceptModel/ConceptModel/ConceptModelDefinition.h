#pragma once

struct Action
{
    template<typename T>
    Action(T InConcept)
        : Concept(std::make_unique<T_Model<T>>(std::move(InConcept)))
    {}

    void Execute()
    {
        Concept->Execute();
    }

private:
    struct Concept
    {
        virtual ~Concept() = default;
        virtual void Execute() = 0;
    };

    template<typename T>
    struct T_Model :Concept
    {
        T_Model(T InModel)
            :Model(std::move(InModel))
        {}
        void Execute() override { Model.Execute(); }

        T Model;
    };

    std::unique_ptr<Concept> Concept;
};