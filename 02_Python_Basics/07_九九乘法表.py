for row in range(1, 10):
    for column in range(1, row + 1):
        print(f"{column}×{row}={column * row}", end="\t")
    print()
