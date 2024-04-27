#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DEBUG

/**
 * stalin_sort - Gets malloc'd array and purges all the traitors within it.
 *
 * @array: Pointer to array of integers.
 * @size: Pointer to size of array.
 *
 * Return: Reallocated arr.
 */
int *stalin_sort(int *array, size_t *size)
{
	size_t i, l, non_traitors;
	int *purged_array;
	int highest_number;

	if (*size == 1)
		return (array);

	/* Counts non triators for memory reallocation */
	for (i = 1, highest_number = array[0],non_traitors = 1; i < *size; i++)
	{
		if (array[i] >= highest_number)
		{
			non_traitors += 1;
			highest_number = array[i];
		}
	}

	/* Allocates new array to accomodate non traitors*/
	purged_array = malloc(non_traitors * sizeof(int));
	if (!purged_array)
		return (NULL);

	/* Purge */
	for (i = 0, l = 0, highest_number = array[0]; i < *size; i++)
	{
		if (i == 0 || array[i] >= highest_number)
		{
			purged_array[l++] = array[i];
			highest_number = array[i];
		}
		else
		{
			printf("%d has been purged.\n", array[i]);
		}
	}

	free(array);
	*size = non_traitors;

	return (purged_array);
}


#ifdef DEBUG
/**
 * print_array - Prints an array of integers.
 *
 * @array: Array of integers.
 * @size: Size of array.
 *
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("[ ");
	for (i = 0; i < size - 1; i++)
		printf("%d, ", array[i]);
	printf("%d ]\n", array[i]);
}

/**
 * main - Mallocs random int array and conditions it to fit the rigime.
 *
 */
int main(void)
{
	int *array;
	size_t size;
	size_t i;

	srand(time(NULL));
	size = (rand() % 25) + 1;

	array = malloc(size * sizeof(int));
	if (!array)
		return (12);

	/* Fill array */
	for (i = 0; i < size; i++)
	{
		array[i] = rand() % 10000;
	}

	print_array(array, size);

	array = stalin_sort(array, &size);

	print_array(array, size);

	free(array);
	return (0);
}
#endif


