Language --> C++

Time Complexity --> O(N)
Space Complexity --> O(1) , as we are using only vairables not extra spaces

string encode(string str){     
  string ans;
  int n = str.length();
  int count = 1;
  char prev = str[0];
  if(n == 1){
    ans += prev + to_string(count);
    return ans;
  } 
  for(int i=1;i<n;i++){
      if(str[i] == prev){
          count++;
      }else{
          ans += prev + to_string(count);
          prev = str[i];
          count = 1;
      }
      if(i == n-1) ans += prev + to_string(count);
  }
  return ans;
} 