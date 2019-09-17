// This class defines an element that is stored
// in the garbage collection information list.
//
template <class T>
class PtrDetails
{
  public:
    unsigned refcount; // current reference count
    T *memPtr;         // pointer to allocated memory
    /* isArray is true if memPtr points
to an allocated array. It is false
otherwise. */
    bool isArray; // true if pointing to array
    /* If memPtr is pointing to an allocated
array, then arraySize contains its size */
    unsigned arraySize; // size of array
    // Here, mPtr points to the allocated memory.
    // If this is an array, then size specifies
    // the size of the array.

    PtrDetails(void)
    {
        // TODO: Implement PtrDetails
        refcount = 0;
        memPtr = new T;

    }

    PtrDetails(T *t,int size)
    {
        memPtr = t;
        if(size > 1)
        {
            isArray = true;
            arraySize = size;
        }
        else
        {
            isArray = false;
        }
        refcount = 1;
    }
};
// Overloading operator== allows two class objects to be compared.
// This is needed by the STL list class.
template <class T>
bool operator==(const PtrDetails<T> &ob1,
                const PtrDetails<T> &ob2)
{
    // TODO: Implement operator==
    if(ob1.memPtr == ob2.memPtr){
        return true;
    }else {
        return false;
    }
}
