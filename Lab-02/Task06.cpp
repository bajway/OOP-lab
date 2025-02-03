/*Time to code a program that manages an ever-growing hungry integer array! The array
starts small with a size of 5, but every time you keep stuffing it with numbers and it gets
full, it will double in size to satisfy its appetite. Once you're done feeding it all the elements,
the array will go on a diet and shrink down to perfectly fit the number of elements it holds.
No wasted space, no extra fluff—just a happy, well-fed array.*/
#include <iostream>
using namespace std;

void double_size(int* array, int* current_size){
    int new_size = *current_size * 2;
    int* new_array = new int[new_size];
    for (int i = 0; i < *current_size; ++i)
    {
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
    *current_size = new_size;
}
void shrinkArray(int* array, int num_elements){
    int* new_array = new int[num_elements];
    for (int i = 0; i < num_elements; ++i)
    {
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
}
void addElements(int* array, int element, int& num_elements, int& current_size){

    if (num_elements == current_size){
        double_size(array, &current_size);
    }
    array[num_elements] = element;
    num_elements++;
}

void printArray(int* array, int num_elements){
    for (int i = 0; i < num_elements; ++i){
        cout << array[i] << " ";
    }
    cout << endl;
}
int main(){
    int current_size = 5;
    int num_elements = 0;
    int* array = new int[current_size];
    //adding elements
    for (int i = 0; i < 12; ++i){
        addElements(array, i + 1, num_elements, current_size);
        cout << "Array after adding " << i + 1 << ": ";
        printArray(array, num_elements);
    }

    //to resize the array
    shrinkArray(array, num_elements);
    cout << "Array after shrinking to fit: ";
    printArray(array, num_elements);
    
    delete[] array;    //to free memoryy

    return 0;
}