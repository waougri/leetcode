// Last updated: 5/20/2026, 11:36:45 PM
class RandomizedSet {

private:
    std::deque<int> m_deque{};

    bool in_deque(const int val) {
        return std::find(m_deque.begin(), m_deque.end(), val) != m_deque.end();
    }

public:
    RandomizedSet() = default;

    bool insert(int val) {
        if (in_deque(val)) { return false; }
        m_deque.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!in_deque(val)) return false;
        m_deque.erase(std::find(m_deque.begin(), m_deque.end(), val));
        return true;
    }

    int getRandom() {
        static std::random_device rd;
    static std::mt19937 mt(rd());
    
    // Use uniform_int_distribution to generate a random index
    std::uniform_int_distribution<int> dist(0, static_cast<int>(m_deque.size()) - 1);
    return m_deque[dist(mt)];
    }

};