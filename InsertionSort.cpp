#include "lib.h"

/*void insertionSort(int *a, int size) sorts elements of int in a[0:size-1]
 * by increasing mode.
 */
void insertionSort(int *a, int size)
{
	int temp = 0,
		i = 0,
		j = 0;
	while ( i < size )
	{
		temp = a[i];
		j = i - 1;
		while ( j >= 0 )
		{
			if ( a[j] > temp )
			{
				swap(a[j], a[j+1]);
				j--;
			}
			else
			{
				a[j+1] = temp;
				break;
			}
		}
		a[j+1] = temp;
		i++;
	}
}
int main(int argc, char **argv)
{

/*=========================== Console ===========================*
	int a[5] = {4, 3, 5, 2, 1};
	cout << "Before insertionSort: " << endl;
	for ( int i = 0; i < 5; i ++)
		cout << a[i] << "\t";
	cout << endl;

	insertionSort(a, 5);
	
	cout << "After insertionSort: " << endl;
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
	insertionSort(array, size);

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
