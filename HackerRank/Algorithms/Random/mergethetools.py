def merge_the_tools(string, k):
    # your code goes here
    n = len(string) // k
    for i in range(0,len(string), k):
        t = string[i: i+k]
        unique_chars = "".join(dict.fromkeys(t))
        print(unique_chars)
    

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)