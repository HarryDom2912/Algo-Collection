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

/*-----Thuật toán tìm số fibonacci sử dụng Đệ quy và Map-----*/
/*-----Search Fibonacci number algorithms using Recursion with Map-----*/

#include <iostream>
#include <map>

using namespace std;

map<long long, long long> F;

long long Fibonacci(long long n){
    if(F.count(n)) return F[n];
    long long k = n / 2;
    if(n % 2 == 0) return F[n] = (Fibonacci(k) * Fibonacci(k) + Fibonacci(k - 1) * Fibonacci(k - 1));
    else return F[n] = (Fibonacci(k) * Fibonacci(k + 1) + Fibonacci(k - 1) * Fibonacci(k));
    return 0;
}

int main(){
    F[0] = F[1] = 1;
    for(int i = 0; i < 20; i++) std::cout << (i == 0 ? 0 : Fibonacci(i - 1)) << " ";
}