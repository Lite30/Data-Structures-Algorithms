#include<iostream>
using namespace std;


template<class Type>
class ArrayListType
{
    public:

        ArrayListType(int arraySize, int initial);
        ~ArrayListType();
        ArrayListType<Type>& operator=(const Type* arr);
        void selectionSort();
        void printlist();
    protected:
        Type* list;
        int length;
        int maxSize; 
        void swap(int first, int second);
        int minLocation(int first, int last);
};
//constructor
template<class Type>
ArrayListType<Type>::ArrayListType(int arraySize, int initial)
{
    if(arraySize<=0){
        cout <<"Enter array size" <<endl;
        maxSize = 0; //corrected
    }
    else{
        maxSize = arraySize;
        length = initial;;
    }
    list = new Type[maxSize];
}

template<class Type>
ArrayListType<Type>::~ArrayListType()
{
    delete [] list;
    
}

//Overload assignment operator
template<class Type>
ArrayListType<Type>& ArrayListType<Type>::operator=(const Type* arr )
{
    for(int i=0;i<length ; i++)
    {
        list[i]= arr[i];
    }
    return *this;
}
//find the index of the minimum element in the array
template<class Type>
int ArrayListType<Type>::minLocation(int first, int last)
{
    int minIndex = first;
    for(int loc= first + 1; loc <= last;loc++)
        if(list[loc]<list[minIndex])
            minIndex = loc;
    return minIndex;
}

//Swap elements at given indices
template<class Type>
void ArrayListType<Type>::swap(int first,int second)
{
    Type temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

//Perform selcetion sort on the array
template<class Type>
void ArrayListType<Type>::selectionSort()
{
    int minIndex;
    for(int loc = 0; loc < length - 1; loc++)
    {
        minIndex = minLocation(loc, length -1 );
        swap(loc, minIndex);
    }
}


//Print the elements in the array
template <class Type>
void ArrayListType<Type>::printlist()
{
    for(int j = 0; j <length; j++)
    {
        cout << list[j]<<""<<endl;
    }
}
int main()

{   

    
    ArrayListType<int> a1(6,6);
    int arr[] = {16, 8, 10,0,17,6};
    a1 = arr;
    a1.selectionSort();
    a1.printlist();

    return 0;
}
