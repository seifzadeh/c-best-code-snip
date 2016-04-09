#include <stdio.h>


void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
	size_t i;
    for ( i=0; i<arraySize; i++)
    {
        array[i] = getNextValue();
        printf("array[%d]=%d\n",i,array[i] );
    }
}

int getNextRandomValue(void)
{
    return rand();
}

int main(int argc, char const *argv[])
{
	 int myarray[10];
    populate_array(myarray, 10, getNextRandomValue);
	return 0;
}

/*
here is no "callback" in C - not more than any other generic programming concept.

They're implemented using function pointers. Here's an example:
Here, the populate_array function takes a function pointer as its third parameter, and calls it to get the values to populate the array with. We've written the callback getNextRandomValue, which returns a random-ish value, and passed a pointer to it to populate_array. populate_array will call our callback function 10 times and assign the returned values to the elements in the given array.

*/
