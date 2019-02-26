class Solution{
public:
    int divide(int dvd, int dvs){
        if(!dvs || (dvd==INT_MIN && dvs==-1))
            return INT_MAX;
        int sign = ((dvd<0)^(dvs<0))?-1:1;
        long long ldvd = labs(dvd);
        long long ldvs = labs(dvs);
        while(ldvd>=ldvs){
            long long tmp = ldvs, multi=1;
            while(ldvd>=(tmp<<1)) { // 10 - 3<<1 = 14
                tmp<<=1;
                multi<<=1;
            } 
            ldvd -= tmp;
            ans += multi;
        }
        return sign==1?ans:-ans;
    }
};
