#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <numeric>
#include <functional>
using namespace std;

// vector<int> merge(vector<int> &num1, vector<int> &num2);
// double find(vector<int> &nums1, vector<int> &nums2)
// {
//     int i = 0, j = 0;
//     vector<int> res;
//     res = merge(nums1, nums2);
//     int n = res.size();
//     if (n % 2)
//     {
//         return res[n / 2] * 1.0;
//     }
//     else
//     {
//         return (res[n / 2 - 1] + res[n / 2]) * 1.0 / 2;
//     }
// }

// vector<int> merge(vector<int> &num1, vector<int> &num2)
// {
//     int i = 0, j = 0;
//     vector<int> res;
//     while (true)
//     {
//         if (i == num1.size() && j == num2.size())
//             break;
//         if ((num1[i] > num2[j] && j != num2.size()) || i == num1.size())
//         {
//             res.push_back(num2[j++]);
//         }
//         else
//         {
//             res.push_back(num1[i++]);
//         }
//     }
//     return res;
// }



bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(),0);
        if (sum % 3 != 0 ) return false;
        int avg = sum / 3;
        int want = avg, sum1=0;
        for (int i=0; i<A.size(); i++) {
            sum1 += A[i];
            if (sum1 == want) want += avg;
        }
        return (want == avg*4);
}

int main()
{
    // vector<int> num2 = {1,3,2,4,2,4,5,2,2};
    vector<int> num1 = {0,2,1,-6,6,-7,9,-1,2,0,1};
    // double d = find(num1, num2);
    // std::cout << d << std::endl;
    cout << canThreePartsEqualSum(num1) << std::endl;
}