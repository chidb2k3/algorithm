def find_min_max(arr):
   if not arr:
        return None, None
    
   min = max = arr[0]
    
   for element in arr:
      
        if element < min:
            min = element
      
        elif element > max:
            max = element
   return min, max



my_list = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
min_value, max_value = find_min_max(my_list)

print(f"Phần tử nhỏ nhất là: {min_value}")
print(f"Phần tử lớn nhất là: {max_value}")

def find_min_max_recursive(arr, start, end):
    if start == end:
        return arr[start], arr[start]
    elif end - start == 1:
        return (arr[start], arr[end]) if arr[start] < arr[end] else (arr[end], arr[start])
    mid = (start + end) // 2
    min_left, max_left = find_min_max_recursive(arr, start, mid)
    min_right, max_right = find_min_max_recursive(arr, mid + 1, end)
    
    min_result = min(min_left, min_right)
    max_result = max(max_left, max_right)
    
    return min_result, max_result

# Ví dụ sử dụng
my_list = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
min_value, max_value = find_min_max_recursive(my_list, 0, len(my_list) - 1)

print(f"Phần tử nhỏ nhất là: {min_value}")
print(f"Phần tử lớn nhất là: {max_value}")

