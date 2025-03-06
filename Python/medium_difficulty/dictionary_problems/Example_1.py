
def question_1():
    keys = ['Ten', 'Twenty', 'Thirty']
    values = [10, 20, 30]

    map_ = {k: v for k, v in zip(keys, values)}
    print(map_)

def question_2():
    print("Question 2 loaded")

    dict1 = {'Ten': 10, 'Twenty': 20, 'Thirty': 30}
    dict2 = {'Thirty': 30, 'Fourty': 40, 'Fifty': 50}

    dict1.update(dict2)

    print(dict1)

def question_3():
    print("Question 3 loaded")

    sampleDict = {
        "class": {
            "student": {
                "name": "Mike",
                "marks": {
                    "physics": 70,
                    "history": 80
                }
            }
        }
    }

    print(sampleDict["class"]["student"]["marks"]["history"])


def question_4():
    employees = ['Kelly', 'Emma']
    defaults = {"designation": 'Developer', "salary": 8000}

    employee_map = {e: defaults for e in employees}
    print(employee_map)

    res = dict.fromkeys(employees, defaults)
    print(res)

def question_5():
    sample_dict = {
    "name": "Kelly",
    "age": 25,
    "salary": 8000,
    "city": "New york"}

    # Keys to extract
    keys = ["name", "salary"]

    res = {k: sample_dict[k] for k in keys}
    print(res)

def question_6():
    sample_dict = {
        "name": "Kelly",
        "age": 25,
        "salary": 8000,
        "city": "New york"
    }

    # Keys to remove
    keys = ["name", "salary"]

    res = {k: sample_dict[k] for k in sample_dict.keys() - keys}
    print(res)

def question_7():
    sample_dict = {'a': 100, 'b': 200, 'c': 300}

    if 200 in sample_dict.values():
        print(200, " present in a dict")
    else:
        print(200, " not present in a dict")

def question_8():
    '''
        Rename key of a dictionary
    '''

    sample_dict = {
    "name": "Kelly",
    "age":25,
    "salary": 8000,
    "city": "New york"
    } 

    sample_dict["location"] = sample_dict.pop("city")

    print(sample_dict)

def question_9():
    '''
        Get the key of a minimum value from dictionary
    '''

    sample_dict = {
    'Physics': 82,
    'Math': 65,
    'history': 75
    }

    print(min(sample_dict, key=sample_dict.get))

def question_10():
    sample_dict = {
        'emp1': {'name': 'Jhon', 'salary': 7500},
        'emp2': {'name': 'Emma', 'salary': 8000},
        'emp3': {'name': 'Brad', 'salary': 500}
    }

    sample_dict["emp3"]["salary"] = 8500

    print(sample_dict)

if __name__ == "__main__":
    print(">>>>>>>> Code loaded <<<<<<<<")

    # question_1()

    # question_2()

    # question_3()

    # question_4()

    # question_5()

    question_10()
