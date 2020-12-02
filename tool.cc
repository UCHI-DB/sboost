//
// Created by Hao Jiang on 11/30/20.
//
#include <iostream>
#include "loader.h"

using namespace std;

int main() {
    for (int i = 1; i < 32; ++i) {
        auto bitwidth = i;
        auto entryInBlocks = sboost::loader::entryInBlocks[i];
        auto resindex = 0;
        auto resoffset = 0;
        cout << "void write" << i << "(__m512i res,uint64_t* bitmap,uint64_t extract) {\n";
        cout << "uint64_t bits = 0;\n";
        for (int j = 0; j < 8; ++j) {
            auto eib = entryInBlocks[j];
            cout << "bits = _pext_u64(res[" << j << "],extract) & ((1L << " << eib << ")-1);\n";
            if (resoffset + eib < 64) {
                cout << "bitmap[" << resindex << "] |= bits << " << resoffset << ";\n";
                resoffset += eib;
            } else if (resoffset + eib == 64) {
                cout << "bitmap[" << resindex << "] |= bits << " << resoffset << ";\n";
                resindex += 1;
                resoffset = 0;
            } else {
                cout << "bitmap[" << resindex << "] |= bits << " << resoffset << ";\n";
                resoffset += eib;
                resindex += 1;
                resoffset &= 0x3F;
                cout << "bitmap[" << resindex << "] |= bits >> " << (eib - resoffset) << ";\n";
            }
        }
        cout << "}\n";
    }
}