import string

def print_rangoli(size):
    # your code goes here
    #width = (size*2 - 1)*2 -1 
    alphabet = string.ascii_lowercase
    
    lines = []
    for i in range(size):
        # Select the letters for the current row
        letters = alphabet[size-1:i:-1] + alphabet[i:size]
        row = "-".join(letters).center(4*size-3, "-")  # Formatting width
        lines.append(row)
    
    # Print the full rangoli
    print("\n".join(lines[::-1] + lines[1:]))

            

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)