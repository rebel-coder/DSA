def binary_search(a_list, item):
    first = 0
    last = len(a_list) - 1
    while first <= last:
        i = (first + last) / 2

        if a_list[i] == item:
            return '{item} found at position {i}'.format(item=item, i=i)
        elif a_list[i] > item:
            last = i - 1
        elif a_list[i] < item:
            first = i + 1
        else:
            return 'Not found.'
