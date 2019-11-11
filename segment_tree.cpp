#include <bits/stdc++.h> 
using namespace std; 

const int MAXN = 1e5+7;

/* Segment Tree Code */
int a[] = {7,8,5,3,1,6,9,2};
int tree[4*MAXN];

// use : build(0, n-1, 1);
void build(int s, int e, int nd) {
	if (s == e) {
		tree[nd] = a[s];
		return;
	}
	int md = (s+e)/2;
	build(s, md, 2*nd);
	build(md+1, e, 2*nd+1);
	tree[nd] = max(tree[2*nd], tree[2*nd+1]);
}

// use : query(0, n-1, 1, l, r);
int query(int s, int e, int nd, int l, int r) {
	if (s > r || e < l)	return INT_MIN;
	if (l <= s && e <= r)	return tree[nd];

	int mid = (s+e)/2;
	int left = query(s, mid, 2*nd, l, r);
	int right = query(mid+1, e, 2*nd+1, l, r);
	return max(left, right);
}

// use : update(0, n-1, 1, i, val);
void update(int s, int e, int nd, int idx, int val) {
	if (s == e) {
		a[s] =  val;
		tree[nd] = val;
		return;
	}

	int mid = (s+e)/2;
	if (idx <= mid)	update(s, mid, 2*nd, idx, val);
	else 			update(mid+1, e, 2*nd+1, idx, val);
	tree[nd] = max(tree[2*nd], tree[2*nd+1]);
}





/* Segment Code Ends */

// Driver Code 
int main() 
{ 
	string input="in.txt",output="output1.txt";
	ifstream file1;
	file1.open(input);
	ofstream file2;
	file2.open(output);
	string line;
	set<string> operation;
	int count=0,time=0;
	while(getline(file1,line))
	{
		stringstream sin(line);
		string prev,curr;
		while(sin>>curr)
		{
			if(curr=="COMPLETED")
				count++;
			if(prev=="STARTED")
				operation.insert(curr);
			if(prev=="in")
			{
				stringstream ss(curr);
				int val;
				ss>>val;
				time = max(time,val);
			}
			prev = curr;
		}
	}
	file2<<count<<endl;
	file2<<time<<endl;
	file2<<operation.size()<<endl;
	file2.close();
	file1.close();

} 
