#include "MultiDeminsionalArray.h"

int main()
{
	M_Array* arr1 = InitArray(3, 3);

	M_Array* arr2;
	arr2 = InitArray(2, 2);

	//Array, index1, index2, number
	SetAt(arr1, 2, 2, 5);

	int num = At(arr1, 2, 2);
	//printf("%d\n\n", num);


	PrintArray(arr1);
	printf("\n");
	//PrintArray(arr2);
	//printf("\n");

	//Resize(arr1, 4, 4);
	//PrintArray(arr1);
	
	FreeArray(arr1);

	return 0;
}