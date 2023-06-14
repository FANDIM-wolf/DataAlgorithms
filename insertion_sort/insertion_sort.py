
# Online Python - IDE, Editor, Compiler, Interpreter
def insertion_sort(arr):
    indexing_length = range(1,len(arr))
    for i in indexing_length:
        print(i)
        value_to_sort = arr[i]
        while arr[i-1] > value_to_sort and i > 0:
            arr[i], arr[i-1] = arr[i-1], arr[i]
            print(i , arr[i-1])
            i = i - 1
            
    return arr        
arr = [1,2,0,4,3]

print(insertion_sort(arr))
