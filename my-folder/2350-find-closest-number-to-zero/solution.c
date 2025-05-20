#include<stdlib.h>
int findClosestNumber(int* nums, int numsSize){
    int closest = nums[0];
    int minDistance = abs(nums[0]);
    for(int i=0; i<numsSize ;i++){
        int currentDistance=abs(nums[i]);
        if(currentDistance<minDistance ||
        (currentDistance==minDistance && nums[i]>closest)){
            minDistance = currentDistance;
            closest = nums[i];
        }
    }
    return closest;
}
