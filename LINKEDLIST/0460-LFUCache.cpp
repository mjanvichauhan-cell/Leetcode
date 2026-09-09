class LFUCache {
    struct Node {
        int key;
        int value;
        int freq;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> nodes;
    unordered_map<int, list<int>> freqList;

    unordered_map<int, list<int>::iterator> position;

    void increaseFrequency(int key) {
        Node* node = nodes[key];
        int oldFreq = node->freq;
        freqList[oldFreq].erase(position[key]);
        if (freqList[oldFreq].empty()) {
            freqList.erase(oldFreq);
            if (minFreq == oldFreq)
                minFreq++;
        }
        node->freq++;
        freqList[node->freq].push_front(key);
        position[key] = freqList[node->freq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    int get(int key) {
        if (nodes.find(key) == nodes.end())
            return -1;
        increaseFrequency(key);
        return nodes[key]->value;
    }
    void put(int key, int value) {
        if (capacity == 0)
            return;
        if (nodes.find(key) != nodes.end()) {
            nodes[key]->value = value;
            increaseFrequency(key);
            return;
        }
        if (nodes.size() == capacity) {
            int removeKey = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty())
                freqList.erase(minFreq);
            position.erase(removeKey);
            delete nodes[removeKey];
            nodes.erase(removeKey);
        }
        Node* node = new Node(key, value);
        nodes[key] = node;
        minFreq = 1;
        freqList[1].push_front(key);
        position[key] = freqList[1].begin();
    }
};