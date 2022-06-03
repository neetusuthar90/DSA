list1 = [1,2,3,5,6,8,9]
list2 = [2,4,6,8]

def random(list1):
    total = 0
    for num1 in list1: #O(n)
        for num2 in list1: #O(n)
            print(num1,num2)
            total += 1
    
    return total

random(list1)   #O(n*n) => O(n)
