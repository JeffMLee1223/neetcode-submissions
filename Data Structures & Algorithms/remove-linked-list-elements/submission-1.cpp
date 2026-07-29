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
    ListNode* removeElements(ListNode* head, int val) {
        vector<int> arr;
        ListNode* curr = head;

        while (curr) {
            if (curr->val != val) {
                arr.push_back(curr->val);
            }
            curr = curr->next;
        }

        if (arr.empty()) {
            return nullptr;
        }

        ListNode* res = new ListNode(arr[0]); 
        // create another linkedlist that using the first element
        // of the array, [1 | null], we have to return res since the first pointer of the array element
        // represent the whole array
        curr = res;
        // we start to traverse the array

        for (int i = 1; i < arr.size(); i++) {
            ListNode* node = new ListNode(arr[i]); //we create node by using each element
            curr->next = node; // make sure the node is linked with each other.
            curr = curr->next; 
        }

        return res;
    }
};