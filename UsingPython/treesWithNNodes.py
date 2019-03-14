



def count(n):
    if n <= 1:
        return 1

    total = 0
    for i in xrange(n):
        total +=  count(i) * count(n-i-1)
    return total




def main():
    import sys
    print count(int(sys.argv[1]))




if __name__ == "__main__":
    main()
