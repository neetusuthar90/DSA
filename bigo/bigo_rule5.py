list = [3,4,5,6,2,7,9,8] #O(1)

def filo(list):
    total = 0 #O(1)
    for num in list:
        print(num)  #O(n)

    for num1 in list:
        for num2 in list:
            print(num1,num2) #O(n^2)
            total += 1 #O(n^2)
    msg = "Rule 5: Remove all non-dominants" #O(1)
    return total  #O(1)

filo(list) #O(4 + n +2n^2) = O(n^2)
