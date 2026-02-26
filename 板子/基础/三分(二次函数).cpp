
//查找区间最大值

int a,b,c;
int f(int x) {
	return a*x*x+b*x+c;
}


int ts(int L,int R){
    if (L > R) return 0;
    while (R-L > 3) {
        int mid1=L+(R-L)/3;
        int mid2=R-(R-L)/3;
        if (f(mid1) < f(mid2)) {
            L=mid1+1;
        }
        else {
            R=mid2-1;
        }
    }
    int ans = 0;
    for (int i=L;i<=R;i++){
        ans=max(ans,f(i));
    }
    return ans;
}