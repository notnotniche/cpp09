#include "PmergeMe.hpp"


FordJohnsonAlgorithm::FordJohnsonAlgorithm()
{
    std::cout << "Default constructor Called " << std::endl;
}

FordJohnsonAlgorithm::FordJohnsonAlgorithm(FordJohnsonAlgorithm const &other)
{
    std::cout << "Copy constructor Called " << std::endl;
    *this = other;
}

FordJohnsonAlgorithm::~FordJohnsonAlgorithm()
{
    std::cout << "Destructor Called " << std::endl;
}  

FordJohnsonAlgorithm &FordJohnsonAlgorithm::operator=(FordJohnsonAlgorithm const &other)
{
    std::cout << "Copy assignment operator Called " << std::endl;
    (void)other;
	return (*this);
}

void FordJohnsonAlgorithm::PmergeVector::getIntegerSequence(char **argv)
{
	int index = 1;
	char *ptr;

	int value;
	try
	{
		while (argv[index])
		{
			if (argv[1][0] == '\0')
			{
				throw std::runtime_error("ERROR: Empty string");
			}
			value = strtol(argv[index], &ptr, 10);

			if (*ptr != '\0' || value < 0)
			{
				throw std::runtime_error("ERROR: Invalid character");
			}
			this->vector.push_back(value);
			std::cout << "Value: " << value << std::endl;
			index++;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		exit(1);
	}
}
//TODO :FUCKING FIX CREATING PAIRS GO TO SLEEP AND FINISH THIS IN 10 HOURS LETS GO
void FordJohnsonAlgorithm::PmergeVector::createVectorPairs()
{
	int size;
	unsigned int i;

	i = 0;
	size = this->vector.size() / 2;
	while (size != 0)
	{
		this->pair_of_vec.push_back(std::make_pair(this->vector.at(i), this->vector.at(i + 1)));
		i += 2;
		size--;
	}
}

void FordJohnsonAlgorithm::PmergeVector::sortVectorPairs()
{
    //iterate through the vector and sort the pairs
    unsigned int i; int tmp;  i = 0;
    while (i < this->pair_of_vec.size())
    {
        if (this->pair_of_vec[i].first < this->pair_of_vec[i].second)
        {
            tmp = this->pair_of_vec[i].first;
            this->pair_of_vec[i].first = this->pair_of_vec[i].second;
            this->pair_of_vec[i].second = tmp;
        }
        std::cout << pair_of_vec[i].first << " " << pair_of_vec[i].second << std::endl;
        i++;
    }
}

void FordJohnsonAlgorithm::PmergeVector::merge(std::vector<std::pair<int, int> > &array, int begin, int middle, int end)
{
    size_t leftarrayIndex;
    size_t rightarrayIndex;
    size_t mergedArrayIndex;

	std::vector<std::pair<int, int> > leftArray(array.begin() + begin, array.begin() + middle + 1);
	std::vector<std::pair<int, int> > rightArray(array.begin() + middle + 1, array.begin() + end + 1);

	while (leftarrayIndex < leftArray.size() && rightarrayIndex < rightArray.size())
	{
		if (leftArray[leftarrayIndex].first <= rightArray[rightarrayIndex].first)
		{
			array[mergedArrayIndex] = leftArray[leftarrayIndex];
			leftarrayIndex++;
		}
		else
		{
			array[mergedArrayIndex] = rightArray[rightarrayIndex];
			rightarrayIndex++;
		}
		mergedArrayIndex++;
	}
	while (leftarrayIndex < leftArray.size())
	{
		array[mergedArrayIndex] = leftArray[leftarrayIndex];
		leftarrayIndex++;
		mergedArrayIndex++;
	}
	while (rightarrayIndex < rightArray.size())
	{
		array[mergedArrayIndex] = rightArray[rightarrayIndex];
		rightarrayIndex++;
		mergedArrayIndex++;
	} 
}

FordJohnsonAlgorithm::PmergeVector::PmergeVector()
{
}

FordJohnsonAlgorithm::PmergeVector::~PmergeVector()
{
}

void FordJohnsonAlgorithm::PmergeVector::PmergeVectorsort(char **argv)
{
    this->getIntegerSequence(argv);
    if (this->vector.size() == 1)
    {
        this->main_chain.push_back(this->vector[0]);
    }
    else
    {
    this->createVectorPairs();
    this->sortVectorPairs();
    this->mergeSort(this->pair_of_vec, 0, this->pair_of_vec.size() - 1);
    this->createMainChain();
    this->insertInMainChain();
    }

    // Print the vector
    std::cout << std::endl;
}

void FordJohnsonAlgorithm::PmergeVector::mergeSort(std::vector<std::pair<int, int> > &array, int begin, int end)
{
    int mid;

    if (begin >= end)
        return;

    mid = begin + (end - begin) / 2;
    this->mergeSort(array,begin, mid);
    this->mergeSort(array, mid + 1, end);
    this->merge(array, begin, mid, end);
}

void FordJohnsonAlgorithm::PmergeVector::createMainChain()
{
    size_t i;

    main_chain.push_back(this->pair_of_vec.at(0).second);

    i = 0;
    while (i < this->pair_of_vec.size())
    {
        main_chain.push_back(this->pair_of_vec.at(i).first);
        pend.push_back(this->pair_of_vec.at(i).second);
        i++;
    }
}

int FordJohnsonAlgorithm::PmergeVector::binarySearch(std::vector<int> array, int target, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target == array.at(mid))
			return (mid);

		if (target > array.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (target > array.at(mid))
		return (mid + 1);
	else
		return (mid);
}

int FordJohnsonAlgorithm::PmergeVector::jacob(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacob(n - 1) + 2 * jacob(n - 2));   
}

void FordJohnsonAlgorithm::PmergeVector::generateJacobSequence()
{
	size_t size;
	size_t jcobstalIndex;
	int index;

	size = this->pend.size();
	index = 3;

	while ((jcobstalIndex = this->jacob(index)) < size - 1)
	{
		this->jacobSequence.push_back(jcobstalIndex);
		index++;
	}
}

void FordJohnsonAlgorithm::PmergeVector::generatePoistions()
{
	size_t val;
	size_t pos;
	size_t lastPos;
	size_t i;

	if (this->pend.empty())
		return;
	this->generateJacobSequence();
	lastPos = 1;
	val = 1;
	i = 0;
	while (i < this->jacobSequence.size())
	{
		val = this->jacobSequence.at(i);

		this->track_pos.push_back(val);

		pos = val - 1;
		while (pos > lastPos)
		{
			this->track_pos.push_back(pos);
			pos--;
		}
		lastPos = val;
		i++;
	}
	while (val++ < this->pend.size())
		this->track_pos.push_back(val);
}

void FordJohnsonAlgorithm::PmergeVector::insertInMainChain()
{
	std::vector<int>::iterator it;
	int target;
	size_t endPos;
	size_t addedCount;
	size_t pos;

	this->generatePoistions();
	addedCount = 0;

	for (it = this->track_pos.begin(); it < this->track_pos.end(); it++)
	{
		target = this->pend.at(*it - 1);

		endPos = *it + addedCount;
		pos = this->binarySearch(this->main_chain, target, 0, endPos);
		this->main_chain.insert(this->main_chain.begin() + pos, target);
		addedCount++;
	}
	if (this->vector.size() % 2 != 0)
	{
		target = this->vector.at(this->vector.size() - 1);
		pos = this->binarySearch(this->main_chain, target, 0, this->main_chain.size() - 1);
		this->main_chain.insert(this->main_chain.begin() + pos, target);
	}
}

void FordJohnsonAlgorithm::PmergeVector::printshit()
{
	std::cout << "before : ";
	for (int i = 0; i < this->vector.size(); i++)
		std::cout << this->vector.at(i) << " ";
	std::cout << std::endl << "after : ";
	for (int i =0; i < this->main_chain.size(); i++)
		std::cout << this->main_chain.at(i) << " ";
	std::cout << std::endl;
}


void FordJohnsonAlgorithm::PmergeDeque::printshit()
{
	std::cout << "before : ";
	for (int i = 0; i < this->deque.size(); i++)
		std::cout << this->deque.at(i) << " ";
	std::cout << std::endl << "after : ";
	for (int i =0; i < this->main_chain.size(); i++)
		std::cout << this->main_chain.at(i) << " ";
	std::cout << std::endl;
}

void FordJohnsonAlgorithm::PmergeDeque::getIntegerSequence(char **argv)
{
    int index = 1;
    char *ptr;
    int value;
	try {
		while (argv[index])
		{
			if (argv[1][0] == '\0')
			{
				throw std::runtime_error("ERROR: Empty string");
				exit(1);
			}
			value = strtol(argv[index], &ptr, 10);

			if (*ptr != '\0' || value < 0)
			{
				throw std::runtime_error("ERROR: Invalid character");
				exit(1);
			}
			this->deque.push_back(value);
			std::cout << "Value: " << value << std::endl;
			index++;
		}
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		exit(1);
	}

}

void FordJohnsonAlgorithm::PmergeDeque::createdequePairs()
{
	int size;
	unsigned int i;

	i = 0;
	size = this->deque.size() / 2;
	while (size != 0)
	{
		this->pair_of_deque.push_back(std::make_pair(this->deque.at(i), this->deque.at(i + 1)));
		i += 2;
		size--;
	}
}


void FordJohnsonAlgorithm::PmergeDeque::sortdequePairs()
{
	unsigned int i;
	int tmp;

	i = 0;
	while (i < this->pair_of_deque.size())
	{
		if (this->pair_of_deque.at(i).first < this->pair_of_deque.at(i).second)
		{
			tmp = this->pair_of_deque.at(i).first;
			this->pair_of_deque.at(i).first = this->pair_of_deque.at(i).second;
			this->pair_of_deque.at(i).second = tmp;
		}
		i++;
	}
}

void FordJohnsonAlgorithm::PmergeDeque::merge(std::deque<std::pair<int, int> > &array, int begin, int middle, int end)
{
	size_t leftArrayIndex;
	size_t rightArrayIndex;
	size_t mergedArrayIndex;

	std::deque<std::pair<int, int> > leftArray(array.begin() + begin, array.begin() + middle + 1);
	std::deque<std::pair<int, int> > rightArray(array.begin() + middle + 1, array.begin() + end + 1);

	leftArrayIndex = 0;
	rightArrayIndex = 0;
	mergedArrayIndex = begin;

	while (leftArrayIndex < leftArray.size() && rightArrayIndex < rightArray.size())
	{
		if (leftArray[leftArrayIndex].first <= rightArray[rightArrayIndex].first)
		{
			array[mergedArrayIndex] = leftArray[leftArrayIndex];
			leftArrayIndex++;
		}
		else
		{
			array[mergedArrayIndex] = rightArray[rightArrayIndex];
			rightArrayIndex++;
		}
		mergedArrayIndex++;
	}
	while (leftArrayIndex < leftArray.size())
	{
		array[mergedArrayIndex] = leftArray[leftArrayIndex];
		leftArrayIndex++;
		mergedArrayIndex++;
	}
	while (rightArrayIndex < rightArray.size())
	{
		array[mergedArrayIndex] = rightArray[rightArrayIndex];
		rightArrayIndex++;
		mergedArrayIndex++;
	}
}

void FordJohnsonAlgorithm::PmergeDeque::mergeSort(std::deque<std::pair<int, int> > &array, int begin, int end)
{
	int mid;

	if (begin >= end)
		return;
	mid = begin + (end - begin) / 2;
	this->mergeSort(array, begin, mid);
	this->mergeSort(array, mid + 1, end);
	this->merge(array, begin, mid, end);
}

void FordJohnsonAlgorithm::PmergeDeque::createMainChain()
{
	size_t i;

	main_chain.push_back(this->pair_of_deque.at(0).second);

	i = 0;
	while (i < this->pair_of_deque.size())
	{
		main_chain.push_back(this->pair_of_deque.at(i).first);
		pend.push_back(this->pair_of_deque.at(i).second);
		i++;
	}
}
FordJohnsonAlgorithm::PmergeDeque::PmergeDeque()
{
}

FordJohnsonAlgorithm::PmergeDeque::~PmergeDeque()
{
}

int FordJohnsonAlgorithm::PmergeDeque::binarySearch(std::deque<int> array, int target, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target == array.at(mid))
			return (mid);

		if (target > array.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (target > array.at(mid))
		return (mid + 1);
	else
		return (mid);
}

int FordJohnsonAlgorithm::PmergeDeque::jacob(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacob(n - 1) + 2 * jacob(n - 2));   
}

void FordJohnsonAlgorithm::PmergeDeque::generateJacobSequence()
{
	size_t size;
	size_t jcobstalIndex;
	int index;

	size = this->pend.size();
	index = 3;

	while ((jcobstalIndex = this->jacob(index)) < size - 1)
	{
		this->jacobSequence.push_back(jcobstalIndex);
		index++;
	}
}

void FordJohnsonAlgorithm::PmergeDeque::generatePoistions()
{
	size_t val;
	size_t pos;
	size_t lastPos;

	if (this->pend.empty())
		return;
	this->generateJacobSequence();
	lastPos = 1;
	val = 1;
	while (!this->jacobSequence.empty())
	{
		val = this->jacobSequence.front();

		this->jacobSequence.pop_front();
		this->track_pos.push_back(val);

		pos = val - 1;
		while (pos > lastPos)
		{
			this->track_pos.push_back(pos);
			pos--;
		}
		lastPos = val;
	}
	while (val++ < this->pend.size())
		this->track_pos.push_back(val);
}

void FordJohnsonAlgorithm::PmergeDeque::insertInMainChain()
{
	std::deque<int>::iterator it;
	int target;
	size_t endPos;
	size_t addedCount;
	size_t pos;

	this->generatePoistions();
	addedCount = 0;

	for (it = this->track_pos.begin(); it < this->track_pos.end(); it++)
	{
		target = this->pend.at(*it - 1);

		endPos = *it + addedCount;
		pos = this->binarySearch(this->main_chain, target, 0, endPos);
		this->main_chain.insert(this->main_chain.begin() + pos, target);
		addedCount++;
	}
	if (this->deque.size() % 2 != 0)
	{
		target = this->deque.at(this->deque.size() - 1);
		pos = this->binarySearch(this->main_chain, target, 0, this->main_chain.size() - 1);
		this->main_chain.insert(this->main_chain.begin() + pos, target);
	}
}

void FordJohnsonAlgorithm::PmergeDeque::PmergeDequesort(char **argv)
{
    this->getIntegerSequence(argv);
    if (this->deque.size() == 1)
    {
        this->main_chain.push_back(this->deque[0]);
    }
    else
    {
    this->createdequePairs();
    this->sortdequePairs();
    this->mergeSort(this->pair_of_deque, 0, this->pair_of_deque.size() - 1);
    this->createMainChain();
    this->insertInMainChain();
    }

    // Print the deque
    std::cout << std::endl;
}