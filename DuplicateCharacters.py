'''Write a function that accepts a string and returns an integer value representing the number of distinct duplicated characters within the string, i.e. the number of characters that appear twice or more.

Your solution should be able to deal with all alphanumeric and special characters. Your solution should also also treat upper and lower case characters as distinct characters.

For example:

Given "Aasdefsgh!!!" the expected result would be '2' ('s' and '!' are duplicated)

[execution time limit] 4 seconds (py3)

[memory limit] 1 GB

[input] string input

The string to evaluate

[output] integer

The number of duplicated characters'''

def solution(input):
    hashMap = {}
    checkArr = []
    count = 0
    
    for i in input:
        if i in hashMap and i not in checkArr:
            count += 1
            checkArr.append(i)
        else:
            hashMap[i] = 1
    
    return count