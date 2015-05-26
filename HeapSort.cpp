#include "lib.h"

/*fixHeap(int *array, int size, int root, int element) inserts element
 * into max heap's root, then continue to fix it
 */
void fixHeap(int *array, int size, int root, int element)
{
	int left = root*2 + 1,
		right = root*2 + 2;
	if ( left > size - 1 )
		array[root] = element;
	else
	{
		int larger = left;
		if ( left == size-1 )
			larger = left;
		else if ( array[left] > array[right] )
			larger = left;
		else
			larger = right;
		if ( element > array[larger] )
			array[root] = element;
		else
		{
			array[root] = array[larger];
			fixHeap(array, size, larger, element);
		}
	}
}

void constructHeap(int *array, int size, int root)
{
	int left = root*2 + 1,
		right = root*2 + 2;
	if ( left <= size - 1 )
		constructHeap(array, size, left);
	if ( right <= size -1 )
		constructHeap(array, size, right);
	int max = array[root];
	fixHeap(array, size, root, max);
}

void heapSort(int *array, int size)
{
	/* Construct max heap first */
	constructHeap(array, size, 0);
	/* Repeatly remove max data from max heap and rearrange it */
	int loc = 0;
	for (loc = size - 1; loc > 0; loc --)
	{
		int max = array[0];
		fixHeap(array, loc, 0, array[loc]);
		array[loc] = max;
	}
}

int main(int argc, char **argv)
{

/*=========================== Console ===========================
	int a[6] = {10, 100, 3, 57, 49, 68};
	cout << "Before heapSort: " << endl;
	for ( int i = 0; i < 6; i ++)
		cout << a[i] << "\t";
	cout << endl;

	heapSort(a, 6);
	
	cout << "After heapSort: " << endl;
	for ( int i = 0; i < 6; i ++)
		cout << a[i] << "\t";
	cout << endl;
 *=========================== Console ===========================*/

/*=========================== Files =============================*/
	// Read data from file "data.txt" 
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

	// Sorting
	heapSort(array, size);

	// write to file "sortedData.txt"
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

