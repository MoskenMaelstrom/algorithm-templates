
char s[40],t[40];
signed main(){
	int n,m;
	cin>>n>>s>>m;//原来的进制n,数字s,要转成的进制m
    to_chars(t,t+40,strtol(s,NULL,n),m);//将数字s先转成n进制的ll,再将ll的s转化为m进制并存入t中
    for(int i=0;i<40;i++) if (t[i] >= 'a' and t[i] <='z') t[i]-=32;
    cout<<t;
    return 0;
}
