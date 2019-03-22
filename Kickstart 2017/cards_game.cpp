#include <bits/stdc++.h>
using namespace std;


struct min_val {
    bool operator() (pair <int, pair <int, int> > a, pair <int, pair <int, int> > b) {
        if (a.first > b.first) {
            return true;
        }
        return false;
    }
};

vector <int> parent;
vector <int> sizes;


int find_parent(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find_parent(parent[x]);
}

void unions(int u, int v) {
    int par_u = find_parent(u);
    int par_v = find_parent(v);
    if (par_u != par_v) {
        if (sizes[par_u] > sizes[par_v]) {
            parent[par_u] = par_v;
            sizes[par_v] += sizes[par_u];
        } else {
            parent[par_v] = par_u;
            sizes[par_u] = sizes[par_v];
        }
    }
}


int main() {
    int tc;
    cin >> tc;
    for (int t = 1 ; t <= tc ; t++) {
        int n;
        cin >> n;
        vector <int> red(n);
        for (int k = 0 ; k < n ; k++) {
            cin >> red[k];
        }
        vector <int> blue(n);
        for (int k = 0 ; k < n ; k++) {
            cin >> blue[k];
        }
        priority_queue <pair <int, pair <int, int> >, vector <pair <int, pair <int, int> > > , min_val> pq;
        for (int k = 0 ; k < n ; k++) {
            for (int j = 0 ; j < n ; j++) {
                if (k != j) {
                    pq.push(make_pair(red[k] ^ blue[j], make_pair(k, j)));
                }
            }
        }
        for (int k = 0 ; k < n ; k++) {
            for (int j = 0 ; j < n ; j++) {
                if (k != j) {
                    pq.push(make_pair(blue[k] ^ red[j], make_pair(k, j)));
                }
            }
        }
        long long int res = 0;
        parent.resize(n + 1);
        sizes.resize(n + 1);
        for (int k = 0 ; k < n ; k++) {
            parent[k] = k;
            sizes[k] = 1;
        }
        while (pq.size()) {
            pair <int, pair <int, int> > curr = pq.top();
            pq.pop();
            int w = curr.first, u = curr.second.first, v = curr.second.second;
            //cout << w << endl;
            if (find_parent(u) != find_parent(v)) {
                res += (long long int) w;
                unions(u, v);
            }
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}