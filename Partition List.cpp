//Partition List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> prev;
        vector<int> suff;
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x)
            { prev.push_back(temp->val);
            }
            else
            { suff.push_back(temp->val);
            }
            temp = temp->next;
        }
        temp = head;
        for(int i = 0; i<prev.size(); i++){
          temp->val = prev[i];
          temp= temp->next;
        }
        for(int i = 0; i<suff.size(); i++){
          temp->val = suff[i];
          temp= temp->next;
        }
      return head;

    }
};
