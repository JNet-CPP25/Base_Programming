#include <iostream>


void mergeSortedArr(int* arr, const int arrSize, int* arrLeft, const int arrLeftSize, int* arrRight, const int arrRightSize);


void mergeSort(int* arr, const int sizeArr);

//Функция печати массива
void arrPrint(int* arr, const int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		std::cout << arr[i] << "\t";
	};
	std::cout << std::endl;
};


int main()
{
	setlocale(LC_ALL, "Russian");

	// 3, 43, 38, 29, 18, 72, 57, 61, 2, 33
	// 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74
	// 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62

	int arr[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };


	std::cout << "Массив до сортировки: \n";
	arrPrint(arr, std::size(arr));

	mergeSort(arr, std::size(arr));

	std::cout << "Массив после сортировки: \n";
	arrPrint(arr, std::size(arr));
}

void mergeSortedArr(int* arr, const int arrSize, int* arrLeft, const int arrLeftSize, int* arrRight, const int arrRightSize)
{
	int iLeft = 0, iRight = 0, i = 0;

	while (arrLeftSize > iLeft && arrRightSize > iRight)
	{
		if (arrLeft[iLeft] <= arrRight[iRight])
		{
			arr[i++] = arrLeft[iLeft++];
		}
		else
		{
			arr[i++] = arrRight[iRight++];
		}
	}
	while (arrLeftSize > iLeft)
	{
		arr[i++] = arrLeft[iLeft++];
	}
	while (arrRightSize > iRight)
	{
		arr[i++] = arrRight[iRight++];
	}
}


void mergeSort(int* arr, const int arrSize)
{
	if (arrSize <= 1)
	{
		return;
	}
	if (arrSize == 2)
	{
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		return;
	}


	int arrLeftSize = arrSize / 2; //разбиваем массив на два подмассива
	int arrRightSize = arrSize - (arrSize / 2);

	int* arrLeft = new int[arrLeftSize];
	int* arrRight = new int[arrRightSize];

	for (int i = 0; i < arrLeftSize; i++)
	{
		arrLeft[i] = arr[i];
	}
	for (int i = 0; i < arrRightSize; i++)
	{
		arrRight[i] = arr[i + arrLeftSize];
	}

	mergeSort(arrLeft, arrLeftSize);
	mergeSort(arrRight, arrRightSize);


	mergeSortedArr(arr, arrSize, arrLeft, arrLeftSize, arrRight, arrRightSize);



	delete[] arrLeft;
	arrLeft = nullptr;
	delete[] arrRight;
	arrRight = nullptr;
}