from unittest import result


def display_cube(list):
    result = []

    for value in list:
        # Additional memory need called space complexity...
        result.append(pow(value, 3))
        # O(n)

    print(result)


list = [2, 3, 4, 5, 6]
display_cube(list)
