#pragma once

typedef struct Multi_Deminsional_Array
{
	int size;
	int stride;
	int strideCount;
	int* array;
} M_Array;

M_Array* InitArray(int strideSize, int strideAmount);
void FreeArray(M_Array* array);
int At(M_Array* array, int index1, int index2);
void SetAt(M_Array* array, int index1, int index2, int number);
void Resize(M_Array* array, int strideSize, int strideAmount);
void PrintArray(M_Array* array);