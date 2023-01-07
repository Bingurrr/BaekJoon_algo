def solution(arr1, arr2) :
    arr1_row = len(arr1)
    arr1_col = len(arr1[0])
    arr2_row = len(arr2)
    arr2_col = len(arr2[0])
    if (arr1_row == arr2_row) & (arr1_col == arr2_col) :
      line = [[0 for j in range(arr1_col)] for i in range(arr1_row)]
      for i in range(arr1_row) :
        for j in range(arr1_col) :
          line[i][j] = arr1[i][j] + arr2[i][j]
      return line