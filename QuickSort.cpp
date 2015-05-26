#include "lib.h"

int partition(int *array, int head, int tail)
{
	int pivot = array[head];
	while ( head < tail )
	{
		while ( head < tail && array[tail] >= pivot )
			tail --;
		if ( head < tail )
			array[head++] = array[tail];
		while ( head < tail && array[head] <= pivot )
			head ++;
		if ( head < tail )
			array[tail--] = array[head];
	}
	array[head] = pivot;
	return head;
}

void quickSort(int *array, int head, int tail)
{
	if ( head < tail )
	{
		int mid = partition(array, head, tail);
		quickSort(array, head, mid-1);
		quickSort(array, mid+1, tail);
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
	quickSort(array, 0, size - 1);

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


