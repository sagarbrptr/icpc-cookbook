vector<ll>adj[400005],adjr[400005];
vector<ll>visited(400005,0),visitedr(400005,0);
vector<ll>order,component;
void dfs1(ll src){
	visited[src] = 1;
	for(auto e:adj[src])
		if(!visited[e])
			dfs1(e);
	order.pb(src);
}
void dfs2(ll src){
	visitedr[src] = 1;
	component.pb(src);
	for(auto e:adjr[src])
		if(!visitedr[e])
			dfs2(e);
}
for(int i=0;i<n;i++){
	cin >> a >> b;
	adj[a].push_back(b);
	adjr[b].push_back(a);
}
for(int i=0;i<n;++i)
	if(!visited[i])
		dfs1(i);
for(int i=0;i<n;++i){
	ll v = order[n-1-i]; 
	if(!visitedr[v]){
		dfs2 (v);component.clear();
	}
}
