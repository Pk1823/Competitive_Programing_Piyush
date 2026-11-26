
// 3360. Stone Removal Game

#include <bits/stdc++.h>

class Solution {
public:
    bool canAliceWin(int n) {
        int need = 10;
        bool aliceTurn = true;

        while (n >= need) {
            n -= need;
            need--;
            aliceTurn = !aliceTurn;
        }

        return !aliceTurn;
    }
};
