#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

vector<pair<int,int>> maxmininkgroup(vector<int>& arr, int k) {
    deque<int> maxi;
    deque<int> mini;
    vector<pair<int,int>> ans;
    for(int i=0; i<k; i++) {
        while(!maxi.empty() && arr[maxi.back()] < arr[i]) {
            maxi.pop_back();
        }
        maxi.push_back(i);

        while(!mini.empty() && arr[mini.back()] > arr[i]) {
            mini.pop_back();
        }
        mini.push_back(i);
    }
    ans.push_back({maxi.front(), mini.front()});

    for(int s=1, e=k; e < arr.size(); e++, s++) {
        // Removing previous group
        if(maxi.front() < s)
            maxi.pop_front();
        if(mini.front() < s)
            mini.pop_front();
        // Adding new group
        while(!maxi.empty() && arr[maxi.back()] < arr[e]) {
            maxi.pop_back();
        }
        maxi.push_back(e);

        while(!mini.empty() && arr[mini.back()] > arr[e]) {
            mini.pop_back();
        }
        mini.push_back(e);

        ans.push_back({maxi.front(), mini.front()});
    }
    return ans;
}

int main()
{
    vector<int> arr {7,3,6,2,1,5,9,8};
    vector<pair<int,int>> p;
    p = maxmininkgroup(arr, 3);
    for(int i=0;i<p.size();i++) {
        cout << "{ " << arr[p[i].first] << ", " << arr[p[i].second] << " }\t";
    }
    return 0;
}
