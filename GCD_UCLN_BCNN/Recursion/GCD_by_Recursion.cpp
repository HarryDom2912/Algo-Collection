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
// Tìm ước chung lớn nhất (UCLN) & Bội chung nhỏ nhất bằng Đệ quy

/*-----Pros and cons------
Pros: Đơn giản, dễ tiếp cận, code ngắn gọn, dung lượng lưu trữ code nhỏ.
Cons: Có thể gây tràn bộ nhớ trong một số trường hợp đặt biệt.
      Có thể khó hiểu và khó bảo trì hơn so với vòng lặp.
      Độ phức tạp của thuật toán chưa tối ưu O(min(a,b)).
*/

#include <iostream>

int GCD(int a, int b, int i){
    if(a%i == 0 && b%i == 0) return i;
    // Nếu a và b cùng chia hết cho i trả về kết quả cho hàm
    return GCD(a, b, i--); // Gọi đệ quy vè i giảm 1
}

int main(){
    int a, b, i;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

    i = a > b ? b : a;
    // Gán cho i giá trị nhỏ hơn trong 2 số a và b
    std::cout << "UCLN = " << GCD(a, b, i) << std::endl;
    std::cout << "BCNN = " << a*b/GCD(a, b, i) << std::endl;

    return 0; 
}
