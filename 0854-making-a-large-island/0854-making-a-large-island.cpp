class DS{
    public:
    vector<int> parent,size;
    DS(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)   parent[i] = i;
    }
    int findparent(int n){
        if(n==parent[n])    return n;
        return parent[n] = findparent(parent[n]);
    }
    void unionbysize(int u,int v){
        int pu = findparent(u);
        int pv = findparent(v);
        if(pu==pv)  return;
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
    bool isvalid(int r,int c,int n){
        return (r>=0 && c>=0 && r<n && c<n);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DS ds(n*n);
        int dr[] = {-1,0,1,0}, dc[] = {0,-1,0,1};
        //node = n*row + col
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0)   continue;
                int node = n*r + c;
                for(int i=0;i<4;i++){
                    int nr = r + dr[i], nc = c + dc[i];
                    int adjnode = n*nr + nc;
                    if(isvalid(nr,nc,n) && grid[nr][nc]){
                        ds.unionbysize(node,adjnode);
                    }
                }
            }
        }
        int ans = 0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c])  continue;
                set<int> comp;
                for(int i=0;i<4;i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    int adjnode = n*nr + nc;
                    if(isvalid(nr,nc,n) && grid[nr][nc]){
                        comp.insert(ds.findparent(adjnode));
                    }
                }
                int cnt = 1;
                for(int p:comp){
                    cnt += ds.size[p];
                }
                ans = max(cnt,ans);
            }
        }
        for(int i=0;i<n*n;i++){
            if(i==ds.findparent(i)){
                ans = max(ans,ds.size[i]);
            }
        }
        return ans;
    }
};