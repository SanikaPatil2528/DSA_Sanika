class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12) hour=0;

        double minDegree=(double)minutes*6;
        double hourShift=(double)minDegree/12;
        double hourDegree=hour*30 + hourShift;

        double angle1=abs(minDegree-hourDegree);
        double angle2=abs(360-angle1);

        return min(angle1,angle2);
    }
};