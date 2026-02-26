int d,X,Y,PX,PY;//d为最大公因数; (X,Y)是一组特解
void exgcd(int a,int b)//a,b当前的两个过程数字,不用考虑入参大小
{
	if (b != 0) {
		exgcd(b,a%b);
		PX=X;//PX更新为下一次的x
		PY=Y;//PY更新为下一次的y
		X=PY;//求解的这次的x就是下次的y
		Y=PX-PY*(a/b);
	} else {
		d=a;
		X=1;
		Y=0;
	}
}

void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if (c%(gcd(a,b)) != 0) {cout<<-1<<endl;return;}
	exgcd(a,b);
	X*=c/d;
	Y*=c/d;
	//先算minx
	int t=ceil((1.0-X)/(b/d));
	int minx=X+t*b/d;
	int maxy=Y-t*a/d;
	//再算maxx;
	t=ceil((1.0-Y)/(a/d));
	int maxx=X-t*b/d;
	int miny=Y+t*a/d;
	int num=(maxx-minx)/(b/d)+1;
	if (minx>0 and maxy>0) cout<<num<<" "<<minx<<" "<<miny<<" "<<maxx<<" "<<maxy<<endl;
	else cout<<minx<<" "<<miny<<endl;
}