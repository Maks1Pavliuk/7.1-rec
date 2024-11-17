#include "pch.h"
#include "CppUnitTest.h"
#include "../7.1 rec/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestCreate)
        {
            const int rowCount = 3;
            const int colCount = 4;
            const int Low = -10;
            const int High = 10;

            int** Q = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                Q[i] = new int[colCount];

            Create(Q, rowCount, colCount, Low, High);

            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    Assert::IsTrue(Q[i][j] >= Low && Q[i][j] <= High);
                }
            }

            for (int i = 0; i < rowCount; i++)
                delete[] Q[i];
            delete[] Q;
        }

        TEST_METHOD(TestCalc)
        {
            const int rowCount = 3;
            const int colCount = 4;

            int** Q = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                Q[i] = new int[colCount];

            int testData[rowCount][colCount] = {
                { 1, 2, 3, 0 },
                { -1, 5, 6, 7 },
                { 9, 0, 11, 12 }
            };

            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    Q[i][j] = testData[i][j];

            int S = 0, k = 0;
            Calc(Q, rowCount, colCount, S, k);

            Assert::AreEqual(36, S); // Сума = 1 + 3 + 5 + 7 + 9 + 11
            Assert::AreEqual(6, k); // Кількість = 6

            for (int i = 0; i < rowCount; i++)
                delete[] Q[i];
            delete[] Q;
        }

        TEST_METHOD(TestSort)
        {
            const int rowCount = 3;
            const int colCount = 4;

            int** Q = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                Q[i] = new int[colCount];

            int testData[rowCount][colCount] = {
                { 4, 3, 2, 1 },
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 }
            };

            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    Q[i][j] = testData[i][j];

            Sort(Q, rowCount, colCount);

            for (int i = 0; i < colCount - 1; i++) {
                Assert::IsTrue(Q[0][i] <= Q[0][i + 1]);
            }

            for (int i = 0; i < rowCount; i++)
                delete[] Q[i];
            delete[] Q;
        }
    };
}
