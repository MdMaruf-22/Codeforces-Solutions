#include <bits/stdc++.h>
using namespace std;

struct Item {
    string name; // Added name of the item
    float weight;
    int value;
};

struct Node {
    int level, profit, bound;
    float weight;
};

// Compare items based on value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate upper bound
int bound(Node u, int n, int W, Item arr[]) {
    if (u.weight >= W)
        return 0;

    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;

    while ((j < n) && (totweight + arr[j].weight <= W)) {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    if (j < n)
        profit_bound += (W - totweight) * arr[j].value / arr[j].weight;

    return profit_bound;
}

// Knapsack function using Branch and Bound
int knapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp);

    queue<Node> Q;
    Node u, v;

    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);

    int maxProfit = 0;

    // Print the header
    cout << "Decision   | Item       | Level | Weight | Profit | Bound\n";
    cout << "--------------------------------------------------------\n";

    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        if (u.level == n - 1)
            continue;

        // Node for including the next item
        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        // Print node details for including the item
        cout << "Including  | " << setw(10) << arr[v.level].name << " | "
             << setw(5) << v.level << " | "
             << setw(6) << v.weight << " | "
             << setw(6) << v.profit << " | "
             << setw(6) << bound(v, n, W, arr) << '\n';

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);

        // Node for excluding the next item
        v.weight = u.weight;
        v.profit = u.profit;

        // Print node details for excluding the item
        cout << "Excluding  | " << setw(10) << arr[v.level].name << " | "
             << setw(5) << v.level << " | "
             << setw(6) << v.weight << " | "
             << setw(6) << v.profit << " | "
             << setw(6) << bound(v, n, W, arr) << '\n';

        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}

int main() {
    int W = 9; // Weight of knapsack
    Item arr[] = {
        {"Item1", 8, 24}, 
        {"Item2", 1, 2}, 
        {"Item3", 5, 20}, 
        {"Item4", 4, 4}
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum possible profit = " << knapsack(W, arr, n) << endl;

    return 0;
}
