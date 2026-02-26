
const int N=1e5;
int tree[N][26];
int pass[N];
int ed[N];
int len=1;

void insert(const string& s) {
	int cur=0;
	pass[cur]++;
	for(char c : s) {
		if (tree[cur][c-'a'] == 0) tree[cur][c-'a']=len++;
		cur=tree[cur][c-'a'];
		pass[cur]++;
	}
	ed[cur]++;
}

int query(const string& s) {
	int cur=0;
	for(char c : s) {
		if (tree[cur][c-'a'] == 0) return 0;
		cur=tree[cur][c-'a'];
	}
	return ed[cur];
}

int querypre(const string& s) {
	int cur=0;
	for(char c : s) {
		if (tree[cur][c-'a'] == 0) return 0;
		cur=tree[cur][c-'a'];
	}
	return pass[cur];
}

void erase(const string& s) {
	if (query(s) == 0) return;
	int cur=0;
	pass[cur]--;
	for(char c : s) {
		if (--pass[tree[cur][c-'a']] == 0) {
			tree[cur][c-'a']=0;
			return;
		}
		cur=tree[cur][c-'a'];
	}
	ed[cur]--;
}
