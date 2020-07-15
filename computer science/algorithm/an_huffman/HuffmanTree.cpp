//
// Created by t1542 on 2020/5/14.
//

#include "HuffmanTree.h"


void HuffmanTree::calc(const string &value, p_greater& _data_out,  map<char,int> & _raw_out){
    // map<char
    map<char, int> cal;
    for(char item: value){
        auto iter = cal.find(item);
        if(iter == cal.end()){
            cal[item] = 1;
        } else {
            cal[item] = cal[item]+1;
        }
    }

    p_greater pg;
    for(auto item: cal){
        auto* node = new bnode<char>(item.first);
        pg.push(calculable(node, item.second));
    }

    _raw_out = cal;
    _data_out = pg;
}

HuffmanTree HuffmanTree::build(const string &value) {
    HuffmanTree tree;
    HuffmanTree::calc(value, tree._data, tree._raw);
    tree.str = value;
    tree.combine();

    tree.encoding_iter(tree._data.top().value);
    return tree;
}

bool HuffmanTree::continue_combine() const {
    return _data.size() >= 2;
}

void HuffmanTree::combine() {
    while(continue_combine()){
        auto first = _data.top();
        _data.pop();
        auto second = _data.top();
        _data.pop();

        calculable new_calc = calculable::combine(first, second);
        _data.push(new_calc);
    }
}

void HuffmanTree::print() {
    cout << "encoding:" << endl;
    for(auto item: _raw){
        cout << setw(5) << item.first << setw(5) << item.second << setw(12) << encoding.find(item.first)->second << endl;
    }

    cout << "raw_string:" << str << endl;
    string encoded;
    for(char item: str){
        encoded += encoding.find(item)->second;
    }
    cout << "encoded_string:" << encoded << endl;
    cout << "length:" << encoded.size() << endl;
}

void HuffmanTree::encoding_iter(bnode<char> *node, const string& prefix) {
    if(!node->has_children()) {
        encoding[node->value] = prefix;
    } else {
        encoding_iter(node->left, prefix + "0" );
        encoding_iter(node->right, prefix + "1");
    }
}
