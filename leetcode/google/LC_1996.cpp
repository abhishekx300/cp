/*A good explanation
https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/discuss/1445186/EASY-C%2B%2B-solution-with-great-explanation-and-comments-(nlogn)-sorting
*/
bool comp(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] == v2[0]? v1[1]<v2[1]:v1[0]>v2[0];
}
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        // for(auto property:properties) {
        //     cout<<property[0]<<" "<<property[1]<<endl;
        // }
        int ans=0;
        int mx_defense_from_left = properties[0][1];
        for(int i=1; i < properties.size(); i++) {
            if(properties[i][1] < mx_defense_from_left)
            {ans++;}

            mx_defense_from_left = max(mx_defense_from_left, properties[i][1]);
        }
        return ans;
    }
};
