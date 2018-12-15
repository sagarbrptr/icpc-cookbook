ll block; //sqrt(N)
struct QUERY{
	ll L,R;
};
bool compare(QUERY a,QUERY b){
	if(a.L/block != b.L/block)
		return (a.L/block) < (b.L/block);
	return a.R<b.R;
}
void mo(vector<ll>a,vector<QUERY>q){
	block = sqrt(a.size());
	sort(q.begin(),q.end(),compare);
	ll curL=0,curR=0,curSum=0;
	for(int i=0;i<q.size();i++){
		ll L = q[i].L,R = q[i].R;
		while(curL<L){
			curSum-=a[curL];
			curL++;
		}
		while(curL>L){
			curSum+=a[curL];
			curL--;
		}
		while(curR<=R){
			curSum+=a[curR];
			curR++;
		}
		while(curR>(R+1)){
			curSum-=a[curR-1];
			curR--;
		}
		cout << curSum << "\n"; 
	}
}
