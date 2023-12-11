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

/*Source: GroupFB : Dev ơi mình đi đâu thế?*/

/*DANH SÁCH LIÊN KẾT CÀI ĐẶT BẰNG MẢNG - DANH SÁCH LIÊN KẾT KẾ TIẾP
  LINKED LIST USING ARRAY              - NEXT LINKED LIST
*/

/*-----Các bước thực hiện ý tưởng-----
B1: CÀI ĐẶT DANH SÁCH
    Để khai báo danh sách này ta cần có 1 mảng có số phần tử tối đa là N, có kiểu dữ liệu là item (item này là 
kiểu dữ liệu tổng quan, khi làm nó sẽ là kiểu int, float hay kiểu cấu trúc sinh viên). Cần thêm 1 biến size thể
hiện số phần tử hiện có của danh sách.
B2: KHỞI TẠO DANH SÁCH RỖNG
    Danh sách của ta rỗng khi số phần tử trong danh sách bằng 0. Vì vậy chỉ cần khai báo trường size của ta bằng
0 là được.
B3: KIỂM TRA DANH SÁCH RỖNG, DANH SÁCH ĐẦY
    Để kiểm tra danh sách rỗng hay đầy ta chỉ việc xem số phần tử của danh sách có bằng 0 hay không (rỗng) và có
bằng N hay không (đầy).
B4: CHÈN PHẦN TỬ VÀO VỊ TRÍ K TRONG DANH SÁCH
    Trước khi chèn phần tử vào trong danh sách chúng ta nên xây dựng 1 hàm trả về dữ liệu (nhập vào dữ liệu) của
phần tử cần chèn đó.
    Sau đó tiến hành chèn:
    Trong quá trình chèn chúng ta cần kiểm tra xem danh sách đó đầy chưa, nhập vị trí k cần chèn và kiểm tra nó,
nếu phù hợp (0 < k <= N) thì sẽ tiến hành chèn.
    Để chèn được phần tử x vào vị trí k trong danh sách (trong mảng) ta cần dùng 1 vòng for để di chuyển các phần
tử từ vị trí k về phía cuối mảng, sau đó chèn x vào vị trí k. Cuối cùng ta tăng size lên 1 đơn vị.
B5: NHẬP DANH SÁCH
    Ta nhập như bình thường với mảng.
B6: TÌM PHẦN TỬ X TRONG DANH SÁCH
    Ta duyệt từ đầu đến cuối danh sách nếu có giá trị x thì đưa ra vị trí của nó.
B7: XÓA PHẦN TỬ THỨ K TRONG DANH SÁCH
    Trước khi xóa, ta phải kiểm tra xem danh sách có rỗng không. Nếu không rỗng ta nhập vào vị trí cần xóa và kiểm
tra (phù hợp nếu 0 < k <= N).
    Ta dùng vòng for chạy đến vị trí thứ k, sau đó dồn các phần tử từ k+1 về trước 1 đơn vị. Tuy nhiên ta cần lưu 
lại giá trị của phần tử xóa trước khi xóa để giữ lại thông tin nếu ta cần dùng đến nó. Cuối cùng là giảm size xuống
1 đơn vị.
B8: XÓA PHẦN TỬ CÓ NỘI DUNG X TRONG DANH SÁCH
    Để xóa phần tử có nội dung x trong danh sách ta tiến hành tìm phần tử x trước bằng hàm search sau đó giá trị
trả về là vị trí của x, ta tiếp tục sử dụng hàm del_k để xóa phần tử ở vị trí mà ta tìm được.
*/

#include<bits/stdc++.h>

// Cài đặt danh sách
const int N = 100;
typedef int item;
typedef struct
{
    item Elems[N];  // Tạo mảng có kiểu dữ liệu là item
    int size;       // Số phần tử của mảng
} List;             // Kiểu dữ liệu của danh sách là List

// Khởi tạo danh sách rỗng
void init(List *L)  // Danh sách L được khai báo kiểu con trỏ để khi ra khỏi hàm nó có thể thay đổi được
{
    (*L).size = 0;  // Size = 0
}

// Kiểm tra danh sách rỗng, danh sách đầy
int isempty(List L)
{
    return (L.size == 0);
}

int isfull(List L)
{
    return (L.size == N);
}

// Chèn phần tử vào vị trí k trong danh sách
item init_x()   // Khởi tạo giá trị của x
{
    int temp;
    std::cin >> temp;
    return temp;
}

int Insert_k(List *L, item x, int k)    // Chèn x vào vị trí k
{
    if(isfull(*L))  // Kiểm tra danh sách đầy
    {
        std::cout << "Danh sach day";
        return 0;
    }

    if(k < 1 || k > (*L).size + 1)  // Kiểm tra điều kiện vị trí chèn
    {
        std::cout << "Vi tri chen khong hop le";
        return 0;
    }

    std::cout << "Nhap thong tin can chen";
    x = init_x();   // Gán x bằng hàm khởi tạo x
    // Di chuyển các phần tử về cuối danh sách
    for(int i = (*L).size; i >= k; i--)
    {
        (*L).Elems[i] = (*L).Elems[i-1];
    }
    (*L).Elems[k-1] = x;    // Chèn x vào vị trí k
    (*L).size++;    // Tăng size lên 1 đơn vị
    return 1;
}

// Nhập danh sách
void Input(List *L){
    std::cout << "Nhap so phan tu cua danh sach: ";
    std::cin >> (*L).size;
    for(int i = 0; i < (*L).size; i++)
    {
        std::cout << "Nhap phan tu thu " << i+1 << " : ";
        (*L).Elems[i] = init_x();
    }
}

// In danh sach
void Output(List L){
    std::cout << "Danh sach: ";
    for(int i = 0; i < L.size; i++){
        std::cout << L.Elems[i] << " ";
        std::cout << "\n";
    }
}

// Tìm phần tử x trong danh sách
int Search(List L, item x){
    for(int i = 0; i < L.size; i++){
        if(L.Elems[i] == x) return i+1;
    }
    return 0;
}

// Xóa phần tử thứ k trong danh sách
int Del_k(List *L, item *x, int k){
    if(isempty(*L)){
        std::cout << "Danh sach rong!";
        return 0;
    }
    
    if(k < 1 || k > (*L).size){
        std::cout << "Vi tri xoa khong hop le!";
        return 0;
    }

    *x = (*L).Elems[k-1];   // Lưu lại giá trị của phần tử cần xóa
    for(int i = k-1; i < (*L).size - 1; i++){
        (*L).Elems[i] = (*L).Elems[i+1];
        (*L).size--;    // Giảm size
        return 1;
    }
}

// Xóa phần tử có nội dung x trong danh sách
int  Del_x(List *L, item x){
    if(isempty(*L)){
        std::cout << "Danh sách rong!";
        return 0;
    }

    int i = Search(*L, x);
    if(!i){
        std::cout << "Danh sach khong chua " << x;
        return 0;
    }

    do{
        Del_k(L, &x, i);
        i = Search(*L, x);
    }while(i);

    return 1;
}

int main(){
    List L;
    init(&L);
    Input(&L);
    Output(L);

    int choose;
    std::cout << "Moi ban nhap lua chon thuc hien phep toan: \n";
    std::cout << "1. Kiem tra danh sach rong \n";
    std::cout << "2. Do dai cua danh sach: \n";
    std::cout << "3. Chen phan tu x vao vi tri k trong danh sach: \n";
    std::cout << "4. Tim mot phan tu trong danh sach: \n";
    std::cout << "5. Xoa phan tu tai vi tri k: \n";
    std::cout << "6. Xoa phan tu x trong danh sach: \n";
    std::cout << "7. Thoat \n";

    do{
        std::cout << "Ban chon: \n";
        std::cin >> choose;

        switch(choose){
            case 1:
            {
                if(isempty(L)) std::cout << "Danh sach rong! \n";
                else std::cout << "Danh sach khong rong! \n";
                break;
            }
            case 2:
            {
                std::cout << "Do dai cua danh sach la: " << L.size << "\n";
                break;
            }
            case 3:
            {
                item x;
                int k;
                std::cout << "Nhap vi tri can chen: \n";
                std::cin >> k;
                if(Insert_k(&L, x, k)){
                    std::cout << "Danh sach sau khi chen la: \n";
                    Output(L);
                }
                break;
            }
            case 4:
            {
                item x;
                std::cout << "Nhap phan tu can tim: \n";
                std::cin >> x;
                int k = Search(L, x);
                if(k) std::cout << "Tim thay " << x << " trong danh sach tai vi tri thu " << k << "\n";
                else std::cout << "Khong tim thay " << x << " trong danh sach! \n";
                break;
            }
            case 5:
            {
                int k;
                item x;
                std::cout << "Nhap vi tri can xoa: \n";
                std::cin >> k;
                if(Del_k(&L, &x, k)){
                    std::cout << "Danh sach sau khi xoa la: \n";
                    Output(L);
                }
                break;
            }
            case 6:
            {
                item x;
                std::cout << "Nhap phan tu can xoa: \n";
                std::cin >> x;
                if(Del_x(&L, x)){
                    std::cout << "Danh sach sau khi xoa la: \n";
                    Output(L);
                }
                break;
            }
            case 7: break;
        }
    }while(choose != 7);

    return 0;
}