#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

// Initializing The Array. 
int arr[50];
int size;

// Getter Functions
int FIRST(int* array)
{
    return array[0];
}

int END(int* array)
{
    return array[size - 1];
}

int LOCATE(int x, int* array)
{
    int i = 0;
    while (array[i] != x)
    {
        i++;
    }
    return i;
}

int RETRIEVE(int p, int* array)
{
    return array[p];
}


// Positional Functions
int NEXT(int x, int* array)
{
    if (x > LOCATE(END(arr), arr))
    {
        return 0; //NULL
    }
    else
    {
        return (x + 1);
    }
}

int PREVIOUS(int x, int* array)
{
    if (x == 0 || x > LOCATE(END(arr), arr))
    {
        return 0; //NULL
    }
    else
    {
        return (x - 1);
    }
}


// Setter Functions
void INSERT(int x, int p, int* array)
{
    size++;
    for (int i = size - 1; i >= p; i--)
    {
        array[i] = array[i - 1];
    }
    array[p] = x;
}

void DELETE(int p, int* array)
{
    size--;
    for (int i = p; i < size; i++)
    {
        array[i] = array[i + 1];
    }
}


// Eraser Function
int MAKENULL(int* array)
{
    int arr[0];
    return &arr;
}
