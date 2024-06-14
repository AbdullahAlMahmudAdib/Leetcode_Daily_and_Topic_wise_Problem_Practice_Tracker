class Solution
{
    public:
    #define ll int
    void merge(vector<ll> &a, ll low, ll mid, ll high)
    {
        vector<ll> temp;
        ll left = low;
        ll right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (a[left] <= a[right])
            {
                temp.push_back(a[left]);
                left++;
            }
            else
            {
                temp.push_back(a[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(a[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(a[right]);
            right++;
        }
        for (ll i = low; i <= high; ++i)
        {
            a[i] = temp[i - low];
        }
    }
    void mergesort(vector<ll> &a, ll low, ll high)
    {
        if (low >= high) return;
        ll mid = low + (high - low) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
    int minIncrementForUnique(vector<int> &a)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        mergesort(a, 0, a.size() - 1);
        ll ans = 0;
        for (ll i = 1; i < a.size(); ++i)
        {
            if (a[i] <= a[i - 1])
            {
                ans += a[i - 1] - a[i] + 1;
                a[i] = a[i - 1] + 1;
            }
        }
        return ans;
    }
};