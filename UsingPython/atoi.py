
def atoi(strNum):
    num = 0
    for c in strNum:
        num = num * 10 + (ord(c) - ord('0'))
    return num


def main():
    assert(atoi('1234') == 1234)
    assert(atoi('2') == 2)



if __name__ == "__main__":
    main()
