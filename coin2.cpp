//
//  coin2.cpp
//  DynamicP
//
//  Created by 신예지 on 06/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> coin;
    int amount;
    for(int i=0; i<n; i++) {
        cin >> amount;
        coin.push_back(amount);
    }
    sort(coin.begin(), coin.end());
    
    int* memo = new int[k+1]();
    
    vector<int>::iterator it = coin.begin();
    for(int i=1; i<=k; i++) {
        if(find(it, coin.end(), i)!=coin.end()) {
            it = find(it, coin.end(), i);
            memo[i++] = 1;
        }
        int temp = k;
        for(int j=0; j<n; j++) {
            if(i-coin[j]>0) {
                if(memo[i-coin[j]]!=0) {
                    if(temp>memo[i-coin[j]]+1) temp = memo[i-coin[j]]+1;
                    memo[i] = temp;
                }
            }
            else break;
        }
    }
    if(memo[k]==0) cout<<-1;
    else cout << memo[k];
}
