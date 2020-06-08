#include <iostream>

int binarySearch(int item, int *a, int n = 10){
    int low = 0, mid = 0, high = n - 1;
    std::cout << a[3]<< std::endl;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (a[mid] < item)
        {
            low = mid + 1;
        }
        else if(a[mid] > item){
            high = mid - 1;
        }
        else{
            std::cout << mid << std::endl;
            return mid;
        }
    }
    return 0;
}

int main(){
    int array[10] = {-45, -40, -30, -20, 0, 10, 20, 40, 50, 60};
    int count = 0, count1 = 0, k = 0;

    //faster algorithm O(N^2.logN)
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = i + 1; j < 10; j++)
        {
            //a + b + c = 0 then c = -(a + b)
            k += binarySearch((-(array[i] + array[j])), array, 10);
            if(array[i] < array[j] && array[j] < array[k])  count += 1;
        }
    }
    

    //slower algorithm O(N^3)
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = i + 1; j < 10; j++)
        {
            for (size_t k = j + 1; k < 10; k++)
            {
                if((array[i] + array[j] + array[k]) == 0){
                    count1 += 1;
                }
            }
            
        }
    }
    std::cout << count << " " << count1 << std::endl;
    return 0;
}