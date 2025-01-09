class LRUCache {
public:
   map<int, int> m;
   map<int , list<int> :: iterator> add;
   list<int> l;
   int cap, siz;
    LRUCache(int capacity) {
        cap = capacity;
        siz =0;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        list<int>::iterator it = add[key];
        l.erase(it);
        add.erase(key);
        l.push_front(key);
        add[key] = l.begin();
        return m[key];
    }
    
    void put(int key, int value) {
        
        if(m.find(key) != m.end()){
            l.erase(add[key]);
            add.erase(key);
            m.erase(key);
            siz--;
        }
        if(siz == cap){
            int k = l.back();
            l.pop_back();
            add.erase(k);
            m.erase(k);
            siz--;
        }
        siz++;
        l.push_front(key);
        add[key] = l.begin();
        m[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */