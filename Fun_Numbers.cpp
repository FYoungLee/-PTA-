  //自测-4 Have Fun with Numbers   (20分)
//Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

//Now you are suppose to check if there are more numbers with this property. That is, double a given number with kk digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

//Input Specification:

//Each input contains one test case. Each case contains one positive integer with no more than 20 digits.

//Output Specification:

//For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

//Sample Input:

//1234567899
//Sample Output:

//Yes
//2469135798

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
