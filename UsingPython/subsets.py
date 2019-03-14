"""
All subsets of a set
"""

def subsets(arr, index, res, pRes):
    print('index:{}, res: {}, pRes; {}\n'.format(index, res, pRes))
    if index == len(arr):
        res.append(pRes)
        return

    subsets(arr, index+1, res, pRes[:])
    pRes.extend([arr[index]])
    subsets(arr, index+1, res, pRes[:])
    pRes.pop()


def main():
    res = []
    pRes = []
    subsets([1,2], 0, res, pRes)
    print res


if __name__ == "__main__":
    main()
