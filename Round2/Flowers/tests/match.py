with open('out10_0.txt', 'rb') as f:
   o0 = f.read()
with open('out10.txt', 'rb') as f:
   o1 = f.read()

for i in range(min(len(o0), len(o1))):
   if o0[i] != o1[i]:
      print("hmmm")