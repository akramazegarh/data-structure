#include <iostream>
// std::vector
#include <vector>
// std::for_each
#include <algorithm>

std::vector<int> initVector(int method)
{
    std::vector<int> aVector;
    const int aSize = 5;
    int aArray[] = {11, 54, 54, 00 };

    switch (method)
    {
        case 1 :
            aVector = std::vector({771,772,7773});
            break;
        case 2 :
            aVector = std::vector(10,5);
            break;
        case 3 :
            for (int i = 0 ; i < aSize; i++)
            {
                aVector.push_back(i);
            }

            std::for_each(aArray , aArray + 4,[&](const int value)
            {
                aVector.insert(aVector.begin(), value); 
            });            
            break;
        default :
            aVector = std::vector({888888});
    }

    return aVector;
}



int main()
{
    std::cout << std::endl << "[MAIN_START]" << std::endl << std::endl;

    int arr[] = {1, 2, 3, 5, 6};

    std::for_each(arr,arr + 8, [](int aIniType)
    {
        std::cout << std::endl << "INIT TYPE : " << aIniType << std::endl << std::endl;
        auto aVector = initVector(aIniType);

        for (int i : aVector)
        {
            std::cout << "[VECTOR] "<< i << std::endl;
        }
    });

    std::cout << std::endl << "[MAIN_END]" << std::endl << std::endl;

    return 0;
}

