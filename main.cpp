#include <iostream>
#include <vector>
#include <algorithm>

class BeautifulNumbersCounter
{
private:
    const int numeralSystem = 13;

    long getPartNumbersCount(int digitsCount, int numeralSystem)
    {
        int maxDigitValue = numeralSystem - 1;
        std::vector<std::vector<long>> partialSolutions(digitsCount, std::vector<long>(numeralSystem, 0));

        for (int k = 0; k <= maxDigitValue; ++k)
        {
            partialSolutions[0][k] = 1;
        }

        for (int n = 1; n < digitsCount; ++n)
        {
            int maxSum = (n + 1) * maxDigitValue;
            partialSolutions[n] = std::vector<long>(maxSum + 1, 0);
            for (int k = maxSum; k >= 0; --k)
            {
                int statIndex = std::max(0, k - n * maxDigitValue);
                for (int i = statIndex; i < numeralSystem && i <= k; ++i)
                {
                    partialSolutions[n][k] += partialSolutions[n - 1][k - i];
                }
            }
        }

        long result = 0;
        for (int k = 0; k <= maxDigitValue * digitsCount; ++k)
        {
            result += partialSolutions[digitsCount - 1][k] * partialSolutions[digitsCount - 1][k];
        }
        return result;
    }

public:
    long GetNumbersCount()
    {
        int digitsCount = 6; 
        return getPartNumbersCount(digitsCount, numeralSystem) * numeralSystem;
    }
};

int main()
{
    BeautifulNumbersCounter bns;
    long numbersCount = bns.GetNumbersCount();
    std::cout << "Result = " << numbersCount << std::endl;
    

    return 0;
}
