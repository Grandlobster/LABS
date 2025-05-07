#include<iostream>
#include<string>
#include<climits>
#include<vector>
using namespace std;

void OptimalBST(vector<int>& keys, vector<float>& probs){
    int n = keys.size();
    vector<vector<float>> conj(n, vector<float>(n, 0));
    vector<vector<int>> root(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        conj[i][i] = probs[i];
        root[i][i] = i;
    }

    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            conj[i][j] = INT_MAX;
            for(int r = i; r <= j; r++){
                float c = ((r > i) ? conj[i][r-1] : 0) +
                          ((r < j) ? conj[r+1][j] : 0) +
                          probs[r];
                if(c < conj[i][j]){
                    conj[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }
    cout << "Optimal cost is: " << conj[0][n-1] << endl;
}

int main(){
    vector<int> keys = {10, 12, 13};
    vector<float> probs = {0.89, 0.52, 0.02};
    OptimalBST(keys, probs);
    return 0;
}
