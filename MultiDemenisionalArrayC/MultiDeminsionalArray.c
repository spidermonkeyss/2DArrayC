#include <stdio.h>
#include "MultiDeminsionalArray.h"

//Must be set to a M_Array pointer before using other functions
M_Array* InitArray(int strideSize, int strideAmount)
{
	M_Array* arr = malloc(sizeof(M_Array));
	arr->size = strideSize * strideAmount;
	arr->stride = strideSize;
	arr->strideCount = strideAmount;
	arr->array = malloc(arr->size * sizeof(int));

	//loop
	for (int i = 0; i < arr->size; i++)
		arr->array[i] = 0;

	return arr;
}

//Memory clean up. Call when done with array
void FreeArray(M_Array* array)
{
	if (array != NULL)
	{
		if (array->array != NULL)
			free(array->array);
		free(array);
	}
}

//Get the vaule at coorinate [x][y]
int At(M_Array* array, int index1, int index2)
{
	return array->array[(index1 * array->stride) + (index2)];
}

//Set the vaule at coordinate [x][y] to number
void SetAt(M_Array* array, int index1, int index2, int number)
{
	array->array[(index1 * array->stride) + (index2)] = number;
}

//Resizes the array to second parameter by third parameter. Keeps previous values
void Resize(M_Array* array, int strideSize, int strideAmount)
{
	//Increase array size
	if (strideSize >= array->stride && strideAmount >= array->strideCount)
	{
		M_Array* arr = malloc(sizeof(M_Array));
		arr->size = strideSize * strideAmount;
		arr->stride = strideSize;
		arr->strideCount = strideAmount;
		arr->array = malloc(arr->size * sizeof(int));

		for (int i = 0; i < arr->size; i++)
			arr->array[i] = 0;

		for (int i = 0; i < array->stride; i++)
		{
			for (int j = 0; j < array->strideCount; j++)
				SetAt(arr, i, j, At(array, i, j));
		}

		array->array = realloc(array->array, arr->size * sizeof(int));

		array->size = strideSize * strideAmount;
		array->stride = strideSize;
		array->strideCount = strideAmount;

		for (int i = 0; i < array->size; i++)
			array->array[i] = arr->array[i];

		FreeArray(arr);
	}
	//Decrease array size
	else
	{

	}
}

//Print array to console in row by column
void PrintArray(M_Array* array)
{
	for (int i = 0; i < array->stride; i++)
	{
		for (int j = 0; j < array->strideCount; j++)
		{
			printf("%d", At(array, i, j));
			if (j < array->strideCount - 1)
				printf(",");
		}
		printf("\n");
	}
}