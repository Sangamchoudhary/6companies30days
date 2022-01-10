
Language --> C++

Time --> O(Length of linked list)
Space --> O(1)

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N){
        Node* curr = head;
        
        while(curr){
            
            int k = M;
            
            while(curr and k > 1){
                curr = curr->next;
                k--;
                if(k == 1) break;
            }
            
            Node* one = curr;
            
            if(curr and curr->next) curr = curr->next;
            else break;
            
            int del = N;
            
            while(curr and del){
                curr = curr->next;
                del--;
            }
            
            one->next = curr;
            
        }
        
    }
};