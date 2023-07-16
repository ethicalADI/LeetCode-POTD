// Smallest Sufficient Team

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string, int> mp;
        int req_skill = 0;

        // convert req_skills vector of string into integer using bit masking
        for(int i = 0; i < req_skills.size(); i++){
            mp[req_skills[i]] = i;
            req_skill |= (1 << i);
        }

        // convert people skill into integer using bit masking
        vector<int> ppl(people.size());
        for(int i = 0; i < people.size(); i++){
            int p_skills = 0;
            for(int j = 0; j < people[i].size(); j++){
                p_skills |= (1 << mp[people[i][j]]);
            }
            ppl[i] = p_skills;
        }

        
        vector<vector<long long>> dp(ppl.size()+1, vector<long long>((1 << 16), INT_MAX));
        dp[0][0] = 0;


        for(int i = 1; i <= ppl.size(); i++){
            // if we dont consider the current person
            dp[i] = dp[i-1];

            // current person dont have any skills
            if(ppl[i-1] == 0) continue;

            // if we consider the current person
            for(int j = (1 << 16) - 1; j >= 0 ; j--){
                int cur_person_req_skills = (ppl[i-1]&j);
                int req_skills_cur_person_dnh = (j^cur_person_req_skills);

                dp[i][j] = min(dp[i][j], dp[i-1][req_skills_cur_person_dnh] + 1ll);
                
            }
        }

        // backtracking
        vector<int> ans;
        int skill = req_skill;
        for(int i = ppl.size(); i >= 1; i--){
            
            // if current person dont make a difference
            if(dp[i][skill] == dp[i-1][skill]) continue;

            // current person is required
            ans.push_back(i-1);
            int cur_person_req_skills = (ppl[i-1]&skill);
            skill = (skill^cur_person_req_skills);
        }

        return ans;
    }
};
