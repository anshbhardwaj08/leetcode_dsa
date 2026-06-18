class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        if(hour==12){
            hour=0;
        }
        
        double deg1=(double((30.0/60)*minutes)+double(30*(hour)));
        double deg2=((360.0/60)*minutes);
        double ans=abs(deg1-deg2);
        return min(ans,360.0-ans);
    }
};