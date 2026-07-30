class Solution {
public:
    int minimumPushes(string word) {
        int wordLength = word.size();

        int totalPushes =0;
        int pushesPerChar =1;

        int completeGroups = wordLength / 8;
        for (int groupIndex = 0; groupIndex < completeGroups; ++groupIndex){
            totalPushes += pushesPerChar * 8;
            ++pushesPerChar;
        }
        int remainingChars = wordLength % 8;
        totalPushes += pushesPerChar * remainingChars;

        return totalPushes;
    }
};
