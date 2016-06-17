# -PTA-
自测-1 打印沙漏   (20分)
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式:

输入在一行给出1个正整数N（\le≤1000）和一个符号，中间以空格分隔。

输出格式:

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例:

19 *
输出样例:

*****
 ***
  *
 ***
*****
2

作业：

#include <iostream>
#include <iomanip>
using namespace std;
void Print(int, char);
int main()
{
    int n;
    char c;
    while (cin >> n >> c)
        Print(n, c);
    return 0;
}
void Print(int n, char c)
{
    if (n > 1000) {
        cerr << "Exceed Limit\n";
        return;
    }
    int remain(n - 1);
    int t(3);
    int counter = 0;
    while ((remain - t * 2) >= 0) {
        remain -= t * 2;
        t += 2;
        ++counter;
    }
    t -= 2;
    if (counter) {
        int wid = 1, n = counter;
        for (; n > 0; --n) {
            int i = t;
            t -= 2;
            cout << setw(wid);
            for (; i > 0; --i)
                cout << c;
            cout << endl;
            ++wid;
        }
        cout << setw(wid) << c << endl;
        n = 0, t = 3;
        for (; n < counter; ++n) {
            --wid;
            cout << setw(wid);
            for (int i = 0; i < t; ++i)
                cout << c;
            cout << endl;
            t += 2;
        }
        cout << remain << endl;
    } else
        cout << c << endl << remain << endl;
}


自测-2 素数对猜想   (20分)
让我们定义d_nd
​n
​​ 为：d_n = p_{n+1}-p_nd
​n
​​ =p
​n+1
​​ −p
​n
​​ ，其中p_ip
​i
​​ 是第ii个素数。显然有d_1 = 1d
​1
​​ =1，且对于n>1n>1有d_nd
​n
​​ 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10^5<10
​5
​​ )，请计算不超过N的满足猜想的素数对的个数。

输入格式:

输入在一行给出正整数N。

输出格式:

在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:

20
输出样例:

4


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

自测-3 数组元素循环右移问题   (20分)
一个数组AA中存有NN（>0>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移MM（\ge 0≥0）个位置，即将AA中的数据由（A_0 A_1 \cdots A_{N-1}A
​0
​​ A
​1
​​ ⋯A
​N−1
​​ ）变换为（A_{N-M} \cdots A_{N-1} A_0 A_1 \cdots A_{N-M-1}A
​N−M
​​ ⋯A
​N−1
​​ A
​0
​​ A
​1
​​ ⋯A
​N−M−1
​​ ）（最后MM个数循环移至最前面的MM个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式:

每个输入包含一个测试用例，第1行输入NN（1\le N \le 1001≤N≤100）和MM（\ge 0≥0）；第2行输入NN个整数，之间用空格分隔。

输出格式:

在一行中输出循环右移MM位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例:

6 2
1 2 3 4 5 6
输出样例:

5 6 1 2 3 4


#include <iostream>
using namespace std;

int main()
{
    size_t n;
    size_t m;
    cin >> n >> m;
    int *aint = new int[n];
    int iput;
    for (size_t i = 0; i < n; ++i) {
        cin >> iput;
        aint[i] = iput;
    }
    for (; m > 0; --m) {
        size_t t = aint[n - 1];
        for (size_t i = 0; i < (n - 1); ++i)
            aint[n - i - 1] = aint[n - i - 2];
        aint[0] = t;
    }
    for (size_t i = 0; i < n - 1; ++i)
        cout << aint[i] << ' ';
    cout << aint[n - 1] << endl;
    return 0;
}

自测-4 Have Fun with Numbers   (20分)
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with kk digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:

Each input contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:

1234567899
Sample Output:

Yes
2469135798

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <string>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<int> get_arr(const vector<int>& vi);
bool check(vector<int> &, vector<int> &);

int main()
{
    char ch;
    vector<int> vi;
    while ((ch = getchar())!= '\n')
        vi.push_back(atoi(&ch));
    auto vres = get_arr(vi);
    if (check(vi, vres))
        cout << "Yes\n";
    else
        cout << "No\n";
    for (int i = vres.size() - 1; i >= 0; --i)
        cout << vres[i];
    cout << endl;

    return 0;
}
vector<int> get_arr(const vector<int>& vi)
{
    vector<int> vret;
    int jw(0);
    for (int i = vi.size() - 1; i >= 0; --i) {
        int t = vi[i] * 2;
        if (jw) { t += 1; --jw; }
        if (t >= 10) {
            ++jw;
            vret.push_back(t % 10);
        } else
            vret.push_back(t);
    }
    if (jw) vret.push_back(jw);
    return vret;
}
bool check(vector<int>& v1, vector<int>& v2)
{
    for(auto it = v2.begin(); it != v2.end(); ++it) {
        auto adr = find(v1.begin(), v1.end(), *it);
        if (adr != v1.end())
            v1.erase(adr);
    }
    if (v1.size() == 0) return true;
    else return false;
}

