# from collections import sorted_dict
import copy


def question_1():
    '''
        create nested dictionary using a given list
    '''

    a = {'Gfg': 4, 'is': 5, 'best': 9}
    b = [8, 3, 2] 

    res = {b_: {k: v} for b_, (k, v) in zip(b, a.items())}
    print(res)

def question_2():
    '''
        swap hierarchies in a given list
    '''

    input_dict = {'Gfg': { 'a' : [1, 3], 'b' : [3, 6], 'c' : [6, 7, 8]},
             'Best': { 'a' : [7, 9], 'b' : [5, 3, 2], 'd' : [0, 1, 0]}}
    
    new_dict = {key2: {key1: input_dict[key1][key2] for key1 in input_dict} for key2 in input_dict[next(iter(input_dict))] }

    print(new_dict)

def question_3():
    '''
        Sort dictionary
    '''

    people = {3: "Jim", 2: "Jack", 4: "Jane", 1: "Jill"}

    new_dict = {k: v for k,v in sorted(people.items(), key=lambda item: item[1])}
    print(new_dict)

    new_dict_1 = {k:v for k, v in sorted(people.items())}

    print(new_dict_1)

    new_dict_2 = {v:k for k, v in sorted(people.items())}
    print(new_dict_2)

def question_4():
    a = [[1, 2], [3, 4],[5, 6]]

    b = a.copy()

    c = copy.deepcopy(a)

    print(b)

    a[0][0] = 10

    print(b)

    print(c)

def question_5():
    a = ['a', 'b', 'c', 'd']
    b = [3, 1, 4, 2]

    x = [val for _, val in sorted(zip(b, a))]

    print(x)



if __name__ == "__main__":
    # question_1()

    question_5()

    with open("ex1.txt") as f:
        for line in f:
            content = line.split(" ")

    print(content)