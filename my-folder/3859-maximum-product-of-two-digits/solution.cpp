class Solution {
public:
    int maxProduct(int n) {
        int maxdigit =0;
        int secmaxdigit=0;

        while(n>0){
            int r =n%10;
            if(maxdigit < r){
                secmaxdigit = maxdigit;
                maxdigit = r;
            }else if(secmaxdigit < r){
                secmaxdigit = r;
            }
            n/=10;
        }
        return maxdigit * secmaxdigit ;
    }
};
