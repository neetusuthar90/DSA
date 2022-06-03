students = ['jane','kiki','andrew','alex','harry','dustin','steve','nancy','max'] #O(1)

def rean(students):
    first = students[0]  #O(1)
    total = 0   #O(1)
    new_list = []  #O(1)

    for student in students:
        total += 1  #O(n)
        new_list.append(student)  #O(n)
     
    print(new_list) #O(1)
    return total  #O(1)

print(rean(students)) #O(6+2n) => O(n)

