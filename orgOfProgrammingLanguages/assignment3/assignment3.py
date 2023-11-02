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

input_code = 'i*i$'

# table parsing algorithm

S = ['$','P']
c=input_code[0]

while len(S):
    c=input_code[0]

    print(str((S[::-1]))+"\t"+str(input_code)+"\t",end="")
    X = S[-1]
    if X==c:
        S.pop()
        input_code=input_code[1:]
        
    elif X in terminals:
        print('error, terminal on stack')
        quit()
    elif parseTable[non_terminals.index(X)][terminals.index(c)]!=0:
        S.pop()

        # push symbols alpha on to the stack and repeat
        alpha = grammar[parseTable[non_terminals.index(X)][terminals.index(c)]-1][1:]
        print(" "+str(grammar[parseTable[non_terminals.index(X)][terminals.index(c)]-1]))
        

        alpha=alpha[::-1]
        for symbol in alpha:
            if symbol!='ε':
                S.append(symbol)
        
        # print("next is alpha")
        # print (alpha)
    elif parseTable[non_terminals.index(X)][terminals.index(c)]==0:
        print('error, no entry in parse table. C=',c,'X=',X,'S=',S,'input=',input_code)
        quit()
    
print()