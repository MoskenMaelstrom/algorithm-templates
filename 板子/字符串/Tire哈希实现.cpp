
const int N=1e5;
unordered_map<char,int> tree[N];
int pass[N];
int ed[N];
int len=1;

void insert(const string& s) {
	int cur=0;
	pass[cur]++;
	for(char c : s) {
		if (tree[cur].find(c) == tree[cur].end()) tree[cur][c]=len++;
		cur=tree[cur][c];
		pass[cur]++;
	}
	ed[cur]++;
}

int query(const string& s) {
	int cur=0;
	for(char c : s) {
		if (tree[cur].find(c) == tree[cur].end()) return 0;
		cur=tree[cur][c];
	}
	return ed[cur];
}

int querypre(const string& s) {
	int cur=0;
	for(char c : s) {
		if (tree[cur].find(c) == tree[cur].end()) return 0;
		cur=tree[cur][c];
	}
	return pass[cur];
}

void erase(const string& s) {
	if (query(s) == 0) return;
	int cur=0;
	pass[cur]--;
	for(char c : s) {
		if (--pass[tree[cur][c]] == 0) {
			tree[cur].erase(c);
			return;
		}
		cur=tree[cur][c];
	}
	ed[cur]--;
}
