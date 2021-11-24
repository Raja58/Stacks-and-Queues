// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        24 Nov 2021
//  @Detail  :        Online Stock Span (LeetCode)
//  ============================
//  -->

class StockSpanner {
public:
    
    stack<int> stock;
    vector<int> input;
    
    StockSpanner() {
        stock.push(-1);
    }
    
    int next(int price) {
        while(stock.top() != -1 && input[stock.top()] <= price)
            stock.pop();
        int result = input.size() - stock.top();
        input.push_back(price);
        stock.push(input.size() - 1);
        return result;
    }
};
