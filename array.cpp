#include <iostream>
// FOR std::size 
#include <iterator>

void fillArray(int iArray[], const int iArraySize)
{
    std::cout << "[FILL] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< " << std::endl;

    for (int i = 0 ; i<iArraySize ; i++)
    {
        std::cout << "[FILL] REF OF  "<< i << " >> "<< &iArray[i] << std::endl;
        iArray[i] = i + 777;
        std::cout << "[FILL] VALUE "<< iArray[i] << std::endl;
    }
    std::cout << "[FILL] =============================== " << std::endl;
    int* aBegin = iArray;
    int* aEnd = iArray + iArraySize;

    for (int* iter = aBegin ; iter != aEnd; iter++)
    {
        std::cout << "[FILL][OUT] REF >> " << iter << std::endl;
        std::cout << "[FILL][OUT] VALUES >> " << *iter << std::endl;
    }

    std::cout << "[FILL] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << std::endl;
}



template <typename T, size_t N>
void computeSize(T (&iArray)[N]) {
    std::cout << "[SIZE] ARRAY SIZE  : " << N << std::endl;
}

int main()
{
    std::cout << "[MAIN] Start\n" << std::endl;

    const int aArraySize = 4;
    int aArray[aArraySize];

    fillArray(aArray, aArraySize);
    computeSize(aArray);

    std::cout << "\n[MAIN] End" << std::endl;

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
