 #include<bits/stdc++.h>
 
 #define int long long int
 #define F first
 #define S second
 #define pb push_back
 #define que_max priority_queue<int>
 #define que_min priority_queue<int,vector<int>,greater<int>>;
  #define endl "\n"
  using namespace std;


  struct node{
    node *nxt[26];
           
    node(){
      for(int i=0;i<26;i++)nxt[i]=NULL;
        
    }
  };

  node *root;


  void insert_trie(string s)
  {
    node *cur=root;
    for(int i=0;i<s.size();i++)
    {
       int imap=s[i]-'a';

       //new node
       if(cur->nxt[imap]==NULL)
       {
           cur->nxt[imap]=new node();
       }
       //go to that node
       cur = cur->nxt[imap];
    }
    
  }

  bool search_trie(string s)
  {
      node *cur=root;
      for(int i=0;i<s.size();i++)
      {
        int imap = s[i]-'a';

        //new node
        if(cur->nxt[imap]== NULL){
          return false;
        }

        cur= cur->nxt[imap];
      }

      return true; 
  }











  
  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif

      root = new node();
       
       string text="ababba";
       string pat="abba";
       int n=text.size();

       for(int i=0;i<n;i++)
       {
            insert_trie(text.substr(i));
            cout<<text.substr(i)<<endl;
       }

       if(search_trie(pat)){
        cout<<"Found";

       }else
       {
         cout<<"Not Found";
       }

     

   

 
 
      return 0;
  }
