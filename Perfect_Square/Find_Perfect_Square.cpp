#include<iostream>
#include<math.h>
#include<iomanip>

int main(){
int S, a;
int temp1 = std::floor(sqrt(a))*std::floor(sqrt(a));
int temp2 = std::ceil(sqrt(a))*std::ceil(sqrt(a));
if(abs(a - temp1) > abs(a - temp2)) S = temp2;
else S = temp1;
}