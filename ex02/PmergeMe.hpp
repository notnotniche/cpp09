#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
#include <ctime>
#include <exception>
#include <cstdlib>

class FordJohnsonAlgorithm
{
    public:
        FordJohnsonAlgorithm();
        FordJohnsonAlgorithm(FordJohnsonAlgorithm const &other);
        FordJohnsonAlgorithm &operator=(FordJohnsonAlgorithm const &other);
        ~FordJohnsonAlgorithm();


        class PmergeVector
        {
            private:
                std::vector<int> vector;
                std::vector<int> track_pos;
                std::vector<std::pair<int, int> > pair_of_vec;
                std::vector<int> main_chain;
                std::vector<int> pend;
                std::vector<int> jacobSequence;

                void getIntegerSequence(char **argv);

                void createVectorPairs();

                void sortVectorPairs();

                void merge(std::vector<std::pair<int, int> > &array, int begin, int middle, int end);

                void mergeSort(std::vector<std::pair<int, int> > &array, int begin, int end);

                void createMainChain();

                int binarySearch(std::vector<int> array, int target, int begin, int end);

                void generateJacobSequence();

                int jacob(int n);

                void generatePoistions();

                void insertInMainChain();
            public:
                PmergeVector();
                ~PmergeVector();
                PmergeVector(PmergeVector const &other);
                PmergeVector &operator=(PmergeVector const &other);

                void printshit();

                void  PmergeVectorsort(char **argv);
        };

        class PmergeDeque
                {
            private:
                std::deque<int> deque;
                std::deque<int> track_pos;
                std::deque<std::pair<int, int> > pair_of_deque;
                std::deque<int> main_chain;
                std::deque<int> pend;
                std::deque<int> jacobSequence;

                void getIntegerSequence(char **argv);

                void createdequePairs();

                void sortdequePairs();

                void merge(std::deque<std::pair<int, int> > &array, int begin, int middle, int end);

                void mergeSort(std::deque<std::pair<int, int> > &array, int begin, int end);

                void createMainChain();

                int binarySearch(std::deque<int> array, int target, int begin, int end);

                void generateJacobSequence();

                int jacob(int n);

                void generatePoistions();

                void insertInMainChain();
            public:
                PmergeDeque();
                ~PmergeDeque();
                PmergeDeque(PmergeDeque const &other);
                PmergeDeque &operator=(PmergeDeque const &other);

                void printshit();

                void  PmergeDequesort(char **argv);
        };
}; 


#endif 