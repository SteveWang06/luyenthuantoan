#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <bitset>
#include <sstream>
#include <algorithm>

using namespace std;

struct Node {
    char ch;
    int freq;
    int order;
    Node *left, *right;

    Node(char ch, int freq, int order) : ch(ch), freq(freq), order(order), left(nullptr), right(nullptr) {}
    Node(Node* l, Node* r) {
        ch = '\0';
        freq = l->freq + r->freq;
        order = min(l->order, r->order);
        left = l;
        right = r;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq != b->freq) return a->freq > b->freq;
        return a->order > b->order;
    }
};

void buildCode(Node* node, string path, unordered_map<char, string>& codes) {
    if (!node->left && !node->right) {
        codes[node->ch] = path;
        return;
    }
    if (node->left) buildCode(node->left, path + "0", codes);
    if (node->right) buildCode(node->right, path + "1", codes);
}

string bitStringToHex(const string& bitStr) {
    stringstream ss;
    for (size_t i = 0; i < bitStr.size(); i += 4) {
        string chunk = bitStr.substr(i, 4);
        while (chunk.size() < 4) chunk += "0"; // 補 0
        int val = stoi(chunk, nullptr, 2);
        ss << hex << uppercase << val;
    }
    return ss.str();
}

int main() {
    string input;
    getline(cin, input);

    unordered_map<char, int> freq;
    unordered_map<char, int> firstPos;
    for (int i = 0; i < input.size(); ++i) {
        char c = input[i];
        freq[c]++;
        if (!firstPos.count(c)) firstPos[c] = i;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& [ch, f] : freq) {
        pq.push(new Node(ch, f, firstPos[ch]));
    }

    while (pq.size() > 1) {
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();
        pq.push(new Node(a, b));
    }

    Node* root = pq.top();
    unordered_map<char, string> huffmanCodes;
    buildCode(root, "", huffmanCodes);

    string bitStr;
    for (char c : input) {
        bitStr += huffmanCodes[c];
    }

    cout << bitStringToHex(bitStr) << endl;

    return 0;
}
