//answer in F
void power(ll F[2][2],ll n){
	if(n<=1)
		return;
	ll M[2][2]={{(2*f)%MOD,-1},{1,0}};
	power(F,n/2);multi(F,F);
	if(n%2)
		multi(F,M);
}
void multi(ll F[2][2],ll M[2][2]){
	ll x=(F[0][0]%MOD*M[0][0]%MOD)%MOD+(F[0][1]%MOD*M[1][0]%MOD)%MOD;
	ll y=(F[0][0]%MOD*M[0][1]%MOD)%MOD+(F[0][1]%MOD*M[1][1]%MOD)%MOD;
	ll z=(F[1][0]%MOD*M[0][0]%MOD)%MOD+(F[1][1]%MOD*M[1][0]%MOD)%MOD;
	ll w=(F[1][0]%MOD*M[0][1]%MOD)%MOD+(F[1][1]%MOD*M[1][1]%MOD)%MOD;
	if(x<0)
		x=(x+MOD)%MOD;
	if(y<0)
		y=(y+MOD)%MOD;
	if(z<0)
		z=(z+MOD)%MOD;
	if(x<0)
		w=(w+MOD)%MOD;
	F[0][0]=x;F[0][1]=y;F[1][0]=z;F[1][1]=w;
}
