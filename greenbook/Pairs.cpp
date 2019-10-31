//
// Created by abialbon on 31/10/2019.
//

#include <iostream>
#include <unordered_map>

int Pairs() {
    int arr[] = {-1, 0, 1, 2, -2, -4 };
    int length =  sizeof(arr)/sizeof(int);
    int n = 0;
    std::unordered_map<int, int> hmap;
    for (int i = 0; i < length; ++i) {
        auto c = hmap.find(n - arr[i]);
        auto v = hmap.find(arr[i]);
        if (c != hmap.end()) {      // If a complement is present
            if (c->second > 0) {    // and it's count is more than zero
                std::cout << arr[i] << " " << (n - arr[i]) << std::endl;
                c->second--;        // decrement it's count
            }
        } else {
            if (v != hmap.end()) v->second++;
            else hmap.insert({ arr[i], 1});
        }
    }
    return 0;
}
