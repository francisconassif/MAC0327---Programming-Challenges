t = int(input())
soma = 0
resposta = ((1+t)*t)/2
a = input()
vetor = a.split(sep=" ")
for elem in vetor:
    elem=int(elem)
    soma+=elem
x = resposta-soma
print(int(x))
