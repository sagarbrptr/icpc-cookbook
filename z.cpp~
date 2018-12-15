vector<ll>z;
void zfunc(string s){              // calculates z value at index i such that maximum prefix length for string p starting from index i
  ll sz = s.size();
  z.pb(-1);
  ll l=0,r=0;
  for(int i=1;i<sz;i++){
    if(i>r){
      l=i;r=i;
      while(r<sz && s[r-l]==s[r])
        r++;
      z.pb(r-l);r--;
    }
    else{
      ll k = i-l;
      if(z[k]<r-i+1)
        z.pb(z[k]);
      else
      {
        l=i;
        while(r<sz && s[r-l]==s[r])
          r++;
        z.pb(r-l);r--;
      }
    }
  }
}

