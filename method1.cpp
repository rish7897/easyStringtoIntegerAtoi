#include<iostream>
#include<string>
#include<climits>
using namespace std;

int myAtoi(string s) {
    int i = 0;
    while(s[i] == ' '){
        i++;
    }
    bool positive = true;
    if(s[i] == '+'){
        i++;
    }else if(s[i] == '-'){
        positive = false;
        i++;
    }
    int start = i;
    while(s[i] >= '0' && s[i] <= '9'){
        i++;
    }
    int end = i;
    int ans = 0;
    if(positive){
        for(int i = start; i < end; i++){
            if(ans < INT_MAX / 10 || (ans == INT_MAX / 10 && int(s[i] - '0') <= 7)){
                ans = ans * 10 + int(s[i] - '0');
            }else{
                return INT_MAX;
            }
        }
    }else{
        for(int i = start; i < end; i++){
            if(ans > INT_MIN / 10 || (ans == INT_MIN / 10 && int(s[i] - '0') <= 8)){
                ans = ans * 10 - int(s[i] - '0');
            }else{
                return INT_MIN;
            }
        }
    }
    return ans;
}