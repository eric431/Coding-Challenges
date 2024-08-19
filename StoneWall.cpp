// you can use includes, for example:
// #include <algorithm>
#include <stack>
#include <set> 
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void identify_foundational_blocks(stack<int>& blocks, int block, int& num_blocks)
{
    if(!blocks.empty())
    {
        int last_block = blocks.top();
        if(block < last_block)
        {
            blocks.pop();
            identify_foundational_blocks(blocks, block, num_blocks);
        }
        else if (block > last_block)
        {
            num_blocks++;
            blocks.push(block);
        }
        return;
    }
    num_blocks++;
    blocks.push(block);
    return;
}

int solution(vector<int> &H) {
    // Implement your solution here
    int num_blocks = 0;
    stack<int> blocks;
    for(auto& block : H)
    {
        identify_foundational_blocks(blocks, block, num_blocks);
    }
    return num_blocks;
}