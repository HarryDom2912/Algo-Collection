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

//Thuật toán Kosaraju - Kosaraju Algorithms

/*-----Ý nghĩa của thuật toán----
- Giúp tìm các thành phần liên thông mạnh trong đồ thị có hướng.
- Thành phần liên thông mạnh là một tập hợp các đỉnh đồ thị mà từ mỗi đỉnh trong tập hợp, ta có thể đi đến 
tất cả các đỉnh khác trong tập hợp bằng cách đi qua các cạnh có hướng.
- Trong một thành phần liên thông mạnh, không có cạnh nào nối các đỉnh từ thành phần liên thông mạnh này đến các đỉnh 
không thuộc thành phần liên thông mạnh này.
*/

/*-----Cách hoạt động của thuật toán-----
B1: Khởi tạo một đồ thị có hướng và một danh sách các đỉnh đã được duyệt.
B2: Duyệt toàn bộ các đỉnh của đồ thị, nếu đỉnh chưa được duyệt, thực hiện B3.
B3: Gọi hàm DFS(G,v) để duyệt đỉnh v. Trong quá trình duyệt, mỗi khi duyệt được một đỉnh, 
    đánh dấu đỉnh đó là đã duyệt và thêm vào danh sách các đỉnh đã được duyệt.
B4: Tạo đồ thị đảo G' của G bằng cách đảo các cạnh của G.
B5: Khởi tạo một danh sách các thành phần liên thông mạnh của đồ thị.
B6: Từ danh sách các đỉnh đã duyệt, duyệt toàn bộ các đỉnh theo thứ tự ngược lại. 
    Nếu đỉnh chưa được duyệt trong đồ thị đảo G', thực hiện B7.
B7: Gọi hàm DFS(G',v) để duyệt đỉnh v trong đồ thị đảo G'. Trong quá trình duyệt, mỗi khi duyệt được một đỉnh, 
    đánh dấu đỉnh đó là đã duyệt và thêm vào danh sách các thành phần liên thông mạnh.
B8: Trả về danh sách các thành phần liên thông mạnh.
*/

#include<bits/stdc++.h>

int n, m;
std::vector<int> adj[1001], r_adj[1001];
bool visited[1001];
std::stack<int> st;

// Nhập dữ liệu đầu vào
void inp(){
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
}

// DFS dùng cho B1
void dfs1(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if(!visited[v]) dfs1(v);
    }
    // Đã duyệt xong đỉnh u
    std::cout << u << " ";
    st.push(u); // Đẩy u vào trong stack
}

// DFS dùng cho B3
void dfs2(int u){
    visited[u] = true;
    std::cout << u << " ";
    for(int v : r_adj[u]){
        if(!visited[v]) dfs2(v);
    }
}

void scc(){
    memset(visited, false, sizeof(visited));
    // B1 : Gọi thuật toán DFS trên đồ thị ban đầu
    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs1(i);
    }
    std::cout << std::endl;
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    while(!st.empty()){
        // Trong khi stack chưa rỗng thì lấy đỉnh ở đầu stack ra
        int u = st.top();
        st.pop();
        if(!visited[u]){
            cnt++;
            dfs2(u);
            std::cout << std::endl;
        }
    }
    if(cnt == 1) std::cout << "YES " << std::endl;
    else std::cout << "NO " << std::endl;
}

int main(){
    inp();
    scc();
}