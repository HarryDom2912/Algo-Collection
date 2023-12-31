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
// Tìm ước chung lớn nhất (UCLN) & Bội chung nhỏ nhất bằng giải thuật Eucild

/*-----Ý tưởng-----
Ý tưởng của giải thuật Euclide tính chất sau:
UCLN của hai số nguyên a và b không thay đổi khi thay số lớn hơn bằng hiệu của nó với số nhỏ hơn.
Sau khi đã có UCLN, hoàn toàn có thể tìm BCNN bằng cách sử dụng một công thức siêu tiện lợi đó là: a*b = UCLN*BCNN
*/

/*-----Pros and Cons-----
Pros: - Độ phức tạp của thuật toán thấp O(log(min(a,b)))
      - Độ chính xác cao
Cons: Khó hiểu hơn cách dùng vòng lặp và đệ quy
*/

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
