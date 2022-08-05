#include <vector>
#include <initializer_list>

template <typename State, class CostFunction>
class Graph {
    private:
        std::vector<State*> states;
        std::vector<std::vector<size_t>> transitions;

    public:
        Graph () = default;

        explicit Graph(std::initializer_list<State*> il);

        ~Graph ();
};