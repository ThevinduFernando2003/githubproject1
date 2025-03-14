def minion_game(string):
    # your code goes here
    kevin_mark = 0
    stuart_mark = 0
    vowels ='AEIOU'
    
    
    for i in range(len(string)):
        if(string[i] in vowels):
            kevin_mark += len(string) - i 
        else:
            stuart_mark += len(string) - i
    
    if(stuart_mark > kevin_mark):
        print("Stuart", stuart_mark)
    elif(stuart_mark == kevin_mark):
        print("Draw")
    else:
        print("Kevin", kevin_mark)

if __name__ == '__main__':
    s = input()
    minion_game(s)