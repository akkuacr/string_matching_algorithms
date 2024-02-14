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
    bool is_end;       
    node(){
      for(int i=0;i<26;i++)nxt[i]=NULL;
        is_end=false;
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
       cur=cur->nxt[imap];
    }
    //curr ->last node
    cur->is_end=true;
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

      return cur->is_end; 
  }











  
  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif

      root = new node();
  

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      string s;
      cin>>s;
      insert_trie(s);
    }

    if(search_trie("apaa")){
      cout<<"Found";
    }else
    {
      cout<<"Not Found";
    }


 
 
      return 0;
  }
