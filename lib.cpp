void swap(int *a, int first, int second)
{
	int temp = a[first];
	a[first] = a[second];
	a[second] = temp;
}

