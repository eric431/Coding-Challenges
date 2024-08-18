// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // Implement your solution here
    int rem = -1; // initiralise to -1 because binary conversion has not started
    int slow_ptr, fast_ptr;
    int binary_gap = 0, max_bp = 0, index = 0;
    bool start_bit = 0, zero_encountered = 0;

    while(N > 0 || rem > 0)
    {
        rem = N % 2;
        N = N / 2;
        if (!start_bit && rem == 1)
        {
            start_bit = 1;
            slow_ptr = index;
            fast_ptr = index;
        }
        else if (start_bit == 1 && rem == 1)
        {
            fast_ptr = index;
            if (!zero_encountered)
            {
                slow_ptr = index;
                binary_gap = fast_ptr - slow_ptr;
                zero_encountered = 0;
            }
            else if (zero_encountered)
            {
                binary_gap = fast_ptr - slow_ptr - 1;
                slow_ptr = fast_ptr;
            }

            if (binary_gap > max_bp)
            {
                max_bp = binary_gap;
            }
        }
        else if (start_bit == 1 && rem == 0)
        {
            zero_encountered = 1;
        }
        index++;
    }
    return max_bp;
}