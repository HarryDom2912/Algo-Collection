// Source: Series: "Algo-Zero" - Code Mely - Dev ơi mình đi đâu thế ?
// Tìm ước chung lớn nhất (UCLN) & Bội chung nhỏ nhất bằng Vòng lặp 

#include <iostream>

int GCD(int a, int b, int i){
    while(i >= 1){
        // Nếu a và b cùng chia hết cho i => thoát vòng lặp
        if(a%i == 0 && b%i == 0)
            break;
        i--;
    }
    return i; // Trả về i, i là UCLN của a và b
}

int main(){
    int a, b, i;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

    i = a > b ? b : a;
    // Gán cho i giá trị nhỏ hơn giữa a và b
    std::cout << "UCLN = " << GCD(a, b, i) << std::endl;
    std::cout << "BCNN = " << a*b/GCD(a, b, i) << std::endl;

    return 0; 
}