class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> recipeIdx, cookable;
        function<bool(string&)> dfs = [&](string& rec) -> bool{
            if(cookable.count(rec))
                return cookable[rec];
            if(recipeIdx.count(rec) == 0)
                return false;
            cookable[rec] = false;
            for(auto& it: ingredients[recipeIdx[rec]])
                if(!dfs(it))
                    return false;
            return cookable[rec] = true;
        };
        vector<string> ans;
        for(int i = 0; i < recipes.size(); i++)
            recipeIdx[recipes[i]] = i;
        for(auto ing: supplies)
            cookable[ing] = true;
        for(auto& recipe: recipes)
            if(dfs(recipe))
                ans.push_back(recipe);
        return ans;
    }
};