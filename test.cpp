class Solution {
private:
    vector<set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<set<int>> graph(numCourses);
        for(auto p:prerequisites)
        {
            graph[p.second].insert(p.first);
        }
        return graph;
    }
    
    bool dfs_cycle(int i, vector<set<int>> &graph,vector<bool> &visited,vector<bool> &onpath)
    {
        if(visited[i])
            return false;
        onpath[i]=true;
        visited[i]=true;
        for(auto g:graph[i])
        {
            if(onpath[g] || dfs_cycle(g,graph,visited,onpath))
                return true;
        }
        return onpath[i]=false;
    }

public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<set<int>> graph=make_graph(numCourses,prerequisites);
        vector<bool> visited(numCourses,false);
        vector<bool> onpath(numCourses,false);
        
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i] && dfs_cycle(i,graph,visited,onpath))
                return false;
        }
        
        return true;
    }
};
