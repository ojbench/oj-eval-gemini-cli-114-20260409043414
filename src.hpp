#include<algorithm>

void Init(int **&p,int n){//初始化，n为vector的个数,传入的p指向nullptr
    p = new int*[n + 1];
    for(int i = 1; i <= n; ++i) {
        p[i] = nullptr;
    }
}
void Add_element(int **&p,int x,int y){//在第x(1base)个vector后面添加一个元素y
    if (p[x] == nullptr) {
        p[x] = new int[6];
        p[x][0] = 4; // capacity
        p[x][1] = 0; // size
    }
    if (p[x][1] == p[x][0]) {
        int cap = p[x][0];
        int *new_arr = new int[cap * 2 + 2];
        new_arr[0] = cap * 2;
        new_arr[1] = p[x][1];
        std::copy(p[x] + 2, p[x] + 2 + p[x][1], new_arr + 2);
        delete[] p[x];
        p[x] = new_arr;
    }
    p[x][2 + p[x][1]] = y;
    p[x][1]++;
}
int Get_element(int **&p,int x,int k){//获取第x(1base)个vector中第k个(1-base)元素的值
    return p[x][1 + k];
}
void Clear(int **&p,int n){//回收空间
    for(int i = 1; i <= n; ++i) {
        if (p[i] != nullptr) {
            delete[] p[i];
        }
    }
    delete[] p;
    p = nullptr;
}
