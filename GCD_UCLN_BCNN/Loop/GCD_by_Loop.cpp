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

// Source: Series: "Algo-Zero" - Code Mely - Dev ơi mình đi đâu thế ?
// Tìm ước chung lớn nhất (UCLN) & Bội chung nhỏ nhất bằng Vòng lặp 

/*------Ý tưởng-----
1/ Tìm UCLN
B1: Tìm số nhỏ hơn giữa 2 số a và b
B2: Duyệt vòng lặp với chỉ số i giảm dần từ min(a,b) tới 1 ( tính cả số 1 và min(a,b))
B3: Nếu cả 2 số a, b đều chia hết cho i thì dừng vòng lặp, i chính là UCLN cần tìm
2/ Tìm BCNN
Sau khi đã có UCLN, có thể dùng công thức a*b=UCLN*BCNN
*/

/*------Pros and cons------
Pros: Đơn giản, dễ tiếp cận đối với người mới. Dung lượng lưu trữ code nhỏ
Cons: code dài dòng, Độ phức tạp của thuật toán chưa tối ưu O(min(a,b)) 
*/

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
