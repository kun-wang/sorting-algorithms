#include "lib.h"

void bubbleSort(int *array, int size)
{
	int i = 0,
		max = size - 1;
	bool flag = false;
	while ( max > 0 )
	{
		i = 0;
		while ( i < max )
		{
			if ( array[i] > array[i+1] )
			{
				swap(array, i, i+1);
				flag = true;
			}
			i++;
		}
		if ( flag == false )
			return;
		max --;
	}
}
int main(int argc, char **argv)
{

/*=========================== Console ===========================*
	int a[5] = {4, 3, 5, 2, 1};
	cout << "Before quickSort: " << endl;
	for ( int i = 0; i < 5; i ++)
		cout << a[i] << "\t";
	cout << endl;

	quickSort(a, 5);
	
	cout << "After quickSort: " << endl;
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
	bubbleSort(array, size);

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
