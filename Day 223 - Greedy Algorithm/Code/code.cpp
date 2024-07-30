#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <limits.h>
using namespace std;

// Q1. Minimum number of Coins.
vector<int> minPartition(int N)
{
    // code here
    int currency[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int notes = 0, i = 0;
    vector<int> ans;
    while (N)
    {
        notes = N / currency[i];
        while (notes--)
        {
            ans.push_back(currency[i]);
        }
        N %= currency[i];
        i++;
    }
    return ans;
}

// Q2. Shop in Candy Store.
vector<int> candyStore(int candies[], int N, int k)
{
    // Write Your Code here
    sort(candies, candies + N);
    int min_amount = 0, max_amount = 0;
    int i = 0, j = N - 1;

    while (i <= j)
    {
        min_amount += candies[i];
        i++;
        j -= k;
    }
    i = N - 1, j = 0;

    while (i >= j)
    {
        max_amount += candies[i];
        i--;
        j += k;
    }

    return {min_amount, max_amount};
}

// Q3. Assign Mice Holes.
int assignMiceHoles(int N, int M[], int H[])
{
    // code here
    sort(M, M + N);
    sort(H, H + N);

    int ans = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        ans = max(ans, abs(M[i] - H[i]));
    }

    return ans;
}

// Q4. Minimum rotations to unlock a circular lock.
int rotationCount(long long R, long long D)
{
    // code here
    int ans = 0;
    int first, second;

    while (R)
    {
        first = R % 10;
        second = D % 10;

        R /= 10;
        D /= 10;

        ans += min(abs(first - second), 10 - abs(first - second));
    }

    return ans;
}

// Q5. N meetings in one room.
bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int, int>> timer;
    for (int i = 0; i < n; i++)
    {
        timer.push_back({start[i], end[i]});
    }

    sort(timer.begin(), timer.end(), comp);

    int total = 0;
    int ending = -1;

    for (int i = 0; i < n; i++)
    {
        if (timer[i].first > ending)
        {
            total++;
            ending = timer[i].second;
        };
    }
    return total;
}

// Q6. Job Sequencing Problem.
// Method 1:
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool comp(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    sort(arr, arr + n, comp);
    int deadline = 0;

    for (int i = 0; i < n; i++)
    {
        deadline = max(deadline, arr[i].dead);
    }

    vector<bool> task(deadline + 1, 0);
    vector<int> ans(2, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (!task[j])
            {
                task[j] = 1;
                ans[0]++;
                ans[1] += arr[i].profit;
                break;
            }
        }
    }

    return ans;
}

// Method 2:
int find(int num, vector<int> &parent)
{
    if (num == parent[num])
        return num;

    return parent[num] = find(parent[num], parent);
}

vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    sort(arr, arr + n, comp);
    int deadline = 0;

    for (int i = 0; i < n; i++)
    {
        deadline = max(deadline, arr[i].dead);
    }

    vector<int> parent(deadline + 1);

    for (int i = 0; i <= deadline; i++)
    {
        parent[i] = i;
    }

    vector<int> ans(2, 0);
    for (int i = 0; i < n; i++)
    {
        int slot = find(arr[i].dead, parent);
        if (slot > 0)
        {
            ans[0]++;
            ans[1] += arr[i].profit;
            parent[slot] = slot - 1;
        }
    }

    return ans;
}

// Q7. Single-Threaded CPU.
vector<int> getOrder(vector<vector<int>> &tasks)
{
    vector<int> ans;
    int n = tasks.size();
    for (int i = 0; i < n; i++)
    {
        tasks[i].push_back(i);
    }

    sort(tasks.begin(), tasks.end());

    long long timer = tasks[0][0];
    int i = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
        pq;

    while (!pq.empty() || i < n)
    {
        while (i < n && timer >= tasks[i][0])
        {
            pq.push({tasks[i][1], tasks[i][2]});
            i++;
        }

        if (pq.empty())
        {
            timer = tasks[i][0];
        }
        else
        {
            ans.push_back(pq.top().second);
            timer += pq.top().first;
            pq.pop();
        }
    }
    return ans;
}

// Q8. Fractional Knapsack.
struct Item
{
    int value;
    int weight;
};
bool comp(Item a, Item b)
{
    // return a.value / a.weight > b.value / b.weight;
    return a.value * b.weight > b.value * a.weight;
}
double fractionalKnapsack(int w, Item arr[], int n)
{
    // Your code here
    sort(arr, arr + n, comp);
    double profit = 0;
    int i = 0;

    while (w && i < n)
    {
        if (w >= arr[i].weight)
        {
            profit += arr[i].value;
            w -= arr[i].weight;
        }
        else
        {
            double temp = arr[i].value;
            temp /= arr[i].weight;
            profit += w * temp;

            w = 0;
        }
        i++;
    }

    return profit;
}

// Q9. Non-overlapping Intervals.
bool comp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), comp);
    int end = INT_MIN;
    int remove = 0;

    for (int i = 0; i < intervals.size(); i++)
    {
        if (end <= intervals[i][0])
        {
            end = intervals[i][1];
        }
        else
            remove++;
    }
    return remove;
}

// Q10. Insert Interval.
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    int i = 0, n = intervals.size();

    while (i < n && newInterval[0] > intervals[i][1])
    {
        ans.push_back(intervals[i]);
        i++;
    }

    if (i == n)
    {
        ans.push_back(newInterval);
        return ans;
    }

    while (i < n && newInterval[1] >= intervals[i][0])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);
    while (i < n)
    {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

// Q11. Task Scheduler.
int leastInterval(vector<char> &tasks, int n)
{
    // Calculate the freq of each Char
    vector<int> freq(26, 0);
    int count = 0;

    for (int i = 0; i < tasks.size(); i++)
    {
        freq[tasks[i] - 'A']++;
        count = max(count, freq[tasks[i] - 'A']);
    }

    int ans = (count - 1) * (n + 1);
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == count)
        {
            ans++;
        }
    }

    return ans > tasks.size() ? ans : tasks.size();
}

// Q12.
class Node
{
public:
    int freq;
    char c;
    Node *left;
    Node *right;

    Node(int frequency, char name)
    {
        freq = frequency;
        c = name;
        left = right = NULL;
    }
};

class comp1
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void preorder(Node *root, string &temp, vector<string> &ans)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        ans.push_back(temp);
    }

    temp.push_back('0');
    preorder(root->left, temp, ans);
    temp.pop_back();
    temp.push_back('1');
    preorder(root->right, temp, ans);
    temp.pop_back();
}

vector<string> huffmanCodes(string S, vector<int> f, int N)
{
    // Code here

    // Build the huffman tree
    // Build the min heap
    priority_queue<Node *, vector<Node *>, comp1> pq;
    for (int i = 0; i < N; i++)
    {
        pq.push(new Node(f[i], S[i]));
    }

    while (pq.size() > 1)
    {
        Node *first = pq.top();
        pq.pop();
        Node *second = pq.top();
        pq.pop();

        Node *root = new Node(first->freq + second->freq, '$');
        root->left = first;
        root->right = second;
        pq.push(root);
    }

    Node *root = pq.top();
    pq.pop();

    // preorder
    vector<string> ans;
    string temp;
    preorder(root, temp, ans);
    return ans;
}

int main() {}