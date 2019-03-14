
def isPalindrome(str):
    l = len(str)
    for i in xrange(l/2):
        if str[i] != str[l-i-1]:
            return False
    return True


def main():
    assert(isPalindrome('a'))
    assert(isPalindrome('abba'))
    assert(not isPalindrome('ac'))

if __name__ == "__main__":
    main()


