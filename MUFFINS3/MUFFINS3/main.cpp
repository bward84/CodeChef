#include <iostream>
#include <vector>

int main()
{
    int num_cases = 0;
    std::vector<int> results;

    std::cin >> num_cases;

    int num_cakes = 0;
    
    do
    {
        std::cin >> num_cakes;
        if (num_cakes < 3)
            results.push_back(num_cakes);
        else
        {
            results.push_back((num_cakes / 2) + 1);
        }
    } while (--num_cases > 0);

    for (auto val : results)
        std::cout << val << std::endl;

    std::cin >> num_cases;
}