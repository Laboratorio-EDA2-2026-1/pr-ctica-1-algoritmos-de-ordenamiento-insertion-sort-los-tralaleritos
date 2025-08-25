def InsertionSortMatriz(matriz, n):

    arr = [num for fila in matriz for num in fila]

    long = len(arr)
    for i in range(1,long):
        key = arr[i]
        j = i - 1
        while j>= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

    k = 0
    for i in range(n):
        for j in range(n):
            matriz[i][j] = arr[k]
            k += 1

    return f"La matriz ya ordenada:\n {matriz[0]}\n {matriz[1]}\n {matriz[2]}"

matriz = [
    [9,2,7],
    [4,6,1],
    [5,8,3]
]

print(InsertionSortMatriz(matriz, 3))

