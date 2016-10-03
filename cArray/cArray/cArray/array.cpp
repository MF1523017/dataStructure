#include <assert.h>
#include "cArray.h"
int main(int argc, char** argv)
{
    CArray array;
    array_initial(array); 
    array_recap(array, 10); 
    assert(array_capacity(array) == 10); 

    //////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < 20; ++i)
    {
        array_append(array, i); 
    }
    assert(array_size(array) == 20); 
    for (int i = 0; i < array_size(array); ++i)
    {
       assert(array_at(array, i) == i); 
    }

    //////////////////////////////////////////////////////////////////////////
    CArray array2, array3; 
    array_initial(array2); 
    array_initial(array3); 

    array_copy(array, array2); 

    assert(array_compare(array, array2) == true); 
    array_copy(array, array3); 
    assert(array_compare(array, array3) == true); 

    //////////////////////////////////////////////////////////////////////////
    array_insert(array2, 2, 3); 
    assert(array_compare(array, array2) == false); 

    //////////////////////////////////////////////////////////////////////////
    array_at(array3, 2) = 5; 
    assert(array_compare(array, array3) == false); 

    //////////////////////////////////////////////////////////////////////////
    array_destroy(array); 
    array_destroy(array2); 
    array_destroy(array3); 

	return 0;
}