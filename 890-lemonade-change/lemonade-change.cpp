class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5bill=0;
        int count10bill=0;
        int count20bill=0;

        for(int i = 0;i<bills.size();i++){
            if(bills[i]==5){
                count5bill++;
            }
            else if(bills[i]==10){
                count10bill++;
                if(count5bill<0) return false;
                count5bill--;
            }
            else{
                count20bill++;
                if(count5bill>=1 && count10bill>=1){
                    count5bill--;
                    count10bill--;
                }
                else if(count5bill>=3){
                    count5bill-=3;
                }
                else return false;
            }

        }
        return true;
    }
};