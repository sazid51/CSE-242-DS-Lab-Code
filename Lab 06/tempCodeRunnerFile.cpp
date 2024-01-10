 while(!ops.empty()){
        int val2 = values.top();
        values.pop();
                 
        int val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();
                 
        values.push(applyOp(val1, val2, op));
    }