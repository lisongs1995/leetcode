#inclue <list>

class LRUCache {
public:
    struct LRUNode {
        int value;
        int key;

        LRUNode(int k, int v) : key(k), value(v) {}
    };
    LRUCache(int capacity): cap(capacity) {}
    
    int get(int key) {
        if (!kv.count(key))
            return -1;
        move_front(key);
        return values.front().value;
    }

    void set(int key, int value) {
        if (!kv.count(key)) {
            values.emplace_front(key, value);
            kv[key] = values.begin();
            if (values.size() > cap) {
                kv.erase(values.back().key);
                values.pop_back();
            }
            else {
                kv[key]->value = value;
                move_front(key);
            }
        }
    }
private:
    int move_front(int key) {
        values.splice(values.begin(), values, kv[key]);
        kv[key] = values.begin();
    }
private:
    int cap;
    list<LRUNode> values;
    unordered_map<int, list<LRUNode>::iterator> kv;
};
