#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {

    FordJohnsonAlgorithm::PmergeVector pmergeVector;
    FordJohnsonAlgorithm::PmergeDeque pmergedeque;
    clock_t pemergevectorTime;
    clock_t pmergedequeTime;

    if (argc == 1)
	{
		std::cerr << "usage: " << argv[0] << " ...numbers" << std::endl;
		return (1);
	}
    try
    {
    pemergevectorTime = clock();
    pmergeVector.PmergeVectorsort(argv);
    pemergevectorTime = clock() - pemergevectorTime;

    pmergedequeTime = clock();
    pmergedeque.PmergeDequesort(argv);
    pmergedequeTime = clock() - pmergedequeTime;

    pmergeVector.printshit();
    pmergedeque.printshit();

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << (float)pemergevectorTime * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << (float)pmergedequeTime * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}