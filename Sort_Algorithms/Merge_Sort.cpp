/*  _____                                                                             _____  */
/* ( ___ )                                                                           ( ___ ) */
/*  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |  */
/*  |   |                                                                             |   |  */
/*  |   |                                                                             |   |  */
/*  |   |    _   _                       ____                  ____   ___  _ ____     |   |  */
/*  |   |   | | | | __ _ _ __ _ __ _   _|  _ \  ___  _ __ ___ |___ \ / _ \/ |___ \    |   |  */
/*  |   |   | |_| |/ _` | '__| '__| | | | | | |/ _ \| '_ ` _ \  __) | (_) | | __) |   |   |  */
/*  |   |   |  _  | (_| | |  | |  | |_| | |_| | (_) | | | | | |/ __/ \__, | |/ __/    |   |  */
/*  |   |   |_| |_|\__,_|_|  |_|   \__, |____/ \___/|_| |_| |_|_____|  /_/|_|_____|   |   |  */
/*  |   |                          |___/                                              |   |  */
/*  |   |                                                                             |   |  */
/*  |   |                                                                             |   |  */
/*  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|  */
/* (_____)                                                                           (_____) */

/*Source: Code Mely*/

/*-----Bài toán-----
    Giả sử có hai danh sách đã được sắp xếp a[1...m] và b[1...n]. Ta có thể trộn chúng lại thành một danh sách mới
c[1...m+n] được sắp xếp bằng cách so sánh hai phần tử đứng đầu danh sách, lấy phần tử nhỏ hơn cho danh sách mới.
Tiếp tục như vậy cho tới khi một trong hai danh sách là rỗng. Khi một trong hai danh sách là rỗng ta lấy phần còn
lại của danh sách kia cho vào cuối danh sách mới.
*/

/*-----Ý tưởng của bài toán-----
    Ý tưởng của giải thuật này bắt nguồn từ việc trộn 2 danh sách đã sắp xếp thành 1 danh sách mới cũng được sắp
xếp.
*/

/*-----0------
    Độ phức tạp của thuật toán: - Ở mức trung bình
                                - O(nlogn)
    Sử dụng phương pháp chia để trị
*/

#include<bits/stdc++.h>

// Sắp xếp trộn
void merge(int arr[], int left[], int left_size, int right[], int right_size){
    int i = 0, j = 0, k = 0;
    
    // So sánh và trộn các phần tử của hai nửa
    while(i < left_size && j < right_size){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    // Copy các phần tử còn lại của mảng left vào arr nếu có
    while(i < left_size){
        arr[k] = left[i];
        i++;
        k++;
    }
    // Copy các phần tử còn lại của mảng right vào arr nếu có
    while(j < right_size){
        arr[k] = right[i];
        j++;
        k++;
    }
}

// l là chỉ số bên trái và r là chỉ số bên phải của mảng cần được sắp xếp
void mergeSort(int arr[], int size){
    if(size <= 1) return;
    
    int middle = size / 2;
    int left[middle];
    int right[size - middle];

    // Chia mảng thành 2 nửa 
    for(int i = 0; i < middle; i++){
        left[i] = arr[i];
    }
    for(int i = 0; i < middle; i++){
        right[i - middle] = arr[i];
    }

    // Đệ quy sắp xếp từng nửa
    mergeSort(left, middle);
    mergeSort(right, size - middle);

    // Trộn hai nửa đã sắp xếp
    merge(arr, left, middle, right, size - middle);
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << '\n';
}

int main(){
    int size;
    std::cin >> size;
    int arr[size];
    
    for(int i = 0; i < size; i++) 
        std::cin >> arr[i];
    
    mergeSort(arr, size);
    printArray(arr, size);
    return 0;
}