'''Write a function that accepts a string and returns the second highest numerical digit in the input as an integer.

The following rules should apply:

Inputs with no numerical digits should return -1
Inputs with only one numerical digit should return -1
Non-numeric characters should be ignored
Each numerical input should be treated individually, meaning in the event of a joint highest digit then the second highest digit will also be the highest digit
For example:

"abc:1231234" returns 3
"123123" returns 3
[execution time limit] 4 seconds (py3)

[memory limit] 1 GB

[input] string input

The input string

[output] integer

The second-highest digit'''


def solution(input):
    m1 = None
    m2 = None
    num = []
    hashMap = {}
    if (len(input) < 2):
        return -1
        
    for i in input:
        if i.isnumeric():
            num.append(int(i))
            
    
    if len(num) < 2:
        return -1
    else:
        for r in num:
            if m1 == None:
                m1 = r
            elif r <= m1 and m2 == None:
                m2 = r
            elif r > m1:
                temp = m1
                m1 = r
                m2 = temp
            elif r > m2:
                m2 = r
    return m2