#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  vector <int> vec[52];
  vector <int> ::iterator it;
  string str;
  int q,x;

  cin>>str;
  for (int i=0; i<str.size(); i++){
    if (str[i]>='a') x=str[i]-'a';
    else x=str[i]-'A'+26;
    vec[x].push_back(i);
  }
  for (int i=0; i<52; i++)
    sort(vec[i].begin(),vec[i].end());

  cin>>q;
  while (q--){
    cin>>str;
    int st=-1;
    bool check=1;
    for (int i=0; i<str.size() && check; i++){
      if (str[i]>='a') x=str[i]-'a';
      else x=str[i]-'A'+26;
      it=upper_bound(vec[x].begin(),vec[x].end(),st);
      if (it==vec[x].end()) check=0;
      else st=*it;
    }

    if (check){
      if (str[0]>='a') x=str[0]-'a';
      else x=str[0]-'A'+26;
      printf("Matched %d %d\n",*vec[x].begin(),st);
    }else printf("Not matched\n");
  }

  return 0;
}
