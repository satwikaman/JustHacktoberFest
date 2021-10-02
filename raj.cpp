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



// question link : https://leetcode.com/problems/split-linked-list-in-parts/submissions/
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>v;
        ListNode* ptr = head; int n =0;
        while(ptr!=NULL){
            n++;
            ptr=ptr->next;
        }
        cout<<n<<endl;
        if(n==k){
            while(head){
                ptr=head;
                ptr = ptr->next;
                head->next = NULL;
                v.push_back(head);
                head = ptr;    
            }
            
        }
        else if(n<=k){
            int s= n ;
            while(s--){
                ptr = head;
                ptr = ptr->next;
                head->next = NULL;
                v.push_back(head);
                head = ptr;
            }
            int z = k-n;
            while(z--){
                ListNode* tmp = NULL;
                v.push_back(tmp);
            }
        }
        else{
           
            ListNode* ptr1 = head;
            int c = n/k;
            int r = n%k;
            for(int i=0;i<r;i++){
                int size = c;
                while(size--){
                    ptr1 = ptr1->next;
                }
                ptr = ptr1->next;
                ptr1->next=NULL;
                v.push_back(head);
                head = ptr;
                ptr1=head;
            }
            int y = (k-r);
            while(y--){
                int size = c-1;
                while(size--){
                    ptr1 = ptr1->next;
                }
                ptr = ptr1->next;
                ptr1->next=NULL;
                v.push_back(head);
                head = ptr;
                ptr1=head;    
            }
            
            
            
        }
        return v; 
        
        
    }
};