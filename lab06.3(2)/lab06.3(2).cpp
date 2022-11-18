
#include <iostream>
#include <ctime>

using namespace std;

int FindMin(int arr[], int size);
int FindMinRecurs(int arr[], int size);
int Minim(int a, int b);

//Cпосіб без шаблонів

int main()
{
    double summ = 0;
    int n = 0;


    srand(time(NULL));

    cout << "Input size of array: " << "\n";
    cin >> n;

    int* arr = new int[n];

    cout << "Created array: ";
    for (int k = 0; k < n; k++)
    {
        arr[k] = (rand() % 100) - 49;

        cout << arr[k];
        if (k != n - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << "\n\n";
        }
    }

    cout << "\nMinimal Number: " << FindMinRecurs(arr, n) << endl;

    delete[] arr;
    system("pause");
}

int FindMin(int arr[], int size)
{
    int minNumber = arr[0];

    for (int k = 1; k < size; k++)
    {
        if (minNumber > arr[k])
        {
            minNumber = arr[k];
        }
    }
    return minNumber;
}

int FindMinRecurs(int arr[], int size)
{
    if (size == 1)
        return arr[0];
    return Minim(arr[size - 1], FindMinRecurs(arr, size - 1));
}

int Minim(int a, int b)
{
    return a < b ? a : b;
}

//Cпосіб з шаблонами

template <typename T>
void FindMinRecurs(T arr[], T size)
{
    if (size == 1)
        return arr[0];
    return Minim(arr[size - 1], FindMinRecurs(arr, size - 1));
}

template <typename T>
int Minim(int a, int b)
{
    return a < b ? a : b;
}

