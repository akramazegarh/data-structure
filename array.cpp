#include <iostream>
// std::size 
#include <iterator>
// std::span
#include <span>
// std::for_each
#include <algorithm>


void fillArray(int iArray[], const int iArraySize)
{
    std::cout << "[FILL_START]" << std::endl << std::endl;
    for (int i = 0 ; i<iArraySize ; i++)
    {
        iArray[i] = i + 777;
    }

    std::cout << "[IERATOR]" << std::endl;
    int* aBegin = iArray;
    int* aEnd = iArray + iArraySize;
    for (int* iter = aBegin ; iter != aEnd; iter++)
    {
        std::cout << "[FILL][OUT] REF    >> " << iter << std::endl;
        std::cout << "[FILL][OUT] VALUES >> " << *iter << std::endl;
    }

    std::cout << "[SPAN]" << std::endl;
    for (const int& value : std::span(iArray, iArraySize))
    {
        std::cout << "[FILL][OUT] REF    >> " << &value << std::endl;
        std::cout << "[FILL][OUT] VALUES >> " << value << std::endl;
    }

    std::cout << "[for_each]" << std::endl;
    std::for_each(aBegin, aEnd, [](int value)
    {
        std::cout << "[FILL][OUT] REF    >> " << &value << std::endl;
        std::cout << "[FILL][OUT] VALUES >> " << value << std::endl;
    });

    std::cout << std::endl << "[FILL_END]" << std::endl << std::endl;
}



template <typename T, size_t N>
void computeSize(T (&iArray)[N]) {
    std::cout << "[SIZE] ARRAY SIZE  >> " << N << std::endl;
}

int main()
{
    std::cout << std::endl << "[MAIN_START]" << std::endl << std::endl;

    const int aArraySize = 4;
    int aArray[aArraySize];

    fillArray(aArray, aArraySize);
    computeSize(aArray);

    std::cout << std::endl << "[MAIN_END]" << std::endl << std::endl;

    return 0;
}













// TRASH  ==============================================================================

// void computeSizeWrong(int iArray[])
// {
//     std::cout << "[SIZE_WRONG] ====================================== " << iArray << std::endl;
//     std::cout << "[SIZE_WRONG] ARRAY SIZE  " << sizeof(iArray) << std::endl;
//     std::cout << "[SIZE_WRONG] ELEM SIZE  " << sizeof(iArray[0]) << std::endl;
//     std::cout << "[SIZE_WRONG] SIZE  " << sizeof(iArray) / sizeof(iArray[0]) << std::endl;
//     std::cout << "[SIZE_WRONG] ====================================== " << *iArray << std::endl;
// }
