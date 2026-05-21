// Last updated: 5/20/2026, 11:37:28 PM

class MinStack {
  std::vector<int> m_stack{};

public:
  MinStack() {}

  void push(int val) { return m_stack.push_back(val); }

  void pop() { return m_stack.pop_back(); }

  int top() { return m_stack.back(); }

  int getMin() { return *std::min_element(m_stack.begin(), m_stack.end()); }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */