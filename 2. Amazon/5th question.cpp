    struct Trie{
        
        Trie *child[26] = {};
        
        vector<string> vect;
        
    }*root;

    void insertInTrie(string str)
    {
        int n = str.size();
        
        Trie *curr = root;
        
        for(int i = 0;i < n; i++)
        {
            char x = str[i];
            
            if(curr->child[x - 'a'])
            {
                curr = curr->child[x - 'a'];
                
                curr->vect.push_back(str);
            }
            
            else
            {
                Trie *node = new Trie;
                
                node->vect.push_back(str);
                
                curr->child[x - 'a'] = node;
                
                curr = node;
            }
        }
    }

    void constructTrie(string contact[], int n)
    {
        unordered_set<string> ms;
        
        for(int i = 0;i < n; i++)
        {
            if(!ms.count(contact[i]))
            {
                ms.insert(contact[i]);
                insertInTrie(contact[i]);
            }
        }
    }

    vector<vector<string>> solve(string str)
    {
        Trie *curr = root;
        
        vector<vector<string>> res;
        
        for(int i = 0; i < str.size(); i++)
        {
            char x = str[i];
            
            if(!curr->child[x - 'a'])
            {
                while(i < str.size())
                {
                    res.push_back({"0"});
                    ++i;
                }
            }
            
            else
            {
                curr = curr->child[x - 'a'];
                
                vector<string> v = curr->vect;
                
                sort(v.begin(), v.end());
                
                res.push_back(v);
            }
        }
        
        return res;
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        root = new Trie;
        
        constructTrie(contact, n);
        
        return solve(s);
    }