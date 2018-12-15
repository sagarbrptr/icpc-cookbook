vector<int> d(n+1, 1000000000);
for (int i = 0; i < n; i++) {
	*lower_bound(d.begin(), d.end(), a[i]) = a[i]; //a is input array of size n
}
for (int i = 0; i <= n; i++) {
	if (d[i] == 1000000000) {
		cout << i << endl;
		return 0;
	}
}

