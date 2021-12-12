// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Dec 2021
//  @Detail  :        Min Stack O(1) extra space
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;

struct MyStack {
 
    stack<int> s;
    int min;
 
void push(int x) {
 
      if(s.empty() ) {
         min=x;
         s.push(x);
      }
      else if(x<=min){
          s.push(2*x-min);
          min=x;
      }else{
      s.push(x);
      }
   }
 
int pop() {

    int t=s.top();s.pop();
    if(t<=min){
        int res=min;
        min=2*min-t;
        return res;
    }else{
        return t;
    }
   }

int top() {
    int t=s.top();
    return ((t<=min)? min : t);
   }
 
int getMin() {
      return min;
   }
};
