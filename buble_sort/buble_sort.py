
# Buble sort 
def buble_sort(arr):
    indexing_length = len(arr)-1
    sorted = False
    while not sorted:
        sorted = True
        for i in range(0, indexing_length):
            if(arr[i] > arr[i+1]):
                sorted = False
                arr[i],arr[i+1] = arr[i+1],arr[i]
    return arr 

            
       
arr = [1,2,0,4,3]

print(buble_sort(arr))
