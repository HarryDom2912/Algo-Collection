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

// Source: Group FB: Dev oi mình đi đâu thế?
// Cây AVL - AVL Tree

/*-----Lý thuyết-----
    Cây AVL ( AVL là viết tắt tên của các tác giả phát minh ra nó Adelson-Velsky và Landis) là một cây tìm kiếm nhị
phân có khả năng tự cân bằng, điều đó giúp cho cây AVL tối ưu hơn rất nhiều so với tìm kiếm nhị phân.

    Cây AVL là cây nhị phân tìm kiếm cân bằng với "chiều cao" giữa cây con bên trái và cây con bên phải chênh nhau
không vượt quá 1. Hay nói cách khác, BST mà cây con bên trái và phải của mọi Node có "chiều cao" chênh lệch không
vượt 1 thì chính là cây AVL.
*/
 
/*-----Định nghĩa-----
    Chiều cao của một Node chính là số các node trên một đường dẫn dài nhất từ Node đó đến Node = NULL. Và quy ước
Node = NULL có chiều cao bằng 0.
*/

/*-----Kĩ thuật quay cây-----
    Cây BST khi không cân bằng sẽ lệch trái hoặc phải -> để điều chỉnh ta cần quay cây sang phía ngược lại.
*/

/*-----Các trường hợp bị lệch-----
    1.Trái trái (Left Left):
Gọi Node X và Y lần lượt là con trái và con phải của root. Node Z là node mới được thêm vào cây con trái của X.
Xảy ra lệch trái khi: +height(X) - height(Y) > 1 và value(Z) < value(X).
Giải pháp: quay phải Node root (rightRotate(root)).
    
    2.Trái phải (Left Right):
Gọi Node X và Y lần lượt là con của root. Node Z là node được thêm vào cây con phải của X.
Xảy ra lệch trái phải khi: +height(X) - height(Y) > 1 và value(Z) > value(X).
Giải pháp: leftRotate(X) -> rightRotate(root).
    
    3.Phải phải (Right Right):
Gọi Node X và Y lần lượt là con của root. Node Z là node được thêm vào cây con phải của Y.
Xảy ra lệch phải phải khi: +height(X) - height(Y) < -1 và value(Z) > value(Y).
Giải pháp: quay trái Node root (leftRotate(root)).

    4.Phải trái (Right Left):
Gọi Node X và Y lần lượt là con của root. Node Z là node được thêm vào cây con trái của Y.
Xảy ra lệch phải trái khi: +height(X) - height(Y) < -1 và value(Z) < value(Y).
Giải pháp: rightRotate(Y) -> leftRotate(root).
*/

/*-----Phép chèn và tính cân bằng cây AVL-----
    Giả sử có một cây AVL và u là một nút của T, một nút mới v được chèn vào u. v sẽ được chèn vào một trong hai
cây con của u => v có thể làm tăng chiều cao của hai cây con đó. Nếu v không làm tăng chiều cao của cây con nào 
hoặc làm tăng chiều cao của cây con có chiều cao nhỏ hơn => tính cân bằng AVL tại đỉnh u vẫn giữ nguyên. Tính cân
bằng AVL tại u chỉ bị phá vỡ khi v làm tăng chiều cao của cây con có chiều cao lớn hơn.

    Bốn trường hợp có thể phá vỡ tính cân bằng AVL tại u:
    1.Trước khi chèn cây con, gốc u lệch trái và v làm tăng chiều cao của cây con trái.
        + Sau khi chèn cây con trái lệch trái (Case LL).
        + Sau khi chèn cây con trái lệch phải (Case LR).
    2.Trước khi chèn cây con, gốc u lệch phải và v làm tăng chiều cao của cây con phải.
        + Sau khi chèn cây con phải lệch phải (Case RR).
        + Sau khi chèn cây con phải lệch trái (Case RL).
    => Cần tái cân bằng sau khi chèn.
*/

// AVL Tree
#include<bits/stdc++.h>
using namespace std;

// Định nghĩa kiểu dữ liệu các Node
struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
};

// Tính chiều cao của mỗi Node
int getHeight(Node* root){
    if(root == NULL) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

// Các kĩ thuật quay cây AVL
//Quay phải
Node* rightRotate(Node* root){
    Node* x = root->left;

    // Bắt đầu quay phải
    root->left = x->right;
    x->right = root;
    
    // Thiết lập chiều cao
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    // Trả về root mới
    return x;
}

//Quay trái
Node* leftRotate(Node* root){
    Node* y = root->right;

    // Bắt đầu quay trái
    root->right = y->left;
    y->left = root;
    
    // Thiết lập chiều cao
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    // Trả về root mới
    return y;
}

// Insertion AVL tree
Node* Insert(Node* root, int value){
    // Insert
    if(root == NULL){
        // Trả về Node có height = 1
        return new Node{value, NULL, NULL, 1};
    }
    if(value > root->data){
        root->right = Insert(root->right, value);
    }else{
        if(value < root->data){
            root->left = Insert(root->left, value);
        }else{
            return root;
        }
    }

    // Set height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Quay cây
    int valBalance = getHeight(root->left) - getHeight(root->right);

    // Kiểm tra 4 trường hợp
    // Left Left -> rightRotate
    if(valBalance > 1 && value < root->left->data){
        return rightRotate(root);
    }
    
    // Right Right -> leftRotate
    if(valBalance < -1 && value > root->right->data){
        return leftRotate(root);
    }

    // Left Right -> leftRotate -> rightRotate
    if(valBalance > 1 && value > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left -> rightRotate -> leftRotate
    if(valBalance < -1 && value < root->right->data){
        root->right = leftRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int COUNT = 10;
// In cây AVL
void print(Node* root, int space){
    if(root == NULL) return;
    space += COUNT;
    print(root->right, space);
    cout << "\n";

    for(int i = COUNT; i < space; i++){
        cout << " ";
    }

    cout << root->data << "(" << root->height << ")" << "\n";

    print(root->left, space);
}

void print2(Node* root){
    print(root, 0);
}

int main(){
    Node* tree = NULL;
    tree = Insert(tree, 18);
    tree = Insert(tree, 12);
    tree = Insert(tree, 30);
    tree = Insert(tree, 25);
    tree = Insert(tree, 69);
    tree = Insert(tree, 23);
    print2(tree);
}