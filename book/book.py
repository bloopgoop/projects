txt = open("bomba.txt", 'r')

word_count = {}


for line in txt:
    new_line = ''
    for char in line:
        if char.isalpha():
            new_line += char.lower()
        else:
            new_line += ' '

    words = new_line.split()
    for word in words:
        word = word.lower()
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1


found = []

found_word = ''
for i in range(20):
    min = 0
    for i in word_count:
        if word_count[i] > min and i not in found:
            min = word_count[i]
            found_word = i
    found.append(found_word)

count = 1
for i in found:
    print(count, ':  ', i, ':', word_count[i])
    count += 1

txt.close()