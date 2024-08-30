def busca_par(x):
    for i in range(1,int(x/2)):
        if (x-i)%3!=0 and x-i!=i:
            return i
    return -1

t = int(input())
trinca = []

while t>0:
    t-=1
    x = int(input())
    trinca = []
    for i in range(1,int(x/2)):
        if i%3!=0:
            complemento = x-i
            resposta = busca_par(complemento)
            if resposta!=(-1) and i!= resposta and i!= complemento-resposta:
                trinca.append(i)
                trinca.append(resposta)
                trinca.append(complemento-resposta)
        if len(trinca)>1:
            print("YES")
            print(trinca[0], trinca[1],trinca[2],sep=" ")
            break
    if len(trinca)<2:
        print("NO")
    
