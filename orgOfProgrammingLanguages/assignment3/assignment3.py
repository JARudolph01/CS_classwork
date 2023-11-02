terminals=['i','+','*','(',')','$']
non_terminals=['P','E','D','T','S','F']
parseTable=[
    [1,0,0,1,0,0],
    [2,0,0,2,0,0],
    [0,3,0,0,4,4],
    [5,0,0,5,0,0],
    [0,7,6,0,7,7],
    [9,0,0,8,0,0]
]
grammar=[
    ['P','E'],
    ['E','T','D'],
    ['D','+','T','D'],
    ['D','ε'],
    ['T','F','S'],
    ['S','*','F','S'],
    ['S','ε'],
    ['F','(','E',')'],
    ['F','i']
]
inputCode = 'i*i$'

# table parsing algorithm
S = ['$','P']
c=inputCode[0]
while len(S):
    c=inputCode[0]

    print(str((S[::-1]))+"   "+str(inputCode)+"   ",end="")

    X = S[-1]
    if X==c:
        S.pop()
        inputCode=inputCode[1:]
    elif X in terminals:
        print('error, terminal on stack')
        quit()
    elif parseTable[non_terminals.index(X)][terminals.index(c)]!=0:
        S.pop()

        # get alpha
        alpha = grammar[parseTable[non_terminals.index(X)][terminals.index(c)]-1][1:]

        # print rule
        print(" "+str(grammar[parseTable[non_terminals.index(X)][terminals.index(c)]-1]))
        
        # push alpha in reverse order
        alpha=alpha[::-1]
        for symbol in alpha:
            if symbol!='ε':
                S.append(symbol)

    elif parseTable[non_terminals.index(X)][terminals.index(c)]==0:
        print('error, no entry in parse table.')
        quit()
    
print()