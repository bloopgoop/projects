f = open("input.txt","r")
outstring = ""
lines = f.readlines()

for line in lines:
    line = line.replace("\n","")
    outstring += line


for small in range(len(outstring)):
    if (outstring[small-4].islower()) and (outstring[small-3]).isupper() and (outstring[small-2]).isupper() and (outstring[small-1]).isupper() and (outstring[small]).islower() \
    and (outstring[small+1]).isupper() and (outstring[small+2]).isupper() and (outstring[small+3]).isupper() and (outstring[small+4].islower()):
        print(outstring[small-3:small+4])

f.close()