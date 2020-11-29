#include <iostream>
#include <cstring>

using namespace std;
void createSquare(int *arr, int size)
{
    // set position for 1
    int i = size / 2 + 1;
    int j = size / 2;

    for (int num = 1; num <= size * size;)
    {
        if (j >= size)
        {
            j = j - size;
        }

        if (j == -1)
        {
            j = size - 1;
        }

        if (i >= size)
        {
            i = i - size;
        }

        if (*(arr + i * size + j)) // if aready exist, jump two positions down
        {
            i++;
            j--;
        }
        else
        {

            *(arr + i * size + j) = num++; // set number

            j++;
            i++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {

            cout << *(arr + i * size + j) << "    ";
        }
        cout << endl;
    }
};
int main()
{
    int n = 9;
    // cout << "Please enter n:" << endl;
    // cin >> n;

    int magicSquare[n][n];
    memset(magicSquare, 0, sizeof(magicSquare));
    createSquare((int *)magicSquare, n);

    return 0;
}
