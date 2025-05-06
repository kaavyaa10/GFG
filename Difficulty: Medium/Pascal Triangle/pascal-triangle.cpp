//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        if(n==1) return {1};
        
        vector<vector<int>>triangle;
        triangle.push_back({1});
        for(int i=1;i<n-1;i++){
            vector<int>curr;
            for(int j=0;j<=i;j++){
                if(j==0 || j ==i){
                    curr.push_back(1);
                }
                else{
                    curr.push_back(triangle[i-1][j-1]+triangle[i-1][j]);
                }
            }
            triangle.push_back(curr);
        }
        vector<int>curr;
        for(int i=0;i<n;i++){
            if(i==0 || i ==n-1){
                curr.push_back(1);
            }else
            curr.push_back(triangle[n-2][i-1]+triangle[n-2][i]);
        }
        return curr;
    }
};


//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends