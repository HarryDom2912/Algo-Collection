// Source: Series: "Algo-Zero" - Code Mely - Dev ơi mình đi đâu thế ?
// Tìm ước chung lớn nhất (UCLN) & Bội chung nhỏ nhất bằng giải thuật Eucild

#include <iostream>

// Hàm đệ quy dùng giải thuật Euclid để tìm UCLN
int GCD(int a, int b){
    if(b==0) return a;
    return GCD(b, a%b);
}

int main(){
    int a, b;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

    std::cout << "UCLN = " << GCD(a, b) << std::endl;
    std::cout << "BCNN = " << a*b/GCD(a, b) << std::endl;

    return 0; 
}