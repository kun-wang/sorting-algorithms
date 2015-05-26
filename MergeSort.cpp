#include "lib.h"
void merge(int *array, int head, int mid, int tail)
{
	int size = tail - head + 1;
	int *tempArray = new int[size];
	for ( int i = 0; i < size; i ++)
		tempArray[i] = array[i + head];
	int beginA = 0, endA = mid - head,
		beginB = mid - head + 1, endB = tail - head,
		beginC = head;
	while ( beginA <= endA && beginB <= endB )
	{
		if ( tempArray[beginA] < tempArray[beginB] )
		{
			array[beginC] = tempArray[beginA];
			beginA ++;
			beginC ++;
		}
		else
		{
			array[beginC] = tempArray[beginB];
			beginB ++;
			beginC ++;
		}
	}
	while ( beginA <= endA )
	{
		array[beginC] = tempArray[beginA];
		beginA ++;
		beginC ++;		
	}
	while ( beginB <= endB )
	{
		array[beginC] = tempArray[beginB];
		beginB ++;
		beginC ++;		
	}
	delete []tempArray;
}
void mergeSort(int *array, int head, int tail)
{
	if ( head < tail )
	{
		int mid = (head + tail)/2;
		mergeSort(array, head, mid);
		mergeSort(array, mid + 1, tail);
		merge(array, head, mid, tail);
	}
}

int main(int argc, char **argv)
{

/*=========================== Console ===========================*
	int a[5] = {4, 3, 5, 2, 1};
	cout << "Before mergeSort: " << endl;
	for ( int i = 0; i < 5; i ++)
		cout << a[i] << "\t";
	cout << endl;

	mergeSort(a, 5);
	
	cout << "After mergeSort: " << endl;
	for ( int i = 0; i < 5; i ++)
		cout << a[i] << "\t";
	cout << endl;
 *=========================== Console ===========================*/

/*=========================== Files =============================*/
	/* Read data from file "data.txt" */
	FILE *reader = fopen("data.txt", "r");
	if ( reader == NULL )
	{
		cerr << "File \"data.txt\" open error." << endl;
		exit(-1);
	}
	int size = 0;
	fscanf(reader, "%d", &size);
	if ( size <= 0 )
	{
		cerr << "Size error." << endl;
		exit(-1);
	}
	int *array = new int[size];
	int temp = 0;
	for (int i = 0; i < size; i ++)
	{
		fscanf(reader, "%d", &temp);
		array[i] = temp;
	}
	fclose(reader);

	/* Sorting */
	mergeSort(array, 0, size - 1);

	/* write to file "sortedData.txt" */
	FILE *writer = fopen("sortedData.txt", "w");
	if ( writer == NULL )
	{
		cerr << "File \"sortedData.txt\" open error." << endl;
		exit(-1);
	}
	fprintf(writer, "%d", size);
	for ( int i = 0; i < size; i ++)
	{
		if ( i % 10 == 0 )
			fprintf(writer, "\n");
		fprintf(writer, "%d\t", array[i]);
	}
	fclose(writer);

	cout << "Done!" << endl;
/*=========================== Files =============================*/
	return 0;
}
