// leetcode 493
#include <iostream>
#include <vector>
using namespace std;

int c = 0;
int inversion(vector<int> &a, vector<int> &b)
{
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] > 2*b[i])
        {
            count += (a.size() - i);
            j++;
        }
        else
            i++;
    }
    return count;
}
void merge(vector<int> &a, vector<int> &b, vector<int> &res)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            res[k++] = a[i++]; // postfix operations
        }
        else
        {
            res[k++] = b[j++];
        }
    }
    if (i == a.size())
    {
        while (j < b.size())
        {
            res[k++] = b[j++];
        }
    }
    if (j == b.size())
    {
        while (i < a.size())
        {
            res[k++] = a[i++];
        }
    }
}

void mergesort(vector<int> &v)
{
    int n = v.size();
    if (n == 1)
        return;
    int n1 = n / 2, n2 = n - n / 2;
    vector<int> a(n1), b(n2);
    // copy pasting
    for (int i = 0; i < n1; i++)
    {
        a[i] = v[i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = v[i + n1];
    }

    // sorting by recursion
    mergesort(a);
    mergesort(b);
    // count inversion
    c += inversion(a, b);
    // merge
    merge(a, b, v);

    // to reduce sapce complexity
    a.clear();
    b.clear();
}

int main()
{
    int arr[] = {2,4,3,5,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    mergesort(v);
    cout << c;
}