//自测-2 素数对猜想   (20分)
//让我们定义d_nd
//​n
//​​ 为：d_n = p_{n+1}-p_nd
//​n
//​​ =p
//​n+1
//​​ −p
//​n
//​​ ，其中p_ip
//​i
//​​ 是第ii个素数。显然有d_1 = 1d
//​1
//​​ =1，且对于n>1n>1有d_nd
//​n
//​​ 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

//现给定任意正整数N(<10^5<10
//​5
//​​ )，请计算不超过N的满足猜想的素数对的个数。

//输入格式:

//输入在一行给出正整数N。

//输出格式:

//在一行中输出不超过N的满足猜想的素数对的个数。

#include <iostream>
#include <vector>

using namespace std;

bool is_primer(size_t num);
size_t get_primer(size_t num);

int main()
{
    size_t n;
    while (cin >> n)
        cout << get_primer(n) << endl;
    return 0;
}

bool is_primer(size_t num)
{
    for (size_t i = 2; i * i <= num; ++i)
        if ( num % i == 0 ) return false;
    return true;
}

size_t get_primer(size_t num)
{
    size_t ret(0);
    size_t last(0);
    for (size_t n = 2; n <= num; ++n) {
        if (is_primer(n)){
            if (last && (n == last + 2))
                ++ret;
            last = n;
        }
    }
    return ret;
}
