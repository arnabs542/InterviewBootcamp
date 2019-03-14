"""
implement the standard quicksort algorithm
"""

def partition(l, low, high):
    pivot = l[high]

    i=low
    j=high

    """ what is the invariant we are maintaining
    it is:
        values < pivot are in range [low, i)
        values > pivot are in range (j, high]
    so the point where we stop partitioning is when i==j
    """
    while i < j:
        if l[i] < pivot:
            i += 1
        else:
            j -= 1
            l[i], l[j] = l[j], l[i]
        #print 'i: {}, j: {}'.format(i,j)
    l[j], l[high] = l[high], l[j]
    return j #pivot index

def quicksort(l, low, high):

    if (low >= high):
        return

    pivot = partition(l, low, high)
    #print 'low:{}, high: {}, pivotIndex:{}, list: {}'.format(low, high, pivot, l)
    quicksort(l, low, pivot-1)
    quicksort(l, pivot+1, high)



def main():
    import random
    l = random.sample(xrange(1000), 10)

    #print 'unsorted: {}'.format(l)
    quicksort(l, 0, len(l)-1)
    #print 'sorted: {}'.format(l)


if __name__ == "__main__":
    main()
