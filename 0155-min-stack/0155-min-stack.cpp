class MinStack {
public:

    // Normal stack: stores all the actual values
    stack<int> st;

    // Minimum stack: stores the minimum value
    // at every level of the stack
    stack<int> minSt;

    // Constructor
    MinStack() {
    }
    
    // Add a value to the stack
    void push(int value) {

        // Push the value into the normal stack
        st.push(value);

        // If minSt is empty, this value is
        // automatically the minimum
        if (minSt.empty()) {
            minSt.push(value);
        }

        // Otherwise, compare the new value
        // with the current minimum
        else {
            minSt.push(min(value, minSt.top()));
        }
    }
    
    // Remove the top value from the stack
    void pop() {

        // Check that the stack is not empty
        if (st.size() != 0) {

            // Remove the top value from normal stack
            st.pop();

            // Remove the corresponding minimum
            // from minimum stack
            minSt.pop();
        }
    }
    
    // Return the top value of the normal stack
    int top() {
        return st.top();
    }
    
    // Return the current minimum value
    // in O(1) time
    int getMin() {
        return minSt.top();
    }
};